# コードレビュー報告書: 認証エンジンおよび TUI 境界

レビュー日: 2026-05-03

レビュー対象リビジョン: `81d3092`

本書は `~/helix-scratch/output.json` に記録されていたレビュー内容を基に、
現在のリポジトリに対してローカル確認を行い、技術文書として詳細化したものである。
対象は C 実装の認証エンジン、CLI 境界、永続化および監査ログ処理、
Go TUI からエンジンを呼び出すプロセス境界、および関連するテストである。

## 概要

総合リスクは高い。最も重要な問題は、認証情報の生成というセキュリティ上重要な処理が
`assert(...)` の副作用として実装されている点である。`NDEBUG` が定義されたビルドでは
`assert` の引数式は評価されないため、登録処理やパスワード変更処理が成功を返しても、
永続化される salt や password hash が生成または更新されない可能性がある。

次に重要な問題は、公開 CLI 境界で入力長および永続化形式に対する安全性が検証されていない点である。
外部から与えられた長い `login_id` により、CLI が正常終了扱いのドメイン結果を返した後でも、
監査ログが破損し、以後の `show-audit` や `show-metrics` が失敗する状態を作れる。

通常の Debug 前提のテストは通過しているが、production code と test code の双方が
C 標準の `assert` マクロに依存しているため、Release または `NDEBUG` 構成に対する保証としては不十分である。

## レビュー範囲

レビュー対象:

- `engine/src/core` にある認証状態遷移
- `engine/src/cli/command_runner.c` にある CLI command handling
- `engine/src/storage` にある user、session、audit の file-backed storage
- `tui/internal/engineclient` にある Go TUI から C engine への process boundary
- 上記の問題に関連する C および Go のテスト

対象外:

- Lean 仕様の証明完全性
- 新規修正の実装
- マルチユーザーホスト環境に対する網羅的 threat modeling

## 指摘事項

### 1. 認証情報生成が `assert(...)` に依存している

重大度: Critical

分類: Security / correctness

影響箇所:

- `engine/src/core/register.c`
- `engine/src/core/change_password.c`

登録処理では、salt 生成と password hash 生成が次のように実行されている。

```c
assert(auth_salt_generate(new_user.salt, sizeof(new_user.salt)) == AUTH_SALT_STATUS_OK);
assert(auth_hash_password(...) == AUTH_HASH_STATUS_OK);
```

パスワード変更処理にも同じ構造がある。

```c
assert(auth_salt_generate(user->salt, sizeof(user->salt)) == AUTH_SALT_STATUS_OK);
assert(auth_hash_password(...) == AUTH_HASH_STATUS_OK);
```

これは単なる診断用 assertion ではない。`auth_salt_generate` と `auth_hash_password` の呼び出し自体が、
認証情報を生成または更新する本体処理である。C 標準の `assert` は `NDEBUG` が定義されると
引数式を評価しないため、これらの関数呼び出しはコンパイル後のプログラムから消える。

想定される影響:

- `register` が success を返しながら、salt と password hash が空の user record を永続化する。
- `change-password` が success を返しながら、対象 user の認証情報を更新しない。
- 永続化された状態が storage loader の期待する invariant と矛盾し、以後の state load が失敗する。
- Debug build で確認された挙動と Release build の挙動がセキュリティ上意味のある形で乖離する。

ローカル確認結果:

- リポジトリの警告設定を維持した直接の `-DNDEBUG` build では、
  `assert(...)` 内でしか使われない値が unused になり、`-Werror` により build failure となった。
  具体的には `register.c` の `password_len` と `change_password.c` の `new_password` が該当する。
- 検証目的で unused warning の error 化のみを緩和したところ、
  `register` command は `{"ok":true,"result":"success",...}` を返したが、
  `users.tsv` には salt と hash が空の行が書き込まれた。
- その後の `login` は破損した state の load に失敗した。

推奨対応:

- `auth_salt_generate` と `auth_hash_password` を通常の statement として実行する。
- 各関数の戻り値を明示的に検査する。
- salt 生成または hash 生成が失敗した場合は runtime failure として扱う。
- `auth_register_result_t` に system error または capacity exceeded を表現する結果を追加するか、
  core/CLI 境界で安定した error path を定義する。
- CI に Release build または `NDEBUG` build の検証 job を追加する。

### 2. `auth_register` が容量と login ID 長を runtime validation していない

重大度: Critical

分類: Security / memory safety

影響箇所:

- `engine/src/core/register.c`

`auth_register` は、少なくとも次の 2 つの前提を runtime check ではなく assertion または caller discipline に依存している。

```c
assert(state->user_count < AUTH_MAX_USERS);
...
memcpy(new_user.login_id, login_id, login_id_len + 1u);
```

`new_user.login_id` は `AUTH_LOGIN_ID_MAX_LENGTH + 1` の固定長 buffer である。
一方、関数は caller から渡された string の長さを `strlen` で計算し、
その長さに terminator 分を加えた byte 数をそのまま `memcpy` している。
Debug build では user capacity について assertion があるが、`login_id_len` に対する runtime check は存在しない。

想定される影響:

- user store が満杯の状態で `assert` が無効化されていると、`state->users` の範囲外に書き込む可能性がある。
- overlong `login_id` により `new_user.login_id` の範囲外に書き込む可能性がある。
- core API は、caller がすべての precondition を正確に満たさない限り memory safe ではない。

推奨対応:

- `state`、`login_id`、`password`、login ID 長、password 長、user store capacity を通常の runtime check で検査する。
- 固定長 user store が満杯の場合に返す明示的な error result を定義する。
- 固定長 buffer に caller supplied string をコピーする前に、必ず destination size に収まることを検証する。
- `assert` は開発時の invariant check に限定し、外部入力に到達可能な条件の唯一の防御として使用しない。

### 3. CLI 入力検証が不完全である

重大度: High

分類: Correctness / storage integrity

影響箇所:

- `engine/src/cli/command_runner.c`

CLI は required option が存在するかだけを確認している。

```c
static bool cli_ensure_required(const char *value)
{
    return value != nullptr;
}
```

`register`、`login`、`change-password` の実行前に
`auth_validate_login_id` や `auth_validate_password` は呼ばれていない。
また、現在の TSV backed storage format で安全に round-trip できない tab や newline などの文字も拒否していない。

想定される影響:

- overlong login ID が core layer および storage layer に到達する。
- invalid value が audit record に書き込まれる。
- CLI が process exit code `0` で domain result を返したにもかかわらず、
  以後の `show-audit` や `show-metrics` が audit log の parse failure により失敗する。
- public contract は required option を説明しているが、受理可能な入力 domain を十分に定義していない。

ローカル確認結果:

通常の Debug build で、300 文字の unknown user ID を指定した `login` command は次の JSON を返した。

```json
{"ok":false,"result":"unknown_user","data":null,"error":{"message":"login failed"}}
```

process exit code は `0` だったが、生成された audit record は途中で切り詰められた。
続く `show-audit` command は次の JSON を返した。

```json
{"ok":false,"result":"system_error","data":null,"error":{"message":"failed to load audit log"}}
```

推奨対応:

- 外部から渡される login ID と password に対し、CLI boundary で validation layer を追加する。
- null、empty、maximum length の検査には `auth_validate_login_id` と `auth_validate_password` を再利用する。
- `users.tsv`、`session.txt`、`audit.log` で安全に表現できない delimiter や control character を拒否する。
- malformed input は `invalid_request` と usage-error exit code で返す。
- overlong login ID、overlong password、empty string、tab、newline、境界長の値に対する CLI integration test を追加する。

### 4. Audit append が `snprintf` の切り詰めを成功扱いしている

重大度: High

分類: Correctness / observability integrity

影響箇所:

- `engine/src/storage/file_audit_log.c`

Audit append は各 record を 256 byte の固定長 buffer に format している。

```c
if (snprintf(line,
             sizeof(line),
             "%s\t%s\t%s\t%s\n",
             timestamp,
             storage_audit_event_type_string(event_type),
             login_id,
             result) < 0) {
    return STORAGE_AUDIT_LOG_STATUS_IO_ERROR;
}
```

現在の実装は `snprintf` の戻り値が負の場合のみ error として扱う。
しかし `snprintf` は、戻り値が destination size 以上の場合に output が切り詰められたことを示す。
structured record を永続化する処理では、この条件も failure として扱う必要がある。

想定される影響:

- malformed input または overlong input により、partial audit line が生成される。
- write operation が success を返した後、後続の audit parser が失敗する。
- metrics は audit log から算出されるため、audit log 破損により metrics も利用不能になる。

推奨対応:

- `snprintf_result >= sizeof(line)` を検査し、該当する場合は error を返す。
- append-only record には dynamically sized formatting または structured escaping layer を導入する。
- 境界長の record が成功し、境界を超える record が partial line を残さず失敗することをテストで確認する。

### 5. 平文 password が process arguments 経由で渡されている

重大度: Medium

分類: Security / secret handling

影響箇所:

- `tui/internal/engineclient/client.go`
- `tui/internal/engineclient/command_exec.go`
- `docs/engine-cli-contract.md`

TUI は plaintext password を argv に含めて engine を起動している。

```go
executeRequest[EmptyData](c, "register", "--login-id", loginID, "--password", password)
executeRequest[EmptyData](c, "login", "--login-id", loginID, "--password", password)
executeRequest[EmptyData](c, "change-password", "--old-password", oldPassword, "--new-password", newPassword)
```

これは public CLI contract に記載された `--password`、`--old-password`、`--new-password` の仕様と一致している。

想定される影響:

- password が process inspection API から参照可能になる場合がある。
- shell history、wrapper log、crash telemetry、endpoint monitoring、command-line tracing に password が残る可能性がある。
- 実際のリスクは host configuration に依存するが、現在の contract は secret exposure を default integration path にしている。

推奨対応:

- secret transport を argv から外す。
- password input は stdin、inherited pipe、または short-lived file descriptor 経由にする。
- `--data-dir` や `--login-id` のような非 secret 値のみ argv に残す。
- `docs/engine-cli-contract.md`、`docs-jp/エンジン用CLI.md`、TUI client tests を同時に更新し、
  contract と implementation の整合性を維持する。

### 6. C tests が C 標準 `assert` マクロを test assertion として使用している

重大度: Medium

分類: Testability / release confidence

影響箇所:

- `engine/tests/unit/*.c`
- `engine/tests/integration/*.c`

C test suite は `assert(...)` を広範に使用している。
これは test binary が `NDEBUG` 付きで build されないことが保証されている場合にのみ安全な前提である。
本リポジトリでは、同じ `assert` マクロへの依存が production bug の原因にもなっている。

想定される影響:

- test が `NDEBUG` 付きで compile されると、多くの check が no-op になる。
- Release mode verification job を追加しても、実際には期待挙動を検査しないまま pass する可能性がある。
- Debug build と Release build の挙動差に対する test strategy が不十分である。

推奨対応:

- test の `assert(...)` を、常に有効な小さな test helper に置き換える。
  例: `TEST_CHECK(condition)` が file/line を出力し、失敗時に non-zero exit するようにする。
- `NDEBUG` または CMake Release configuration で engine tests を build/run する CI job を追加する。
- Release mode で credential generation が実行されることを確認する regression test を追加する。

## 実施した検証

成功した command:

```powershell
.\scripts\run-engine-tests.ps1
```

結果: C engine tests は 17 件中 17 件成功。

```powershell
go test ./...
```

実行場所: `tui`

結果: Go packages はすべて成功、または test file なし。

追加検証:

- CMake Release configuration を試行したが、local environment では compiler ABI detection 中に timeout した。
- `mingw32-make` による Makefile の `NDEBUG` path も試行したが、
  Windows environment で Makefile が要求する Unix `touch` command が見つからず build marker rule で失敗した。
- 直接の `clang -DNDEBUG` verification build により、上記の credential generation 問題を確認した。
- 通常の Debug build により、長い login ID による audit log corruption scenario を再現した。

検証中に作成した一時 artifact は削除済みである。

## 推奨修正順序

1. production code の `assert(...)` 式から副作用を排除し、salt/hash 生成に明示的な runtime error handling を追加する。
2. `auth_register` に login ID 長と user store capacity の runtime check を追加する。
3. core auth function の呼び出しや audit record 書き込みの前に、CLI input validation を適用する。
4. audit append で `snprintf` truncation を failure として扱う。
5. malformed CLI input と release-style build を含む regression test を追加する。
6. TUI と public CLI contract で、password を process arguments に載せない secret transport へ移行する。
7. C tests の `assert(...)` 使用を、常に有効な test assertion helper に置き換える。

## 残存リスク

少なくとも最初の 4 項目が修正されるまでは、本リポジトリを authentication use に対して
release-ready と見なすべきではない。現在の実装は通常の test suite を通過しながら、
`NDEBUG` build で security-critical behavior が失われる可能性があり、
さらに外部から渡される CLI input により observability storage を破損させることができる。

## 2026-05-12 に適用した修正

上記の指摘事項に対する修正内容は
[`code-review-2026-05-03-remediation-ja.md`](./code-review-2026-05-03-remediation-ja.md)
に記録した。

適用した修正の要約:

- production code の `assert(...)` 式から、認証情報生成の副作用を除去した。
- `auth_register` に null input、invalid login ID / password length、
  fixed-capacity state の満杯状態に対する runtime guard を追加した。
- core auth function と audit write の前に CLI validation を追加した。
- audit append で `snprintf` truncation を拒否するようにした。
- password transport を argv から stdin に移し、`--password-stdin`、
  `--old-password-stdin`、`--new-password-stdin` を使う契約に変更した。
- C tests の `assert(...)` 使用を、常に有効な `TEST_CHECK(...)` に置き換えた。
- malformed CLI input、audit truncation、Release behavior、TUI secret transport
  に対する regression test を追加した。
- Lean の result-code refinement notes、英日 CLI 契約文書、CI の Release-mode
  engine verification を更新した。

検証結果:

- `.\scripts\run-engine-tests.ps1`: C engine tests は 17 件中 17 件成功。
- `tui` での `go test ./...`: 成功。
- CMake Release build と `ctest`: C engine tests は 17 件中 17 件成功。
- `.\scripts\run-spec-check.ps1`: Lean build は成功。
- `git diff --check`: Windows の line-ending warning のみで成功。

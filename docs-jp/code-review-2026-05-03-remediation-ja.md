# コードレビュー修正記録: 2026-05-12

この文書は
[`../docs/code-review-2026-05-03-en.md`](../docs/code-review-2026-05-03-en.md)
に対するリポジトリ修正内容を記録する。

## 対象範囲

今回の修正対象は、認証エンジン、CLI 境界、audit storage、Go TUI engine client、
Lean の result-code refinement notes、CI 検証、C/Go regression test suite である。

## 適用した修正

1. 認証情報生成が `assert(...)` に依存しないようにした。
   - `engine/src/core/register.c`
   - `engine/src/core/change_password.c`
   - salt generation と password hashing を通常の statement として実行するようにした。
   - 戻り値 status を明示的に検査するようにした。
   - runtime failure は debug-only assertion behavior に依存せず、`system_error` を返す。

2. `auth_register` に runtime safety check を追加した。
   - `engine/include/auth/result.h`
   - `engine/include/auth/register.h`
   - `engine/src/core/register.c`
   - core register path では、fixed buffer にコピーする前に null argument、login ID length、
     password length、fixed user-store capacity を検査する。
   - implementation-bound failure を表現するために
     `AUTH_REGISTER_RESULT_SYSTEM_ERROR` を追加した。

3. core state transition および audit write の前に CLI input validation を追加した。
   - `engine/src/cli/command_runner.c`
   - login ID と password について null、empty、maximum length、control character を検査する。
   - TSV-backed storage で安全に round-trip できない login ID を拒否する。
   - malformed input は `invalid_request` と usage-error exit code を返す。

4. audit append で `snprintf` truncation を failure として扱うようにした。
   - `engine/src/storage/file_audit_log.c`
   - formatted audit line の必要長が destination buffer 以上の場合は、
     partial structured record を書かずに拒否する。

5. password transport を process arguments から外した。
   - `engine/include/cli/command_runner.h`
   - `engine/src/cli/command_runner.c`
   - `tui/internal/engineclient/client.go`
   - `tui/internal/engineclient/command_exec.go`
   - public CLI は `--password-stdin`、`--old-password-stdin`、
     `--new-password-stdin` を使う。
   - 以前の plaintext argv flag は `invalid_request` として拒否する。
   - Go TUI は password value を stdin で渡し、argv には非 secret 値だけを残す。

6. C tests が C 標準 `assert` マクロに依存しないようにした。
   - `engine/tests/support/test_support.h`
   - `engine/tests/support/cli_test_support.h`
   - `engine/tests/unit/*.c`
   - `engine/tests/integration/*.c`
   - test check は `TEST_CHECK(...)` を使う。これは Release または `NDEBUG`
     build でも有効なままである。

7. レビューで指摘された failure mode に対する regression coverage を追加した。
   - core register の null / invalid / full-state handling。
   - CLI の overlong login ID、overlong password、empty password、tab / newline rejection、
     boundary-length accepted value。
   - audit append truncation rejection。
   - TUI secret transport が argv ではなく stdin を使うこと。
   - Release-mode engine verification。

8. 新しい境界に合わせて specification と contract document を更新した。
   - `spec/VerifiableAuth/Types.lean`
   - `spec/VerifiableAuth/RefinementNotes.lean`
   - `docs/engine-cli-contract.md`
   - `docs/system-specification.md`
   - `docs/spec-engine-comparison-table.md`
   - `docs-jp/エンジン用CLI.md`
   - `docs-jp/仕様書.md`
   - `docs-jp/Lean仕様とC言語エンジンの対照表.md`

9. CI に Release-mode engine verification を追加した。
   - `.github/workflows/engine.yml`
   - engine workflow は通常の engine test path の後に、CMake Release configuration で
     C test suite を build/run する。

## 検証

次の check がローカルで成功した。

```powershell
.\scripts\run-engine-tests.ps1
```

結果: C engine tests は 17 件中 17 件成功。

```powershell
go test ./...
```

実行場所: `tui`

結果: Go packages はすべて成功、または test file なし。

```powershell
cmake -S .\engine -B .\engine\.build-release -DCMAKE_BUILD_TYPE=Release
cmake --build .\engine\.build-release
ctest --test-dir .\engine\.build-release --output-on-failure
```

結果: Release mode の C engine tests は 17 件中 17 件成功。

```powershell
.\scripts\run-spec-check.ps1
```

結果: configured toolchain が利用可能になった後、Lean build は成功。

```powershell
git diff --check
```

結果: Git on Windows の line-ending warning のみで成功。

## Working Tree Notes

今回の remediation は、実装作業前から存在していた README edits、`.scratch/`、
および untracked review Markdown files の ownership は主張しない。

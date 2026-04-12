# Lean 仕様と C エンジンの対照表

この文書は [`../docs/spec-engine-comparison-table.md`](../docs/spec-engine-comparison-table.md) の日本語版です。

この文書は、`spec/` にある形式仕様と `engine/` にある C 実装とのあいだの
主要なトレーサビリティ資料です。

目的は、単に類似した名前のファイルを並べることだけでなく、以下が説得力を持つことを
レビュー可能な形で示すことにあります。

- Lean モデルが意図された挙動を正しく明示していること
- C エンジンが運用境界において同じ挙動を実装していること
- 既知の不一致は、暗黙的に乖離しているのでなく、意図的なリファインであること
- 残る妥協点が可視化され、正当化可能であること

散文レベルでのシステム契約は [`仕様書.md`](./仕様書.md)、
短い状況要約は [`仕様・Lean・C言語の整合性検討.md`](./仕様・Lean・C言語の整合性検討.md) を参照してください。

## この文書の読み方

以下の表は 3 列で構成します。

| Lean 仕様 | C 実装 | 対応関係の根拠 / 実装上の妥協点 |
| --- | --- | --- |

これは、厳密な 2 列のクロスリファレンスより意図的に詳しくしてあります。
この追加説明こそが本プロジェクトにおいて非常に重要です。形式仕様が説得力ある証拠になるためには、読者が
「モデルが実行可能な実装にどうリファインされているのか、そして実装がどこでモデルよりも具体的にならざるを
得ないのか」を把握できることが必要だからです。

比較は次の観点で整理しています。

1. 中核データ定義と状態の形
2. 純粋な遷移意味論
3. 不変条件と保存の議論
4. CLI および observability の refinement
5. 明示的な実装上の妥協点

## 状態とデータモデル

| Lean 仕様 | C 実装 | 対応関係の根拠 / 実装上の妥協点 |
| --- | --- | --- |
| `spec/VerifiableAuth/Types.lean` における `LoginId := String` と `Password := String` | `engine/include/auth/types.h`、`engine/include/auth/register.h`、`engine/include/auth/login.h`、`engine/include/auth/change_password.h` における `char login_id[...]` と `const char *password` | 両層とも login identifier と password を文字列値としてモデル化しています。C 層は低レベル実装として境界付き storage が必要なため、固定最大長 (`AUTH_LOGIN_ID_MAX_LENGTH`, `AUTH_PASSWORD_MAX_LENGTH`) を追加しています。これは意味変更ではなく意図的な refinement です。 |
| `spec/VerifiableAuth/Types.lean` における `lockoutThreshold : Nat := 3` | `engine/include/auth/types.h` の `AUTH_LOCKOUT_THRESHOLD 3u` | 閾値は両層で同一です。C 実装では、このコードベースで一般的な定数機構として macro を使っています。 |
| `spec/VerifiableAuth/Types.lean` における `inductive LockState | active | locked` | `engine/include/auth/types.h` の `auth_lock_state_t` | 直接的な構造対応です。Lean の sum type が、同じ 2 状態を持つ C enum になっています。 |
| `spec/VerifiableAuth/Types.lean` における `Salt` 構造体、`Salt.initial`, `Salt.rotate`, `Salt.material` | `engine/include/crypto/salt_adapter.h` および `engine/src/crypto/salt_adapter.c` における `char salt[AUTH_SALT_ENCODED_LENGTH]` と `auth_salt_generate(...)` | ここには意図的な抽象ギャップがあります。Lean は、状態遷移の証明が暗号や RNG の詳細に依存しないよう salt を記号的にモデル化します。C エンジンは実際の乱数と直列化可能な表現を必要とするため、16 バイトのランダム salt を小文字 hex で保持します。両層で保存される意味論的要件は「ユーザーごとに fresh な salt」「パスワード変更時に新しい salt」なのであり、salt の内部構成法そのものではありません。 |
| `spec/VerifiableAuth/Types.lean` における `PasswordHash` 構造体と `derivePasswordHash` / `verifyPassword` | `engine/include/crypto/hash_adapter.h` および `engine/src/crypto/hash_adapter.c` における `char password_hash[AUTH_HASH_ENCODED_LENGTH]`, `auth_hash_password(...)`, `auth_hash_verify_password(...)` | ここも意図的な refinement 境界です。Lean は `password` と `salt.material` 上の記号的・決定的 digest を使い、議論の焦点を暗号工学ではなく遷移意味論に置きます。C エンジンは平文パスワードを保存しないという prose requirement を満たすため、実際の `PBKDF2-HMAC-SHA256` と iteration count (`100000`) を使います。保持される性質は `password_hash = hash(password, salt)` であり、記号モデル内部の digest 実装ではありません。 |
| `spec/VerifiableAuth/Types.lean` の `User` 構造体 | `engine/include/auth/types.h` の `auth_user_t` | `loginId/login_id`, `salt`, `passwordHash/password_hash`, `failedAttempts/failed_attempts`, `lockState/lock_state` に直接対応があります。C 表現は、具体的な文字列 storage と整数幅を追加しています。 |
| `spec/VerifiableAuth/Types.lean` における `users : List User` と `authenticated : Option LoginId` を持つ `AuthState` | `engine/include/auth/state.h` における `users[AUTH_MAX_USERS]`, `user_count`, `authenticated`, `authenticated_login_id` を持つ `auth_state_t` | 意味論的な形は同じです。ユーザー集合と、単一の optional session です。主な妥協点は、Lean が無界 `List` を使うのに対して、C は固定長 array と `user_count` を使うことです。これは engine を簡潔かつ allocation-free に保つための実装上の選択です。容量上限は supported range 内の実装境界であって、形式挙動の意味そのものではありません。 |
| `spec/VerifiableAuth/Types.lean` の `Outcome α` | `engine/include/auth/result.h` の operation-specific result enum と `engine/src/core/*.c` の in-place mutation | Lean は post-state と result code をひとつの値として返します。C は `auth_state_t *` を破壊的に更新し、result enum だけを返します。これは純粋状態機械モデルから命令的コードへの自然な翻訳です。 |
| `spec/VerifiableAuth/Types.lean` における `AuditEventType`, `AuditEvent`, `Metrics` | `engine/include/storage/audit_log.h` における `storage_audit_event_type_t`, `storage_audit_event_t`, `storage_metrics_t` | observability model は構造的に整合しています。C 層は永続化レコードが有界直列化 field を必要とするため、timestamp と string buffer 長を具体化しています。 |

## 状態ヘルパーと構造的定義

| Lean 仕様 | C 実装 | 対応関係の根拠 / 実装上の妥協点 |
| --- | --- | --- |
| `spec/VerifiableAuth/StateModel.lean` の `User.passwordMatches` | `engine/src/core/login.c` と `engine/src/core/change_password.c` における `auth_hash_verify_password(...)` 呼び出し | Lean は password check を user record 上の述語として表現します。C エンジンは、入力平文と永続化された salt から hash を再計算することでその述語を実現します。 |
| `spec/VerifiableAuth/StateModel.lean` の `User.noteFailedLogin` | `engine/src/core/login.c` の wrong-password branch | 実装される状態更新は同一です。`failed_attempts` を増やし、threshold 到達時に lock し、それ以外は active のままです。Lean は reusable な pure helper として、C は inline field update として表現します。 |
| `spec/VerifiableAuth/StateModel.lean` の `User.clearFailedAttempts` | `engine/src/core/login.c` の success branch | 現在の engine 実装は helper 関数を切らずに直接 counter を 0 にします。差はスタイルのみで、意味論差ではありません。 |
| `spec/VerifiableAuth/StateModel.lean` の `User.changePassword` | `engine/src/core/change_password.c` の success branch | 両層とも credential material を置換し、lock 関連 state を reset します。C エンジンは fresh salt 生成、hash 導出、失敗回数クリア、`ACTIVE` への復帰を命令的に実装します。 |
| `spec/VerifiableAuth/StateModel.lean` の `mkRegisteredUser` | `engine/src/core/register.c` の new user construction | どちらも zero failed attempts と導出済み credential material を持つ fresh active user を構築します。差は、記号的 crypto material か具体 crypto material かだけです。 |
| `spec/VerifiableAuth/StateModel.lean` の `AuthState.lookupUser?`, `containsUser`, `insertUser`, `replaceUser`, `clearSession`, `setAuthenticated` | `engine/include/auth/state.h` と `engine/src/core/state.c` における `auth_state_find_user`, `auth_state_find_user_mut`, `auth_state_clear_session`, `auth_state_set_authenticated_user` | これらは直接的な operational counterpart です。主な妥協点は、Lean が list-level helper を使うのに対し、C が fixed array 上の線形探索を使うことです。仕様は探索複雑度ではなく挙動を制約しているので、これは許容されます。 |
| `spec/VerifiableAuth/StateModel.lean` の `User.CredentialsBound` と `AuthState.CredentialsBound` | `engine/src/storage/file_user_store.c` における persisted-record validation と、`auth_register(...)` / `auth_change_password(...)` の間接的 enforcement | C 側に `CredentialsBound` という名前の直接 predicate はありません。しかし engine は同じ不変条件を operational に保っています。salt / hash は専用 adapter 経由でのみ生成・再生成され、永続化レコードは runtime state へ戻る前に検証されます。Lean が宣言的に表す不変条件を、C は手続き的に強制している例です。 |

## Well-Formedness とグローバル不変条件

| Lean 仕様 | C 実装 | 対応関係の根拠 / 実装上の妥協点 |
| --- | --- | --- |
| `spec/VerifiableAuth/WellFormed.lean` の `UniqueLoginIds` | `engine/src/core/register.c` の duplicate prevention と `engine/src/storage/file_user_store.c` の duplicate rejection | この不変条件は mutation 時にも persistence load 時にも強制されます。Lean は全状態上の性質として述べ、C は duplicate の生成を防ぎ、違反 persisted state を拒否します。 |
| `spec/VerifiableAuth/WellFormed.lean` の `User.WellFormed : user.lockState = .locked ↔ lockoutThreshold <= user.failedAttempts` | `engine/src/core/login.c` の threshold update と `engine/src/storage/file_user_store.c` の load-time validation | engine は生成 state に対して forward direction を直接強制し、load 時に key consistency を確認します。Lean では完全な同値が theorem として現れ、engine では construction logic と parse-time rejection に分散します。 |
| `spec/VerifiableAuth/WellFormed.lean` の `AuthState.SessionConsistent` | `engine/src/storage/file_session_store.c` の session-file validation と `auth_state_set_authenticated_user(...)` | C エンジンは、deserialize された authenticated login ID が必ず既存 user と対応することを保証し、そうでなければ parse error にします。これは Lean の existential session consistency predicate に対する具体的 operational equivalent です。 |
| `spec/VerifiableAuth/WellFormed.lean` の `AuthState.WellFormed` | `engine/src/core/*.c`, `engine/src/storage/file_user_store.c`, `engine/src/storage/file_session_store.c` にまたがる enforcement | Lean は uniqueness, user well-formedness, session consistency をひとつの conjunction として述べられます。engine は内部でそれを証明しないため、新規生成 state では construction で守り、on-disk state では invalid input を拒否することで維持します。 |
| `spec/VerifiableAuth/GlobalInvariants.lean` の `ConstructionInvariants`, `I02_UniqueLoginIds`, `I05_LockStateTracksThreshold`, `I11_SessionIsOptionalLoginId`, `I13_WellFormed`, `CoreInvariants` | `engine/include/auth/types.h`, `engine/include/auth/state.h`, core transition, storage loader, `engine/tests` | これは単一関数対応ではなく cross-cutting correspondence です。Lean は不変条件を centralize し、C は type 定義、mutation code、deserialize check、test coverage に分散して強制します。妥協は構造上のもので、意味論上のものではありません。 |
| `spec/VerifiableAuth/GlobalInvariants.lean` の `register_preserves_construction_invariants`, `login_preserves_construction_invariants`, `changePassword_preserves_construction_invariants`, `logout_preserves_construction_invariants` | `engine/tests/unit/test_register.c`, `engine/tests/unit/test_login.c`, `engine/tests/unit/test_change_password.c`, `engine/tests/unit/test_logout.c`, さらに `engine/tests/integration` の storage parse test | Lean は preservation を抽象的に証明します。C エンジンは focused test と、合法的 state mutation を対応コード経路に制限することによって同じ性質を経験的に示します。ここは proof-to-implementation の最重要妥協点の一つです。C は proof term を持てないため、証拠は「construction discipline + validation + tests」になります。 |
| `spec/VerifiableAuth/GlobalInvariants.lean` の `logout_does_not_modify_users` | `engine/src/core/logout.c` と `engine/tests/unit/test_logout.c` | ほぼ 1 行対応です。engine は session field だけをクリアし、user array を変更しません。 |
| `spec/VerifiableAuth/GlobalInvariants.lean` の `changePassword_success_clears_lock` | `engine/src/core/change_password.c` の `user->failed_attempts = 0u; user->lock_state = AUTH_LOCK_STATE_ACTIVE;` | 直接的な挙動対応です。 |

## 操作意味論

### Register

| Lean 仕様 | C 実装 | 対応関係の根拠 / 実装上の妥協点 |
| --- | --- | --- |
| `spec/VerifiableAuth/RegisterSpec.lean` の `register` 定義 | `engine/src/core/register.c` の `auth_register(...)` | 同じ 2 分岐が存在します。duplicate は state unchanged、そうでなければ fresh user が append されます。 |
| duplicate branch が `{ state := state, result := .duplicate }` を返す | `engine/src/core/register.c` の early duplicate return | 直接整合です。現在の命令的実装では、mutation 前に return します。 |
| success branch が `mkRegisteredUser` を insert する | `engine/src/core/register.c` の new-user creation と append | engine は同じ論理的仕事を行いますが、salt/hash generation を具体化しなければなりません。 |
| `spec/VerifiableAuth/RegisterSpec.lean` の `register_preserves_session` | `engine/src/core/register.c` は session field に触れず、CLI は `engine/src/cli/command_runner.c` で modified user store だけを save する | Lean は session preservation を直接証明します。C は、`auth_register(...)` に session-field write が存在しないことでそれを守ります。 |
| `spec/VerifiableAuth/RegisterSpec.lean` の `register_success_initializes_active_user` | `engine/src/core/register.c` の `new_user.failed_attempts = 0u; new_user.lock_state = AUTH_LOCK_STATE_ACTIVE;` | 直接整合です。 |

### Login

| Lean 仕様 | C 実装 | 対応関係の根拠 / 実装上の妥協点 |
| --- | --- | --- |
| `spec/VerifiableAuth/LoginSpec.lean` の `login` 定義 | `engine/src/core/login.c` の `auth_login(...)` | `already_authenticated`, `unknown_user`, `locked_out`, `wrong_password`, `success` について branch-for-branch 対応があります。 |
| `state.authenticated = some _ -> alreadyAuthenticated` | `engine/src/core/login.c` の `if (state->authenticated) return AUTH_LOGIN_RESULT_ALREADY_AUTHENTICATED;` | 直接整合です。engine は「同一ユーザーの再ログイン」と「別ユーザーでの再ログイン」をどちらも `already_authenticated` と扱い、prose spec の要求どおりです。 |
| unknown-user branch は state unchanged | `engine/src/core/login.c` の `user == nullptr -> AUTH_LOGIN_RESULT_UNKNOWN_USER` | 直接整合です。 |
| locked-user branch は `.lockedOut` を返し、state unchanged | `engine/src/core/login.c` の `user->lock_state == AUTH_LOCK_STATE_LOCKED` branch | 直接整合です。 |
| wrong-password branch は `noteFailedLogin` を使い、`.wrongPassword` または `.lockedOut` を返す | `engine/src/core/login.c` の wrong-password branch | 直接整合です。C は increment と threshold check を helper ではなく inline で行います。 |
| success branch は failure を clear し authenticated session を設定する | `engine/src/core/login.c` の success branch と `engine/src/core/state.c` の `auth_state_set_authenticated_user(...)` | 直接整合です。 |
| `spec/VerifiableAuth/LoginSpec.lean` の `login_already_authenticated_is_noop` | `engine/src/core/login.c` の early `authenticated` return と `engine/src/storage/file_audit_log.c` の persisted-metrics exclusion | state 部分は直接対応です。observability refinement はさらに、event を `LoginFailure` として記録しつつ failure metric を増やさないという仕様上の微妙な区別まで保持します。 |
| `spec/VerifiableAuth/LoginSpec.lean` の `login_unknown_user_keeps_state` | `engine/src/core/login.c` の unknown-user branch | 直接整合です。 |
| `spec/VerifiableAuth/LoginSpec.lean` の `login_success_sets_authenticated` | `engine/src/core/state.c` の `auth_state_set_authenticated_user(...)` と `engine/tests/unit/test_login.c` | Lean は postcondition を証明し、engine は state write を直接行い、test suite が挙動を確認します。 |

### Change Password

| Lean 仕様 | C 実装 | 対応関係の根拠 / 実装上の妥協点 |
| --- | --- | --- |
| `spec/VerifiableAuth/ChangePasswordSpec.lean` の `changePassword` 定義 | `engine/src/core/change_password.c` の `auth_change_password(...)` | `unauthorized`, `system_error`, `wrong_password`, `success` について branch-for-branch 対応があります。 |
| unauthenticated branch は `.unauthorized` と state unchanged を返す | `engine/src/core/change_password.c` の `if (!state->authenticated)` | 直接整合です。 |
| authenticated なのに user がいない場合 `.systemError` | `engine/src/core/change_password.c` の `user == nullptr` branch | 直接整合です。 |
| wrong old password は state unchanged | `engine/src/core/change_password.c` の `auth_hash_verify_password(...) == false` branch | 直接整合です。 |
| success branch は `user.changePassword newPassword` を使う | `engine/src/core/change_password.c` の success branch | 同じ抽象効果を実装していますが、ここでは実際の random salt と real password derivation を使います。 |
| `spec/VerifiableAuth/ChangePasswordSpec.lean` の `changePassword_preserves_session` | `auth_change_password(...)` は `auth_state_clear_session(...)` を呼ばず、`authenticated_login_id` も書き換えない | 直接整合です。 |
| `spec/VerifiableAuth/ChangePasswordSpec.lean` の `user_changePassword_rotates_salt` | `engine/src/core/change_password.c` の `auth_salt_generate(...)` 呼び出し | これは意味的には整合しつつ、構造的には異なる refinement です。Lean は symbolic salt epoch を increment して rotation を表します。engine は旧 salt を決定的に rotate せず、fresh random salt を生成します。これは security-oriented な強化であり、保持される性質は「以前と異なる新しい credential material」であって「old salt に epoch + 1 を適用したもの」ではありません。 |
| `spec/VerifiableAuth/ChangePasswordSpec.lean` の `user_changePassword_clears_failures` | `engine/src/core/change_password.c` の `user->failed_attempts = 0u; user->lock_state = AUTH_LOCK_STATE_ACTIVE;` | 直接整合です。 |

### Logout

| Lean 仕様 | C 実装 | 対応関係の根拠 / 実装上の妥協点 |
| --- | --- | --- |
| `spec/VerifiableAuth/LogoutSpec.lean` の `logout` 定義 | `engine/src/core/logout.c` の `auth_logout(...)` | 直接整合です。唯一の効果は session clearing、唯一の結果は success です。 |
| `spec/VerifiableAuth/LogoutSpec.lean` の `logout_preserves_users` | `engine/src/core/state.c` の `auth_state_clear_session(...)` と `engine/src/core/logout.c` に user write がないこと | 直接整合です。 |
| `spec/VerifiableAuth/LogoutSpec.lean` の `logout_clears_session` | `engine/src/core/state.c` における `state->authenticated = false` と `authenticated_login_id` の clear | 直接整合です。 |

## 結果コードと CLI Refinement

| Lean 仕様 | C 実装 | 対応関係の根拠 / 実装上の妥協点 |
| --- | --- | --- |
| `spec/VerifiableAuth/Types.lean` の `RegisterResult`, `LoginResult`, `ChangePasswordResult`, `LogoutResult` | `engine/include/auth/result.h` の `auth_register_result_t`, `auth_login_result_t`, `auth_change_password_result_t`, `auth_logout_result_t` | これが result space の中核的整合です。 |
| `spec/VerifiableAuth/RefinementNotes.lean` の `*.cliCode` | `engine/src/cli/command_runner.c` の `cli_register_result_string(...)`, `cli_login_result_string(...)`, `cli_change_password_result_string(...)` | string code は CLI boundary で意図的に固定されています。TUI や将来の tooling は C enum ではなくこの string code に依存するため、ここは最重要 refinement point の一つです。 |
| `spec/VerifiableAuth/RefinementNotes.lean` の `*.isOk` | `engine/src/cli/command_runner.c` で `cli_json_write_*` helper へ渡される `ok` boolean | 直接的な挙動整合です。engine は domain-level failure と runtime failure の区別を保持します。 |
| `docs/system-specification.md` における `ok`, `result`, `data`, `error` を含む CLI contract requirement | `engine/src/cli/json_output.c` の `cli_json_write_response_begin(...)`, `cli_json_write_response_end(...)`, `cli_json_write_null_response(...)` | Lean は JSON syntax そのものをモデル化しません。散文仕様と refinement note が、pure state machine と concrete engine contract の橋渡しをしています。JSON は core proof の本質ではなく implementation boundary に属するため、この分離は妥当です。 |
| `register`, `login`, `change-password`, `logout`, `show-audit`, `show-metrics` という documented command set | `engine/src/cli/command_runner.c` の dispatch logic | pure Lean state machine に存在するのは 4 つの auth transition だけです。`show-audit` と `show-metrics` は observability data 上の refinement-level read-only command なので、純粋遷移モデルの外側に置かれます。 |

## Observability と Metrics の Refinement

| Lean 仕様 | C 実装 | 対応関係の根拠 / 実装上の妥協点 |
| --- | --- | --- |
| `spec/VerifiableAuth/Types.lean` と `spec/VerifiableAuth/RefinementNotes.lean` の `AuditEventType`, `AuditEvent`, `Metrics`, `loginAuditEventType`, `countsAsLoginFailure`, `Metrics.record`, `computeMetrics` | `engine/include/storage/audit_log.h` と `engine/src/storage/file_audit_log.c` の `storage_audit_event_type_t`, `storage_audit_event_t`, `storage_metrics_t`, `storage_audit_log_counts_as_login_failure(...)`, `storage_audit_log_compute_metrics(...)` | 強い refinement correspondence です。engine は persisted event から、Lean refinement note が symbolic event から計算するのと同じ導出 counter を計算します。 |
| `spec/VerifiableAuth/RefinementNotes.lean` の `loginAuditEventType` | `engine/src/cli/command_runner.c` の `cli_login_audit_event_type(...)` | 直接的な挙動整合です。engine は「すでに locked な user」と「今回の試行で新たに lockout になった user」を Lean refinement note と同じように区別します。 |
| `spec/VerifiableAuth/RefinementNotes.lean` の `alreadyAuthenticated_does_not_count_as_login_failure` | `engine/src/storage/file_audit_log.c` の `storage_audit_log_counts_as_login_failure(...)` | 直接整合であり、特に重要です。audit traceability と metric counting の微妙な差を engine が保持していることを示します。 |
| Lean で symbolic event sequence を fold して metrics を計算すること | `engine/src/storage/file_audit_log.c` の audit-log persistence と `engine/src/cli/command_runner.c` の `show-metrics` path | 実装は on-disk artifact を必要とするため、具体的な serialization と timestamp を追加します。それでも semantic event category と counting rule は整合したままです。 |
| Lean における `AuditEvent` は record field として timestamp を持つが shape 制約はない | `engine/src/storage/file_audit_log.c` における append 時の `timestamp` 生成 | これは Lean 側で意図的に抽象化されている implementation detail です。形式モデルは timestamp format を必要とせず、engine は永続化のためにそれを選ばなければなりません。 |

## 永続化境界と Runtime Validation

| Lean 仕様 | C 実装 | 対応関係の根拠 / 実装上の妥協点 |
| --- | --- | --- |
| Lean state machine は入力として合法な `AuthState` を仮定する | `engine/src/storage/file_user_store.c` と `engine/src/storage/file_session_store.c` の `storage_user_store_load(...)`, `storage_session_store_load(...)` は persisted state を runtime state に変換する前に検証する | これは implementation-only obligation の中でも最重要の一つです。形式モデルは通常 well-formed state から始まります。実エンジンは破損ファイルから自分を守らなければならないため、malformed persistence を parse/runtime failure として扱い、不正 state を構築しません。 |
| Lean における `AuthState.WellFormed` と `SessionConsistent` | `engine/src/storage/file_session_store.c` における `session.txt` が `users.tsv` に存在しない user を指す場合の parse error | file-backed runtime state に対する session consistency の直接 refinement です。 |
| Lean における `UniqueLoginIds` と lock-state threshold consistency | `engine/src/storage/file_user_store.c` の duplicate check と record-shape validation | loader は、Lean なら単に「well formed ではない」と分類する persisted state を拒否します。 |
| pure Lean operation spec に storage model がないこと | `engine/src/storage/*.c` における `users.tsv`, `session.txt`, `audit.log` | これは意図的なモデリング省略です。プロジェクトは storage format を auth state machine の本質ではなく、その下位にある implementation detail として扱います。proof target が byte-level encoding ではなく auth state machine である限り、妥当な妥協です。 |

## 補助証拠としてのテスト

| Lean 仕様 | C 実装 | 対応関係の根拠 / 実装上の妥協点 |
| --- | --- | --- |
| `spec/VerifiableAuth/*.lean` における pure operation theorem と example | `engine/tests/unit` と `engine/tests/integration` の test 群 | Lean は proof-oriented evidence を与え、C は executable evidence を加えます。どちらか片方だけでは不十分で、組み合わせることで論拠が強くなります。 |
| register、連続 wrong password、lockout、change-password、logout をつなぐ `Examples.lean` scenario chain | `engine/tests/unit/test_login.c`, `engine/tests/unit/test_change_password.c`, `engine/tests/unit/test_logout.c`, さらに CLI integration test | scenario coverage は line-by-line で完全一致するわけではないものの、意味的には整合しています。 |
| `RefinementNotes.lean` における result-code と contract stability | `engine/tests/integration/test_cli_golden_json.c` と `tests/golden/cli-json/*` | engine は concrete JSON output を snapshot することで議論を強化します。Lean は result code の意味を定義し、golden test は公開表現が安定していることを示します。 |
| well-formedness preservation theorem | `engine/tests/integration/test_cli_corrupt_state.c`, `engine/tests/integration/test_file_user_store.c`, `engine/tests/integration/test_file_session_store.c` | Lean が通常抽象化する次元、つまり persistence corruption と CLI-visible `system_error` 挙動をこの test 群が埋めています。 |

## 操作別・境界別の証拠インデックス

上の各表は意味対応を詳しく説明しています。下の表は、レビュー担当者が
Lean の記述から concrete C 実装へ、さらに公開システムが runtime でも
そのとおりに振る舞う executable evidence へ、最短で移動するための索引です。

この索引は earlier section と意図的に冗長です。この冗長さには意味があります。
形式仕様と実装の比較文書は、読者が次の疑問にすぐ答えられるほど強くなります。

- 挙動はどこで仕様化されているか
- どこで実装されているか
- どこでテストされているか
- どこで公開契約として固定されているか

| Lean source または refinement note | C 実装アンカー | 対応 test / golden output | この証拠が重要な理由 |
| --- | --- | --- | --- |
| `RegisterSpec.register` の duplicate / success branch | `engine/src/core/register.c`, `engine/src/cli/command_runner.c` | `engine/tests/unit/test_register.c`, `engine/tests/integration/test_cli_register.c`, `tests/golden/cli-json/register-success.json`, `tests/golden/cli-json/register-duplicate.json` | 記号的 register transition、命令的 register 実装、公開 CLI result code が整合していることを示します。 |
| `LoginSpec.login` の `unknown_user`, `wrong_password`, `locked_out`, `already_authenticated` を含む branch | `engine/src/core/login.c`, `engine/src/core/state.c`, `engine/src/cli/command_runner.c` | `engine/tests/unit/test_login.c`, `engine/tests/integration/test_cli_login.c`, `tests/golden/cli-json/login-success.json`, `tests/golden/cli-json/login-unknown-user.json`, `tests/golden/cli-json/login-wrong-password.json`, `tests/golden/cli-json/login-locked-out.json`, `tests/golden/cli-json/login-already-authenticated.json` | login はシステム中でもっとも branch が多い操作です。この証拠列は、engine が形式状態機械を「なんとなく」ではなく、実際に refinement しているという主張の中核です。 |
| `LoginSpec.login_already_authenticated_is_noop` と `RefinementNotes.alreadyAuthenticated_does_not_count_as_login_failure` | `engine/src/core/login.c`, `engine/src/storage/file_audit_log.c` | `engine/tests/unit/test_login.c`, `engine/tests/integration/test_file_audit_log.c`, `engine/tests/integration/test_cli_show_metrics.c` | audit traceability と metric counting が意図的に異なる微妙なケースです。この行が可視化されていることで、実装が誤って login failure を過剰計上していないと示せます。 |
| `ChangePasswordSpec.changePassword`、特に `unauthorized`, `wrong_password`, `systemError`, successful credential replacement | `engine/src/core/change_password.c`, `engine/src/cli/command_runner.c`, `engine/src/crypto/hash_adapter.c`, `engine/src/crypto/salt_adapter.c` | `engine/tests/unit/test_change_password.c`, `engine/tests/integration/test_cli_change_password.c`, `tests/golden/cli-json/change-password-success.json`, `tests/golden/cli-json/change-password-unauthorized.json` | password change は symbolic Lean transition が concrete crypto work に refinement される最も分かりやすい例です。test と golden artifact は、より強い実装詳細を入れても branch structure が保たれていることを示します。 |
| `LogoutSpec.logout` と `GlobalInvariants.logout_does_not_modify_users` | `engine/src/core/logout.c`, `engine/src/core/state.c`, `engine/src/cli/command_runner.c` | `engine/tests/unit/test_logout.c` | logout は意図的に単純です。その単純さがあるため、non-mutation claim を theorem と code の両面でレビューしやすくなります。 |
| `RefinementNotes.*.cliCode` と `*.isOk` | `engine/src/cli/command_runner.c`, `engine/src/cli/json_output.c`, `engine/include/cli/exit_codes.h` | `engine/tests/integration/test_cli_golden_json.c`, `tests/golden/cli-json/*`, `docs/engine-cli-contract.md` | 形式モデルから public machine-readable boundary への橋渡しです。external client が ad hoc な CLI formatting ではなく stable semantics に依存していることを示す主要証拠です。 |
| `RefinementNotes.lean` における `AuditEventType`, `Metrics`, `computeMetrics`, 監査 refinement helper | `engine/src/storage/file_audit_log.c`, `engine/src/cli/command_runner.c` | `engine/tests/integration/test_file_audit_log.c`, `engine/tests/integration/test_cli_show_audit.c`, `engine/tests/integration/test_cli_show_metrics.c`, `observability/audit/sample-events.json`, `observability/metrics/sample-metrics.json` | observability layer が informal な付け足しではなく、記号的 event / metric model の tested refinement であることを示します。 |
| `WellFormed.AuthState`, `UniqueLoginIds`, `SessionConsistent` | `engine/src/storage/file_user_store.c`, `engine/src/storage/file_session_store.c` | `engine/tests/integration/test_file_user_store.c`, `engine/tests/integration/test_file_session_store.c`, `engine/tests/integration/test_cli_corrupt_state.c` | Lean は legal state を仮定します。engine は corrupted persistence に対してその境界を強制しなければなりません。この証拠は、実装が黙ってモデル外へ出ないよう守っている箇所を示します。 |
| `Examples.lean` の end-to-end scenario chain | `engine/src/core/*.c`, `engine/src/cli/command_runner.c`, TUI consumer boundary | `tests/contract/spec-to-test-mapping.md`, `tests/e2e/tui-register-flow.md`, `tests/e2e/tui-login-flow.md`, `tests/e2e/threshold-lock-flow.md`, `tests/e2e/password-change-flow.md` | 記号的 scenario narrative を、実行可能かつ operator-facing な flow へ接続します。プロジェクトが isolated unit だけでなく、層横断で挙動を検証していると分かります。 |

## 明示的な妥協点とその理由

最重要の実装上の妥協点を、ここで明示的に列挙します。これらはバグではありません。
proof-oriented model よりも現実の engine が具体的にならざるを得ない場所です。

### 1. 記号的な salt / hash と実際の暗号

- Lean は記号的な `Salt.initial`, `Salt.rotate`, `derivePasswordHash`, `verifyPassword` を使う
- engine は `auth_salt_generate(...)` と `PBKDF2-HMAC-SHA256` を使う

この妥協が存在する理由:

- 形式モデルは deterministic で proof-friendly な transition を必要とする
- engine は real password hashing と random salt generation を必要とする
- PBKDF2 実装そのものを証明対象外としたのは、検証対象の中心である state-machine
  property から焦点が外れないようにするためです。

それでも対応が有効な理由:

- 両層とも `(password, salt)` から credential material を導出するという意味論的性質を満たす
- 両層とも password change 時に credential material を置換する
- engine は security の観点から model より厳しくなっているのであって、弱くなっているのではない

### 2. 純粋関数遷移と in-place mutation

- Lean は post-state 全体を含む `Outcome α` を返す
- C は `auth_state_t *` を mutation し、result enum を返す

この妥協が存在する理由:

- Lean の証明は pure function 上で扱いやすい
- C の systems code は mutation を使ったほうが実装しやすく自然

それでも対応が有効な理由:

- mutation boundary は狭く、対応する operation 名に沿っている
- result code と postcondition は pure model と一致している

### 3. 無界 list と fixed-capacity array

- Lean は `List User` を使う
- C は `users[AUTH_MAX_USERS]` と `user_count` を使う

この妥協が存在する理由:

- 現在の engine は動的 allocation を避ける設計である
- fixed-capacity state により、memory management が単純で audit しやすい

それでも対応が有効な理由:

- user membership と single-session authentication の意味モデルは同じ
- capacity limit は supported range 内の implementation bound であり、操作の意味そのものを変えない

### 4. 形式的な well-formedness predicate と runtime parse rejection

- Lean は `AuthState.WellFormed` のような predicate を述べる
- engine は malformed persisted state を storage boundary で reject する

この妥協が存在する理由:

- Lean は合法 state を対象に推論する
- 実 engine は corrupted file や partial write から自分を守らなければならない

それでも対応が有効な理由:

- malformed runtime input を reject することこそが、実装をモデルが扱う state space の内部に留める仕組みである
- これはモデルからの乖離ではなく、モデル化された domain から外れないための防御機構である

### 5. core auth model と CLI / JSON / observability boundary

- Lean は auth state transition と result-code / metrics semantics の refinement note に集中する
- engine は stable JSON、timestamp、具体 file format を公開しなければならない

この妥協が存在する理由:

- JSON syntax、filename、timestamp は boundary concern である
- これらは TUI のような real client には重要だが、core transition proof の本質ではない

それでも対応が有効な理由:

- engine は JSON 契約と observability mapping を stable かつ test-backed に保っている
- operation result から emitted event / metric delta への semantic mapping は refinement note と整合している

## なぜこの表が重要なのか

本プロジェクトの主張は、形式仕様と C 実装の両方を持っているということに留まりません。
より強い主張として、実装を仕様の faithful refinement としてレビューできることを有します。

その主張が信頼に足るものになるのは、レビュー担当者が次を確認できる場合だけです。

- どの Lean 定義がどの C 構造体・関数に対応するのか
- どの theorem がどの operational guarantee や validation boundary に対応するのか
- どこで engine が model よりも具体的になっているのか
- そして、その具体的選択がなぜ指定挙動を弱めないのか

したがって、この対照表はプロジェクトの中核証拠の一部です。形式モデルと
実行可能 engine を正面から向き合わせる場所として機能します。

# Lean Specification to C Engine Comparison Table

This document is the primary traceability artifact between the formal specification in `spec/` and the C implementation in `engine/`.

Its purpose is not merely to list similarly named files. Its purpose is to make a persuasive, reviewable argument that:

- the Lean model states the intended behavior explicitly,
- the C engine implements the same behavior at the operational boundary,
- known mismatches are intentional refinements rather than silent divergence, and
- the remaining compromises are visible and defensible.

For the prose-level system contract, see [`system-specification.md`](./system-specification.md). For a shorter status summary, see [`spec-engine-alignment.md`](./spec-engine-alignment.md).

## How to Read This Document

The tables below use three columns:

| Lean specification | C implementation | Alignment rationale / implementation compromise |
| --- | --- | --- |

This is intentionally more verbose than a strict two-column cross-reference. The extra explanation is the critical part: formal specification only becomes convincing evidence when a reader can see how an executable implementation refines it, and where the implementation must become more concrete than the model.

The comparison is organized around:

1. core data definitions and state shape,
2. pure transition semantics,
3. invariants and preservation arguments,
4. CLI and observability refinement, and
5. explicit implementation compromises.

## State and Data Model

| Lean specification | C implementation | Alignment rationale / implementation compromise |
| --- | --- | --- |
| `LoginId := String` and `Password := String` in `spec/VerifiableAuth/Types.lean` | `char login_id[...]` and function parameters `const char *password` in `engine/include/auth/types.h`, `engine/include/auth/register.h`, `engine/include/auth/login.h`, and `engine/include/auth/change_password.h` | Both layers model login identifiers and passwords as textual values. The C layer adds fixed maximum lengths (`AUTH_LOGIN_ID_MAX_LENGTH`, `AUTH_PASSWORD_MAX_LENGTH`) because a low-level implementation needs bounded storage. This is a deliberate refinement, not a semantic change. |
| `lockoutThreshold : Nat := 3` in `spec/VerifiableAuth/Types.lean` | `AUTH_LOCKOUT_THRESHOLD 3u` in `engine/include/auth/types.h` | The threshold is identical across both layers. The C implementation uses a macro because this is the conventional constant mechanism in the current codebase. |
| `inductive LockState | active | locked` in `spec/VerifiableAuth/Types.lean` | `auth_lock_state_t` in `engine/include/auth/types.h` | This is a direct structural correspondence. The Lean sum type becomes a C enum with the same two states. |
| `structure Salt` with `owner` and `epoch`, plus `Salt.initial`, `Salt.rotate`, and `Salt.material` in `spec/VerifiableAuth/Types.lean` | `char salt[AUTH_SALT_ENCODED_LENGTH]` plus `auth_salt_generate(...)` in `engine/include/crypto/salt_adapter.h` and `engine/src/crypto/salt_adapter.c` | This is an intentional abstraction gap. Lean models salt symbolically so the state transition proofs do not depend on cryptographic or random-number generator details. The C engine must use actual randomness and a serializable representation, so it stores a 16-byte random salt encoded as lowercase hex. The semantic requirement preserved across both layers is "fresh per-user salt" and "new salt on password rotation", not the internal salt construction method. |
| `structure PasswordHash` and `derivePasswordHash` / `verifyPassword` in `spec/VerifiableAuth/Types.lean` | `char password_hash[AUTH_HASH_ENCODED_LENGTH]`, `auth_hash_password(...)`, and `auth_hash_verify_password(...)` in `engine/include/crypto/hash_adapter.h` and `engine/src/crypto/hash_adapter.c` | This is another deliberate refinement boundary. Lean uses a symbolic deterministic digest over `password` and `salt.material` so that correctness arguments stay about transition semantics rather than cryptographic engineering. The C engine uses `PBKDF2-HMAC-SHA256` with a real iteration count (`100000`) because the implementation must satisfy the prose requirement that plaintext passwords are not stored and that real password hashing is used. The preserved property is `password_hash = hash(password, salt)`, not the exact internals of the symbolic digest. |
| `structure User` in `spec/VerifiableAuth/Types.lean` | `auth_user_t` in `engine/include/auth/types.h` | Direct field-level alignment exists for `loginId/login_id`, `salt`, `passwordHash/password_hash`, `failedAttempts/failed_attempts`, and `lockState/lock_state`. The C representation adds concrete string storage and integer widths. |
| `structure AuthState` with `users : List User` and `authenticated : Option LoginId` in `spec/VerifiableAuth/Types.lean` | `auth_state_t` in `engine/include/auth/state.h` with `users[AUTH_MAX_USERS]`, `user_count`, `authenticated`, and `authenticated_login_id` | The semantic shape is the same: a user collection plus a single optional session. The main compromise is that Lean uses an unbounded `List`, while C uses a fixed-capacity array plus `user_count`. This is a pragmatic systems-level choice that keeps the engine simple and allocation-free. The resulting capacity limit is an implementation bound, not part of the formal behavior. |
| `Outcome α` in `spec/VerifiableAuth/Types.lean` | operation-specific result enums plus in-place state mutation in `engine/include/auth/result.h` and `engine/src/core/*.c` | Lean packages the post-state and result code together as a value because it is proving pure transition functions. C mutates `auth_state_t *` in place and returns only the result enum. This is an expected translation from a pure state machine model to imperative code. |
| `AuditEventType`, `AuditEvent`, and `Metrics` in `spec/VerifiableAuth/Types.lean` | `storage_audit_event_type_t`, `storage_audit_event_t`, `storage_metrics_t` in `engine/include/storage/audit_log.h` | The observability model is structurally aligned. The C layer adds concrete timestamp and string buffer widths because persisted records require bounded serialized fields. |

## State Helpers and Structural Definitions

| Lean specification | C implementation | Alignment rationale / implementation compromise |
| --- | --- | --- |
| `User.passwordMatches` in `spec/VerifiableAuth/StateModel.lean` | `auth_hash_verify_password(...)` calls in `engine/src/core/login.c` and `engine/src/core/change_password.c` | Lean expresses password checking as a proposition over a user record. The C engine realizes that proposition by recomputing the stored hash from plaintext input and the persisted salt. |
| `User.noteFailedLogin` in `spec/VerifiableAuth/StateModel.lean` | wrong-password branch in `engine/src/core/login.c` | The same state update is implemented: increment `failed_attempts`, lock when the threshold is reached, otherwise remain active. Lean packages this as a reusable pure helper; C performs the field updates inline. |
| `User.clearFailedAttempts` in `spec/VerifiableAuth/StateModel.lean` | success branch of `auth_login(...)` in `engine/src/core/login.c` | The current engine implementation clears the counter directly rather than through a helper function. This is a stylistic difference only. |
| `User.changePassword` in `spec/VerifiableAuth/StateModel.lean` | success branch of `auth_change_password(...)` in `engine/src/core/change_password.c` | Both layers replace the credential material and reset lock-related state. The C engine implements the same transition imperatively: fresh salt generation, hash derivation, clearing failures, and forcing `ACTIVE`. |
| `mkRegisteredUser` in `spec/VerifiableAuth/StateModel.lean` | new-user construction in `engine/src/core/register.c` | Both construct a fresh active user with zero failed attempts and derived password material. The difference is again symbolic versus concrete crypto material. |
| `AuthState.lookupUser?`, `containsUser`, `insertUser`, `replaceUser`, `clearSession`, and `setAuthenticated` in `spec/VerifiableAuth/StateModel.lean` | `auth_state_find_user`, `auth_state_find_user_mut`, `auth_state_clear_session`, and `auth_state_set_authenticated_user` in `engine/include/auth/state.h` and `engine/src/core/state.c` | These are direct operational counterparts. The main compromise is that Lean uses reusable list-level helper functions, while C uses linear scans over a fixed array. This is acceptable because the specification constrains behavior, not lookup complexity. |
| `User.CredentialsBound` and `AuthState.CredentialsBound` in `spec/VerifiableAuth/StateModel.lean` | indirect enforcement through `auth_register(...)`, `auth_change_password(...)`, and persisted-record validation in `engine/src/storage/file_user_store.c` | There is no direct C predicate named `CredentialsBound`, but the engine maintains the same invariant operationally: salts/hashes are always generated or regenerated through the dedicated adapters, and persisted records are validated before reentry into runtime state. This is a case where Lean expresses the invariant declaratively and C enforces it procedurally. |

## Well-Formedness and Global Invariants

| Lean specification | C implementation | Alignment rationale / implementation compromise |
| --- | --- | --- |
| `UniqueLoginIds` in `spec/VerifiableAuth/WellFormed.lean` | duplicate prevention in `engine/src/core/register.c` and duplicate rejection in `engine/src/storage/file_user_store.c` | The invariant is enforced both at mutation time and at persistence-load time. Lean states uniqueness as a property over all states; C prevents creation of duplicates and rejects malformed persisted states that violate it. |
| `User.WellFormed : user.lockState = .locked ↔ lockoutThreshold <= user.failedAttempts` in `spec/VerifiableAuth/WellFormed.lean` | threshold update logic in `engine/src/core/login.c` and load-time validation in `engine/src/storage/file_user_store.c` | The engine directly enforces the forward direction for produced states and checks a key consistency direction when loading persisted data. The full equivalence appears as a theorem in Lean, while the engine splits the guarantee between construction logic and parse-time rejection. |
| `AuthState.SessionConsistent` in `spec/VerifiableAuth/WellFormed.lean` | `auth_state_set_authenticated_user(...)` plus session-file validation in `engine/src/storage/file_session_store.c` | The C engine ensures that any deserialized authenticated login ID must correspond to an existing user; otherwise load fails with parse error. This is the concrete operational equivalent of Lean's existential session consistency predicate. |
| `AuthState.WellFormed` in `spec/VerifiableAuth/WellFormed.lean` | combined effect of core mutations plus storage parse validation in `engine/src/core/*.c`, `engine/src/storage/file_user_store.c`, and `engine/src/storage/file_session_store.c` | Lean can state a single conjunction over uniqueness, user well-formedness, and session consistency. The engine cannot prove that conjunction internally, so it enforces it by construction for newly produced states and by rejecting invalid on-disk state at the boundary. |
| `ConstructionInvariants`, `I02_UniqueLoginIds`, `I05_LockStateTracksThreshold`, `I11_SessionIsOptionalLoginId`, `I13_WellFormed`, and `CoreInvariants` in `spec/VerifiableAuth/GlobalInvariants.lean` | `engine/include/auth/types.h`, `engine/include/auth/state.h`, core transitions, storage loaders, and engine tests under `engine/tests` | This is a cross-cutting correspondence rather than a single function-to-function mapping. Lean centralizes the invariants; C distributes enforcement across type definitions, mutation code, deserialization checks, and test coverage. The compromise is structural, not semantic. |
| `register_preserves_construction_invariants`, `login_preserves_construction_invariants`, `changePassword_preserves_construction_invariants`, and `logout_preserves_construction_invariants` in `spec/VerifiableAuth/GlobalInvariants.lean` | engine tests in `engine/tests/unit/test_register.c`, `engine/tests/unit/test_login.c`, `engine/tests/unit/test_change_password.c`, `engine/tests/unit/test_logout.c`, plus storage parse tests in `engine/tests/integration` | Lean proves preservation abstractly. The C engine demonstrates the same property empirically through focused tests and by constraining all legal state mutations to the corresponding code paths. This is one of the most important proof-to-implementation compromises: C does not carry proof terms, so the evidence becomes "construction discipline + validation + tests". |
| `logout_does_not_modify_users` in `spec/VerifiableAuth/GlobalInvariants.lean` | `auth_logout(...)` in `engine/src/core/logout.c` and `engine/tests/unit/test_logout.c` | This is almost a direct one-line correspondence. The engine clears only the session fields and leaves the user array untouched. |
| `changePassword_success_clears_lock` in `spec/VerifiableAuth/GlobalInvariants.lean` | `user->failed_attempts = 0u; user->lock_state = AUTH_LOCK_STATE_ACTIVE;` in `engine/src/core/change_password.c` | This is a direct behavioral correspondence. |

## Operation Semantics

### Register

| Lean specification | C implementation | Alignment rationale / implementation compromise |
| --- | --- | --- |
| `register` definition in `spec/VerifiableAuth/RegisterSpec.lean` | `auth_register(...)` in `engine/src/core/register.c` | The same two branches exist: duplicate leaves state unchanged, otherwise a fresh user is appended. |
| duplicate branch returns `{ state := state, result := .duplicate }` | early duplicate return in `engine/src/core/register.c` | Direct alignment. The current imperative implementation returns before mutating anything. |
| success branch inserts `mkRegisteredUser` | new-user creation and append in `engine/src/core/register.c` | The engine performs the same logical work but must concretize salt/hash generation. |
| `register_preserves_session` theorem in `spec/VerifiableAuth/RegisterSpec.lean` | `auth_register(...)` does not touch session fields; CLI preserves this by saving only the modified user store in `engine/src/cli/command_runner.c` | Lean proves session preservation directly. C preserves it by omission: no session-field writes occur in `auth_register(...)`. |
| `register_success_initializes_active_user` theorem in `spec/VerifiableAuth/RegisterSpec.lean` | `new_user.failed_attempts = 0u; new_user.lock_state = AUTH_LOCK_STATE_ACTIVE;` in `engine/src/core/register.c` | Direct alignment. |

### Login

| Lean specification | C implementation | Alignment rationale / implementation compromise |
| --- | --- | --- |
| `login` definition in `spec/VerifiableAuth/LoginSpec.lean` | `auth_login(...)` in `engine/src/core/login.c` | Branch-for-branch correspondence exists for `already_authenticated`, `unknown_user`, `locked_out`, `wrong_password`, and `success`. |
| `state.authenticated = some _ -> alreadyAuthenticated` | `if (state->authenticated) return AUTH_LOGIN_RESULT_ALREADY_AUTHENTICATED;` in `engine/src/core/login.c` | Direct alignment. The engine treats both "same user" and "different user" re-login as already authenticated, exactly as required by the prose spec. |
| unknown-user branch leaves state unchanged | `user == nullptr -> AUTH_LOGIN_RESULT_UNKNOWN_USER` in `engine/src/core/login.c` | Direct alignment. |
| locked-user branch returns `.lockedOut` and leaves state unchanged | `user->lock_state == AUTH_LOCK_STATE_LOCKED` branch in `engine/src/core/login.c` | Direct alignment. |
| wrong-password branch uses `noteFailedLogin` and may produce `.wrongPassword` or `.lockedOut` | wrong-password branch in `engine/src/core/login.c` | Direct alignment. The C code performs the increment and threshold check inline rather than through a helper. |
| success branch clears failures and sets authenticated session | success branch in `engine/src/core/login.c` plus `auth_state_set_authenticated_user(...)` in `engine/src/core/state.c` | Direct alignment. |
| `login_already_authenticated_is_noop` theorem in `spec/VerifiableAuth/LoginSpec.lean` | early `authenticated` return in `engine/src/core/login.c` and persisted-metrics exclusion logic in `engine/src/storage/file_audit_log.c` | The state part is direct. The observability refinement goes further by recording the event as `LoginFailure` while not incrementing the failure metric, matching the specification and refinement note. |
| `login_unknown_user_keeps_state` theorem in `spec/VerifiableAuth/LoginSpec.lean` | unknown-user branch in `engine/src/core/login.c` | Direct alignment. |
| `login_success_sets_authenticated` theorem in `spec/VerifiableAuth/LoginSpec.lean` | `auth_state_set_authenticated_user(...)` in `engine/src/core/state.c` and `engine/tests/unit/test_login.c` | Lean proves the postcondition; the engine performs the state write directly and the test suite confirms the behavior. |

### Change Password

| Lean specification | C implementation | Alignment rationale / implementation compromise |
| --- | --- | --- |
| `changePassword` definition in `spec/VerifiableAuth/ChangePasswordSpec.lean` | `auth_change_password(...)` in `engine/src/core/change_password.c` | Branch-for-branch correspondence exists for `unauthorized`, `system_error`, `wrong_password`, and `success`. |
| unauthenticated branch returns `.unauthorized` and leaves state unchanged | `if (!state->authenticated)` in `engine/src/core/change_password.c` | Direct alignment. |
| authenticated but missing user returns `.systemError` | `user == nullptr` branch in `engine/src/core/change_password.c` | Direct alignment. |
| wrong old password leaves state unchanged | `auth_hash_verify_password(...) == false` branch in `engine/src/core/change_password.c` | Direct alignment. |
| success branch uses `user.changePassword newPassword` | success branch in `engine/src/core/change_password.c` | The same abstract effect is implemented, but with a real random salt and real password derivation. |
| `changePassword_preserves_session` theorem in `spec/VerifiableAuth/ChangePasswordSpec.lean` | `auth_change_password(...)` does not call `auth_state_clear_session(...)` or rewrite `authenticated_login_id` | Direct alignment. |
| `user_changePassword_rotates_salt` theorem in `spec/VerifiableAuth/ChangePasswordSpec.lean` | `auth_salt_generate(...)` call in `engine/src/core/change_password.c` | This is a semantically aligned but structurally different refinement. Lean models rotation by incrementing a symbolic salt epoch. The engine does not rotate an old salt deterministically; it generates a fresh random salt. This is a deliberate security-oriented strengthening of the implementation. The preserved property is "new salt distinct from the previous credential material", not "salt = old salt with epoch + 1". |
| `user_changePassword_clears_failures` theorem in `spec/VerifiableAuth/ChangePasswordSpec.lean` | `user->failed_attempts = 0u; user->lock_state = AUTH_LOCK_STATE_ACTIVE;` in `engine/src/core/change_password.c` | Direct alignment. |

### Logout

| Lean specification | C implementation | Alignment rationale / implementation compromise |
| --- | --- | --- |
| `logout` definition in `spec/VerifiableAuth/LogoutSpec.lean` | `auth_logout(...)` in `engine/src/core/logout.c` | Direct alignment: the only effect is session clearing and the only result is success. |
| `logout_preserves_users` theorem in `spec/VerifiableAuth/LogoutSpec.lean` | `auth_state_clear_session(...)` in `engine/src/core/state.c` and no user writes in `engine/src/core/logout.c` | Direct alignment. |
| `logout_clears_session` theorem in `spec/VerifiableAuth/LogoutSpec.lean` | `state->authenticated = false` and clearing `authenticated_login_id` in `engine/src/core/state.c` | Direct alignment. |

## Result Codes and CLI Refinement

| Lean specification | C implementation | Alignment rationale / implementation compromise |
| --- | --- | --- |
| `RegisterResult`, `LoginResult`, `ChangePasswordResult`, and `LogoutResult` in `spec/VerifiableAuth/Types.lean` | `auth_register_result_t`, `auth_login_result_t`, `auth_change_password_result_t`, and `auth_logout_result_t` in `engine/include/auth/result.h` | This is the core result-space alignment. |
| `*.cliCode` functions in `spec/VerifiableAuth/RefinementNotes.lean` | `cli_register_result_string(...)`, `cli_login_result_string(...)`, and `cli_change_password_result_string(...)` in `engine/src/cli/command_runner.c` | The string codes are intentionally stabilized at the CLI boundary. This is one of the most important refinement points because the TUI and any future tooling depend on those strings rather than C enum constants. |
| `*.isOk` functions in `spec/VerifiableAuth/RefinementNotes.lean` | `ok` booleans passed to `cli_json_write_*` helpers in `engine/src/cli/command_runner.c` | Direct behavioral alignment. The engine preserves the distinction between domain-level failures and runtime failures. |
| CLI contract requirement from `docs/system-specification.md` that responses include `ok`, `result`, `data`, and `error` | `cli_json_write_response_begin(...)`, `cli_json_write_response_end(...)`, and `cli_json_write_null_response(...)` in `engine/src/cli/json_output.c` | Lean does not model JSON syntax directly. The prose spec and refinement notes bridge the formal model to the concrete engine contract. This is a necessary layering compromise: JSON belongs to the implementation boundary, not to the pure state machine itself. |
| documented command set `register`, `login`, `change-password`, `logout`, `show-audit`, and `show-metrics` | dispatch logic in `engine/src/cli/command_runner.c` | Only the four auth transitions exist in the core Lean state machine. `show-audit` and `show-metrics` are refinement-level read-only commands over observability data, so they live outside the pure transition model. |

## Observability and Metrics Refinement

| Lean specification | C implementation | Alignment rationale / implementation compromise |
| --- | --- | --- |
| `AuditEventType`, `AuditEvent`, `Metrics`, `loginAuditEventType`, `countsAsLoginFailure`, `Metrics.record`, and `computeMetrics` in `spec/VerifiableAuth/Types.lean` and `spec/VerifiableAuth/RefinementNotes.lean` | `storage_audit_event_type_t`, `storage_audit_event_t`, `storage_metrics_t`, `storage_audit_log_counts_as_login_failure(...)`, and `storage_audit_log_compute_metrics(...)` in `engine/include/storage/audit_log.h` and `engine/src/storage/file_audit_log.c` | This is a strong refinement correspondence. The engine computes the same derived counters from persisted events that the Lean refinement notes compute from symbolic events. |
| `loginAuditEventType` in `spec/VerifiableAuth/RefinementNotes.lean` | `cli_login_audit_event_type(...)` in `engine/src/cli/command_runner.c` | Direct behavioral alignment. The engine distinguishes between an already-locked user and a newly triggered lockout in exactly the same way as the Lean refinement note. |
| `alreadyAuthenticated_does_not_count_as_login_failure` theorem in `spec/VerifiableAuth/RefinementNotes.lean` | `storage_audit_log_counts_as_login_failure(...)` in `engine/src/storage/file_audit_log.c` | Direct alignment and an especially important one. It shows that the engine preserves the subtle distinction between audit traceability and metric counting. |
| symbolic event sequence folded into metrics in Lean | audit-log persistence in `engine/src/storage/file_audit_log.c` plus `show-metrics` path in `engine/src/cli/command_runner.c` | The implementation adds concrete serialization and timestamps because operational artifacts must exist on disk. The semantic event categories and counting rules remain aligned. |
| `AuditEvent` in Lean has no timestamp field shape constraints beyond being a record field | `timestamp` generated at append time in `engine/src/storage/file_audit_log.c` | This is an intentional implementation detail left abstract in Lean. The formal model does not need a timestamp format to reason about state transitions. The engine must choose one to persist records. |

## Persistence Boundary and Runtime Validation

| Lean specification | C implementation | Alignment rationale / implementation compromise |
| --- | --- | --- |
| Lean state machine assumes legal `AuthState` values as function inputs | `storage_user_store_load(...)` and `storage_session_store_load(...)` in `engine/src/storage/file_user_store.c` and `engine/src/storage/file_session_store.c` validate persisted state before it becomes runtime state | This is one of the most important implementation-only obligations. A formal model usually starts from a well-formed state. A real engine must defend against corrupted files. The engine therefore treats malformed persistence as parse/runtime failure rather than silently constructing an illegal state. |
| `AuthState.WellFormed` and `SessionConsistent` in Lean | parse error when `session.txt` names a user missing from `users.tsv` in `engine/src/storage/file_session_store.c` | Direct refinement of session consistency to file-backed runtime state. |
| `UniqueLoginIds` and lock-state threshold consistency in Lean | duplicate-check and record-shape validation in `engine/src/storage/file_user_store.c` | The loader rejects persisted states that the Lean model would simply classify as not well formed. |
| no storage model in pure Lean operation specs | `users.tsv`, `session.txt`, and `audit.log` in `engine/src/storage/*.c` | This is an intentional modeling omission. The project treats storage format as an implementation detail beneath the formal transition semantics. That is a reasonable compromise because the proof target is the auth state machine, not the byte-level file encoding. |

## Tests as Supporting Evidence

| Lean specification | C implementation | Alignment rationale / implementation compromise |
| --- | --- | --- |
| pure operation theorems and examples in `spec/VerifiableAuth/*.lean` | unit tests in `engine/tests/unit` and integration tests in `engine/tests/integration` | Lean gives proof-oriented evidence; C adds executable evidence. Neither alone is enough for a persuasive engineering argument. The combination is stronger. |
| `Examples.lean` scenario chain for register, repeated wrong password, lockout, change-password, and logout | `engine/tests/unit/test_login.c`, `engine/tests/unit/test_change_password.c`, `engine/tests/unit/test_logout.c`, and CLI integration tests | The scenario coverage is aligned, although not line-by-line identical. |
| result-code and contract stability in `RefinementNotes.lean` | `engine/tests/integration/test_cli_golden_json.c` and `tests/golden/cli-json/*` | The engine strengthens the argument by snapshotting concrete JSON output. Lean defines the meaning of the result codes; golden tests show that the published representation is stable. |
| well-formedness preservation theorems | `engine/tests/integration/test_cli_corrupt_state.c`, `engine/tests/integration/test_file_user_store.c`, and `engine/tests/integration/test_file_session_store.c` | These tests cover a dimension that Lean normally abstracts away: corrupted persistence and CLI-visible `system_error` behavior. |

## Evidence Index by Operation and Boundary

The tables above explain the semantic correspondence in detail. The table below
is the shortest path for a reviewer who wants to move from a Lean statement, to
the concrete C implementation, to the executable evidence that the published
system still behaves that way at runtime.

This index is intentionally redundant with the earlier sections. That
redundancy is useful. A formal-to-implementation comparison document becomes
much stronger when the reader can answer all of these questions quickly:

- where the behavior is specified,
- where it is implemented,
- where it is tested,
- and where the externally visible contract is frozen.

| Lean source or refinement note | C implementation anchor | Supporting tests / golden outputs | Why this evidence matters |
| --- | --- | --- | --- |
| `RegisterSpec.register`, duplicate and success branches | `engine/src/core/register.c`, `engine/src/cli/command_runner.c` | `engine/tests/unit/test_register.c`, `engine/tests/integration/test_cli_register.c`, `tests/golden/cli-json/register-success.json`, `tests/golden/cli-json/register-duplicate.json` | This chain shows that the symbolic register transition, the imperative register implementation, and the published CLI result codes are aligned. |
| `LoginSpec.login`, including `unknown_user`, `wrong_password`, `locked_out`, and `already_authenticated` | `engine/src/core/login.c`, `engine/src/core/state.c`, `engine/src/cli/command_runner.c` | `engine/tests/unit/test_login.c`, `engine/tests/integration/test_cli_login.c`, `tests/golden/cli-json/login-success.json`, `tests/golden/cli-json/login-unknown-user.json`, `tests/golden/cli-json/login-wrong-password.json`, `tests/golden/cli-json/login-locked-out.json`, `tests/golden/cli-json/login-already-authenticated.json` | Login is the most branch-heavy operation in the system. This evidence chain is central to the project's claim that the engine refines the formally described state machine rather than merely approximating it. |
| `LoginSpec.login_already_authenticated_is_noop` and `RefinementNotes.alreadyAuthenticated_does_not_count_as_login_failure` | `engine/src/core/login.c`, `engine/src/storage/file_audit_log.c` | `engine/tests/unit/test_login.c`, `engine/tests/integration/test_file_audit_log.c`, `engine/tests/integration/test_cli_show_metrics.c` | This is a subtle case where audit traceability and metric counting intentionally differ. Keeping this row visible prevents a reviewer from assuming the implementation accidentally over-counts login failures. |
| `ChangePasswordSpec.changePassword`, especially `unauthorized`, `wrong_password`, `systemError`, and successful credential replacement | `engine/src/core/change_password.c`, `engine/src/cli/command_runner.c`, `engine/src/crypto/hash_adapter.c`, `engine/src/crypto/salt_adapter.c` | `engine/tests/unit/test_change_password.c`, `engine/tests/integration/test_cli_change_password.c`, `tests/golden/cli-json/change-password-success.json`, `tests/golden/cli-json/change-password-unauthorized.json` | Password change is the clearest example of a symbolic Lean transition being refined into concrete cryptographic work in C. The test and golden artifacts show that the stronger implementation details still preserve the modeled branch structure. |
| `LogoutSpec.logout` and `GlobalInvariants.logout_does_not_modify_users` | `engine/src/core/logout.c`, `engine/src/core/state.c`, `engine/src/cli/command_runner.c` | `engine/tests/unit/test_logout.c` | Logout is intentionally simple. That simplicity matters because it makes the non-mutation claim reviewable at both the theorem and code levels. |
| `RefinementNotes.*.cliCode` and `*.isOk` functions | `engine/src/cli/command_runner.c`, `engine/src/cli/json_output.c`, `engine/include/cli/exit_codes.h` | `engine/tests/integration/test_cli_golden_json.c`, `tests/golden/cli-json/*`, `docs/engine-cli-contract.md` | This row bridges the formal model to the public machine-readable boundary. It is the main evidence that external clients depend on stable semantics rather than ad hoc CLI formatting. |
| `AuditEventType`, `Metrics`, `computeMetrics`, and audit refinement helpers in `RefinementNotes.lean` | `engine/src/storage/file_audit_log.c`, `engine/src/cli/command_runner.c` | `engine/tests/integration/test_file_audit_log.c`, `engine/tests/integration/test_cli_show_audit.c`, `engine/tests/integration/test_cli_show_metrics.c`, `observability/audit/sample-events.json`, `observability/metrics/sample-metrics.json` | This row demonstrates that the observability layer is not an informal add-on. It is a tested refinement of the symbolic event and metric model. |
| `WellFormed.AuthState`, `UniqueLoginIds`, and `SessionConsistent` | `engine/src/storage/file_user_store.c`, `engine/src/storage/file_session_store.c` | `engine/tests/integration/test_file_user_store.c`, `engine/tests/integration/test_file_session_store.c`, `engine/tests/integration/test_cli_corrupt_state.c` | Lean assumes legal states. The engine must enforce that boundary against corrupted persistence. This evidence shows where the implementation defends the model rather than silently stepping outside it. |
| `Examples.lean` end-to-end scenario chain | `engine/src/core/*.c`, `engine/src/cli/command_runner.c`, and the TUI consumer boundary | `tests/contract/spec-to-test-mapping.md`, `tests/e2e/tui-register-flow.md`, `tests/e2e/tui-login-flow.md`, `tests/e2e/threshold-lock-flow.md`, `tests/e2e/password-change-flow.md` | This row ties the symbolic scenario narrative to real executable and operator-facing flows. It helps reviewers see that the project is verifying behavior across layers, not only inside isolated units. |

## Explicit Compromises and Why They Exist

The most important implementation compromises are listed here explicitly because they are not bugs; they are the places where a real engine must become more concrete than a proof-oriented model.

### 1. Symbolic salt and hash versus real cryptography

- Lean uses symbolic `Salt.initial`, `Salt.rotate`, `derivePasswordHash`, and `verifyPassword`.
- The engine uses `auth_salt_generate(...)` and `PBKDF2-HMAC-SHA256`.

Why this compromise exists:

- The formal model needs deterministic, proof-friendly transitions.
- The engine needs real password hashing and random salt generation.
- Proving over the exact PBKDF2 implementation would distract from the state-machine property being verified.

Why the correspondence is still valid:

- Both layers satisfy the required semantic property that user credentials are derived from `(password, salt)`.
- Both layers replace credential material on password change.
- The engine is stricter than the model from a security standpoint, not weaker.

### 2. Pure functional transitions versus in-place mutation

- Lean returns `Outcome α` values that contain the entire post-state.
- C mutates `auth_state_t *` and returns a result enum.

Why this compromise exists:

- Lean proofs are easier over pure functions.
- C systems code naturally uses mutable state for performance and simplicity.

Why the correspondence is still valid:

- The mutation boundaries are narrow and named after the same operations.
- The result codes and postconditions match the pure model.

### 3. Unbounded lists versus fixed-capacity arrays

- Lean uses `List User`.
- C uses `users[AUTH_MAX_USERS]` plus `user_count`.

Why this compromise exists:

- The engine deliberately avoids dynamic allocation in the current implementation.
- Fixed-capacity state keeps memory management simpler and easier to audit.

Why the correspondence is still valid:

- The semantic model of user membership and single-session authentication is the same.
- The capacity limit is an implementation bound, not a change to the meaning of operations inside the supported range.

### 4. Formal well-formedness predicates versus runtime parse rejection

- Lean states predicates such as `AuthState.WellFormed`.
- The engine rejects malformed persisted state at the storage boundary.

Why this compromise exists:

- Lean reasons about legal states.
- A real engine must defend itself against corrupted files and partial writes.

Why the correspondence is still valid:

- Rejecting malformed runtime inputs is exactly what keeps the implementation inside the modeled state space.
- This is not a divergence from the model; it is the mechanism by which the engine refuses to leave the modeled domain.

### 5. Core auth model versus CLI/JSON/observability boundary

- Lean focuses on auth state transitions and refinement notes for result-code and metrics semantics.
- The engine must expose stable JSON, timestamps, and concrete file formats.

Why this compromise exists:

- JSON syntax, filenames, and timestamps are boundary concerns.
- They matter to real clients such as the TUI but are not the essence of the core transition proof.

Why the correspondence is still valid:

- The engine keeps the JSON contract and observability mapping stable and test-backed.
- The semantic mapping from operation result to emitted event and metric delta remains aligned with the refinement notes.

## Why This Table Matters

The main claim of this project is not merely that it has both a formal specification and a C implementation. The stronger claim is that the implementation can be reviewed as a faithful refinement of the specification.

That claim is only credible if a reviewer can inspect:

- which Lean definitions correspond to which C structures and functions,
- which theorems correspond to which operational guarantees or validation boundaries,
- where the engine becomes more concrete than the model, and
- why those concrete choices do not weaken the specified behavior.

This comparison table is therefore part of the project's core evidence. It is the place where the formal model and the executable engine are made to face each other directly.

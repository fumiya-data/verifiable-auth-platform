# Code Review Report: Authentication Engine and TUI Boundary

Review date: 2026-05-03

Reviewed revision: `81d3092`

This document expands the code review summarized in
`~/helix-scratch/output.json` and records the local verification performed
against the current repository. The review focuses on the C authentication
engine, the CLI boundary, storage and audit behavior, the Go TUI engine client,
and the test strategy around those components.

## Executive Summary

The overall risk is high. The most important issue is that security-critical
credential generation is implemented as a side effect of `assert(...)`.
In builds where `NDEBUG` is defined, those expressions are not evaluated.
As a result, registration and password-change paths can report success without
creating or replacing the persisted password salt and hash.

The second major issue is that the public CLI boundary does not validate input
length or serialization safety before passing values into the core engine and
audit log. A long externally supplied `login_id` can corrupt the audit log while
the CLI still exits successfully with a domain-level result.

The normal debug-oriented test suite passes, but it does not provide enough
evidence for release behavior because both production code and tests currently
depend on the C standard `assert` macro.

## Scope

Reviewed areas:

- Core authentication state transitions in `engine/src/core`
- CLI command handling in `engine/src/cli/command_runner.c`
- File-backed user, session, and audit storage in `engine/src/storage`
- Go TUI process boundary in `tui/internal/engineclient`
- C and Go test coverage relevant to the findings

Out of scope:

- Formal proof completeness in the Lean specification
- New implementation changes
- Full threat modeling for multi-user host environments

## Findings

### 1. Credential Generation Depends on `assert(...)`

Severity: Critical

Category: Security / correctness

Affected files:

- `engine/src/core/register.c`
- `engine/src/core/change_password.c`

The registration path generates the salt and password hash as follows:

```c
assert(auth_salt_generate(new_user.salt, sizeof(new_user.salt)) == AUTH_SALT_STATUS_OK);
assert(auth_hash_password(...) == AUTH_HASH_STATUS_OK);
```

The password-change path has the same pattern:

```c
assert(auth_salt_generate(user->salt, sizeof(user->salt)) == AUTH_SALT_STATUS_OK);
assert(auth_hash_password(...) == AUTH_HASH_STATUS_OK);
```

This is not only a diagnostic assertion. The function calls themselves are the
operations that generate the credential material. When `NDEBUG` is defined, the
C standard `assert` macro expands in a way that does not evaluate its argument.
Therefore the salt generation and password hashing calls are removed from the
compiled program.

Impact:

- `register` can return success while persisting a user with empty salt and
  empty password hash fields.
- `change-password` can return success without replacing the user's credential
  material.
- Persisted state can become unparsable or inconsistent with the authentication
  invariants expected by the storage loader.
- The release build can diverge materially from the behavior verified by normal
  debug tests.

Local verification:

- A direct `-DNDEBUG` build with the repository warning flags failed because
  values used only inside `assert(...)` became unused (`password_len` in
  `register.c`, `new_password` in `change_password.c`).
- After relaxing only those unused-warning errors for verification, a
  `register` command returned `{"ok":true,"result":"success",...}` while
  writing a `users.tsv` row where the salt and hash fields were empty.
- A subsequent `login` failed while loading the corrupted state.

Recommended remediation:

- Move `auth_salt_generate` and `auth_hash_password` calls into ordinary
  statements.
- Check each returned status explicitly.
- Return a runtime failure result if either operation fails.
- Extend `auth_register_result_t` with a system-error or capacity-exceeded
  branch, or otherwise define a stable error path at the core/CLI boundary.
- Add a Release or `NDEBUG` verification job to CI.

### 2. `auth_register` Trusts External Invariants for Capacity and Login ID Length

Severity: Critical

Category: Security / memory safety

Affected file:

- `engine/src/core/register.c`

`auth_register` assumes two invariants that are not enforced at runtime:

```c
assert(state->user_count < AUTH_MAX_USERS);
...
memcpy(new_user.login_id, login_id, login_id_len + 1u);
```

`new_user.login_id` is a fixed-size buffer of
`AUTH_LOGIN_ID_MAX_LENGTH + 1`. The function computes `login_id_len` from the
caller-supplied string and copies that length plus the terminator without
checking the maximum. In debug builds, the function only asserts the user
capacity condition. It does not assert or validate `login_id_len`.

Impact:

- A full `auth_state_t` can write past `state->users` in builds where
  `assert` is disabled.
- An overlong `login_id` can write past `new_user.login_id`.
- The core API is unsafe for any caller that fails to enforce the intended
  preconditions exactly.

Recommended remediation:

- Validate `state`, `login_id`, `password`, login ID length, password length,
  and store capacity with ordinary runtime checks.
- Return an explicit error result when the fixed user store is full.
- Avoid copying caller strings into fixed buffers unless the destination size
  has already been checked.
- Treat `assert` only as a development-time invariant check, never as the sole
  enforcement mechanism for externally reachable input.

### 3. CLI Input Validation Is Incomplete

Severity: High

Category: Correctness / storage integrity

Affected file:

- `engine/src/cli/command_runner.c`

The CLI checks only whether required options are present:

```c
static bool cli_ensure_required(const char *value)
{
    return value != nullptr;
}
```

It does not call `auth_validate_login_id` or `auth_validate_password` before
executing `register`, `login`, or `change-password`. It also does not reject
characters that cannot safely round-trip through the current TSV-backed storage
formats, such as tab or newline.

Impact:

- Overlong login IDs can reach the core and storage layers.
- Invalid values can be written to audit records.
- The CLI can return process exit code `0` for a domain result while leaving the
  audit log unreadable for subsequent `show-audit` or `show-metrics` commands.
- The public contract currently describes required options but not the complete
  accepted input domain.

Local verification:

Using the normal debug build, a `login` command with a 300-character unknown
user ID returned:

```json
{"ok":false,"result":"unknown_user","data":null,"error":{"message":"login failed"}}
```

The process exit code was `0`, but the generated audit record was truncated.
The next `show-audit` command returned:

```json
{"ok":false,"result":"system_error","data":null,"error":{"message":"failed to load audit log"}}
```

Recommended remediation:

- Add a CLI validation layer for every externally supplied login ID and
  password.
- Reuse `auth_validate_login_id` and `auth_validate_password` for null, empty,
  and maximum-length checks.
- Extend validation to reject delimiters and control characters that cannot be
  represented safely in `users.tsv`, `session.txt`, or `audit.log`.
- Return `invalid_request` and the usage-error exit code for malformed input.
- Add CLI integration tests for overlong login IDs, overlong passwords, empty
  strings, tab characters, newline characters, and boundary-length values.

### 4. Audit Append Treats `snprintf` Truncation as Success

Severity: High

Category: Correctness / observability integrity

Affected file:

- `engine/src/storage/file_audit_log.c`

The audit append path formats each line into a fixed 256-byte buffer:

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

The code checks only for a negative return value. For `snprintf`, a return
value greater than or equal to the destination size means the output was
truncated. That condition must be treated as failure when writing a structured
record.

Impact:

- A malformed or overlong input can produce a partial audit line.
- Later audit parsing can fail even though the write operation returned success.
- Derived metrics can become unavailable because metrics are computed from the
  audit log.

Recommended remediation:

- Check `snprintf_result >= sizeof(line)` and return an error.
- Prefer dynamically sized formatting or a structured escaping layer for
  append-only records.
- Add tests that prove boundary-length records are accepted and over-boundary
  records fail without writing partial lines.

### 5. Plaintext Passwords Are Passed Through Process Arguments

Severity: Medium

Category: Security / secret handling

Affected files:

- `tui/internal/engineclient/client.go`
- `tui/internal/engineclient/command_exec.go`
- `docs/engine-cli-contract.md`

The TUI invokes the engine with plaintext password values in argv:

```go
executeRequest[EmptyData](c, "register", "--login-id", loginID, "--password", password)
executeRequest[EmptyData](c, "login", "--login-id", loginID, "--password", password)
executeRequest[EmptyData](c, "change-password", "--old-password", oldPassword, "--new-password", newPassword)
```

This matches the documented public CLI contract, which requires `--password`,
`--old-password`, and `--new-password` values.

Impact:

- Passwords may be visible through process inspection APIs.
- Passwords may be captured by shell history, wrapper logs, crash telemetry,
  endpoint monitoring, or command-line tracing.
- The risk depends on host configuration, but the current contract makes secret
  exposure the default integration path.

Recommended remediation:

- Move secret transport off argv.
- Use stdin, an inherited pipe, or a short-lived file descriptor for password
  input.
- Keep argv flags for non-secret values such as `--data-dir` and `--login-id`.
- Update `docs/engine-cli-contract.md`, `docs-jp/エンジン用CLI.md`, and TUI
  client tests together so the contract and implementation remain aligned.

### 6. Tests Use the C Standard `assert` Macro as the Assertion Mechanism

Severity: Medium

Category: Testability / release confidence

Affected files:

- `engine/tests/unit/*.c`
- `engine/tests/integration/*.c`

The C test suite uses `assert(...)` extensively. That is acceptable only when
the tests are never compiled with `NDEBUG`. In this repository, the same macro
also caused a production bug because side effects were embedded inside
assertion expressions.

Impact:

- If tests are compiled with `NDEBUG`, many test checks become no-ops.
- A release-mode verification job could pass without actually checking the
  expected behavior.
- The test strategy does not currently protect against differences between
  debug and release compilation modes.

Recommended remediation:

- Replace test `assert(...)` calls with a small always-on test helper, for
  example `TEST_CHECK(condition)`, that prints file and line information and
  exits non-zero on failure.
- Add at least one CI job that builds and runs the engine tests with
  `NDEBUG` or a CMake Release configuration.
- Add targeted regression tests for credential generation in Release mode.

## Verification Performed

Commands that passed:

```powershell
.\scripts\run-engine-tests.ps1
```

Result: 17 of 17 C engine tests passed.

```powershell
go test ./...
```

Run from `tui`.

Result: all Go packages passed or had no test files.

Additional verification:

- CMake Release configuration was attempted but timed out during compiler ABI
  detection in the local environment.
- The Makefile `NDEBUG` path was attempted with `mingw32-make`, but the
  Windows environment lacked the Unix `touch` command required by the
  Makefile's build marker rule.
- A direct `clang -DNDEBUG` verification build showed the credential-generation
  issue described above.
- The long-login audit corruption scenario was reproduced with the normal debug
  build.

Temporary verification artifacts were removed after the review.

## Recommended Remediation Order

1. Remove side effects from production `assert(...)` expressions and add
   explicit runtime error handling for salt/hash generation.
2. Add runtime checks in `auth_register` for login ID length and user store
   capacity.
3. Enforce CLI input validation before calling core auth functions or writing
   audit records.
4. Make audit append fail on `snprintf` truncation.
5. Add regression tests for the above cases, including malformed CLI input and
   release-style builds.
6. Redesign password transport so the TUI and public CLI contract do not pass
   secrets through process arguments.
7. Replace C test `assert(...)` usage with an always-on test assertion helper.

## Residual Risk

Until the first four remediation items are complete, the repository should not
be treated as release-ready for authentication use. The current implementation
can pass the normal test suite while still failing security-critical behavior in
`NDEBUG` builds and while allowing externally supplied CLI input to corrupt
observability storage.

## Remediation Applied on 2026-05-12

The findings above were addressed in
[`code-review-2026-05-03-remediation.md`](./code-review-2026-05-03-remediation.md).

Summary of applied fixes:

- Removed credential-generation side effects from production `assert(...)`
  expressions.
- Added runtime `auth_register` guards for null input, invalid login ID or
  password length, and full fixed-capacity state.
- Added CLI validation before core auth calls and audit writes.
- Made audit append reject `snprintf` truncation.
- Moved password transport from argv to stdin with `--password-stdin`,
  `--old-password-stdin`, and `--new-password-stdin`.
- Replaced C test `assert(...)` usage with always-on `TEST_CHECK(...)`.
- Added regression tests for malformed CLI input, audit truncation, Release
  behavior, and TUI secret transport.
- Updated Lean result-code refinement notes, EN/JP contract documents, and CI
  Release-mode engine verification.

Verification passed:

- `.\scripts\run-engine-tests.ps1`: 17 of 17 C engine tests passed.
- `go test ./...` from `tui`: passed.
- CMake Release build plus `ctest`: 17 of 17 C engine tests passed.
- `.\scripts\run-spec-check.ps1`: Lean build completed successfully.
- `git diff --check`: passed with only Windows line-ending warnings.

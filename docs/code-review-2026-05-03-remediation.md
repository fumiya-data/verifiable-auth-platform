# Code Review Remediation Record: 2026-05-12

This document records the repository changes made in response to
[`code-review-2026-05-03-en.md`](./code-review-2026-05-03-en.md).

## Scope

The remediation covered the authentication engine, CLI boundary, audit storage,
Go TUI engine client, Lean result-code refinement notes, CI verification, and
the C/Go regression test suites.

## Fixes Applied

1. Credential generation no longer depends on `assert(...)`.
   - `engine/src/core/register.c`
   - `engine/src/core/change_password.c`
   - Salt generation and password hashing now run as ordinary statements.
   - Return statuses are checked explicitly.
   - Runtime failures return `system_error` instead of relying on debug-only
     assertion behavior.

2. `auth_register` now performs runtime safety checks.
   - `engine/include/auth/result.h`
   - `engine/include/auth/register.h`
   - `engine/src/core/register.c`
   - The core register path validates null arguments, login ID length,
     password length, and fixed user-store capacity before copying into fixed
     buffers.
   - `AUTH_REGISTER_RESULT_SYSTEM_ERROR` was added for implementation-bound
     failures.

3. CLI input validation was added before core state transitions and audit
   writes.
   - `engine/src/cli/command_runner.c`
   - Login IDs and passwords are checked for null, empty, maximum length, and
     control characters.
   - Login IDs that cannot safely round-trip through TSV-backed storage are
     rejected.
   - Malformed input returns `invalid_request` with the usage-error exit code.

4. Audit append now treats `snprintf` truncation as failure.
   - `engine/src/storage/file_audit_log.c`
   - A formatted audit line whose required length is greater than or equal to
     the destination buffer is rejected instead of writing a partial structured
     record.

5. Password transport was moved off process arguments.
   - `engine/include/cli/command_runner.h`
   - `engine/src/cli/command_runner.c`
   - `tui/internal/engineclient/client.go`
   - `tui/internal/engineclient/command_exec.go`
   - The public CLI now uses `--password-stdin`, `--old-password-stdin`, and
     `--new-password-stdin`.
   - The previous plaintext argv flags are rejected as `invalid_request`.
   - The Go TUI sends password values through stdin and keeps only non-secret
     values in argv.

6. C tests no longer depend on the C standard `assert` macro.
   - `engine/tests/support/test_support.h`
   - `engine/tests/support/cli_test_support.h`
   - `engine/tests/unit/*.c`
   - `engine/tests/integration/*.c`
   - Test checks now use `TEST_CHECK(...)`, which remains active in Release or
     `NDEBUG` builds.

7. Regression coverage was added for the reviewed failure modes.
   - Core register null/invalid/full-state handling.
   - CLI overlong login IDs, overlong passwords, empty passwords, tab/newline
     rejection, and boundary-length accepted values.
   - Audit append truncation rejection.
   - TUI secret transport through stdin rather than argv.
   - Release-mode engine verification.

8. Specification and contract documents were aligned with the new boundary.
   - `spec/VerifiableAuth/Types.lean`
   - `spec/VerifiableAuth/RefinementNotes.lean`
   - `docs/engine-cli-contract.md`
   - `docs/system-specification.md`
   - `docs/spec-engine-comparison-table.md`
   - `docs-jp/エンジン用CLI.md`
   - `docs-jp/仕様書.md`
   - `docs-jp/Lean仕様とC言語エンジンの対照表.md`

9. CI now includes Release-mode engine verification.
   - `.github/workflows/engine.yml`
   - The engine workflow builds and runs the C test suite in a CMake Release
     configuration after the normal engine test path.

## Verification

The following checks passed locally:

```powershell
.\scripts\run-engine-tests.ps1
```

Result: 17 of 17 C engine tests passed.

```powershell
go test ./...
```

Run from `tui`.

Result: all Go packages passed or had no test files.

```powershell
cmake -S .\engine -B .\engine\.build-release -DCMAKE_BUILD_TYPE=Release
cmake --build .\engine\.build-release
ctest --test-dir .\engine\.build-release --output-on-failure
```

Result: 17 of 17 C engine tests passed in Release mode.

```powershell
.\scripts\run-spec-check.ps1
```

Result: Lean build completed successfully after the configured toolchain was
available.

```powershell
git diff --check
```

Result: passed, with only line-ending warnings from Git on Windows.

## Working Tree Notes

The remediation intentionally did not claim ownership of pre-existing README
edits, `.scratch/`, or the untracked review Markdown files that were already
present before the implementation work.

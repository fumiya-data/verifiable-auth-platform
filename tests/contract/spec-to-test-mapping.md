# Specification to Lean and Test Mapping

This matrix records where the documented behavior is represented formally in
Lean and where it is executed in the C engine test suite.

| Requirement | Lean source | Engine evidence |
| --- | --- | --- |
| State is `users + authenticated` | `VerifiableAuth.Types.AuthState` | `engine/include/auth/state.h`, unit and integration tests |
| Login IDs are unique | `VerifiableAuth.WellFormed.UniqueLoginIds`, `GlobalInvariants.I02_UniqueLoginIds` | `engine/tests/unit/test_register.c`, `engine/tests/integration/test_file_user_store.c` |
| Lock state tracks threshold | `VerifiableAuth.WellFormed.User.WellFormed`, `GlobalInvariants.I05_LockStateTracksThreshold` | `engine/tests/unit/test_login.c`, `engine/tests/integration/test_file_user_store.c` |
| Successful login clears failures and authenticates | `VerifiableAuth.LoginSpec.login_success_sets_authenticated` | `engine/tests/unit/test_login.c`, `engine/tests/integration/test_cli_login.c`, `engine/tests/integration/test_cli_golden_json.c` |
| Failed login only mutates state on wrong-password or new lockout | `VerifiableAuth.LoginSpec.login`, `RefinementNotes.loginPersistsState` | `engine/src/cli/command_runner.c`, `engine/tests/unit/test_login.c` |
| Successful password change replaces salt and hash | `VerifiableAuth.ChangePasswordSpec.user_changePassword_rotates_salt` | `engine/tests/unit/test_change_password.c` |
| Logout does not modify users | `VerifiableAuth.LogoutSpec.logout_preserves_users`, `GlobalInvariants.logout_does_not_modify_users` | `engine/tests/unit/test_logout.c` |
| `already_authenticated` does not increment login-failure metrics | `VerifiableAuth.RefinementNotes.alreadyAuthenticated_does_not_count_as_login_failure` | `engine/tests/integration/test_file_audit_log.c`, `engine/tests/integration/test_cli_show_metrics.c` |
| CLI result strings are stable machine-readable codes | `VerifiableAuth.RefinementNotes.*.cliCode` | `engine/tests/integration/test_cli_golden_json.c`, `tests/golden/cli-json/*` |
| Corrupted persisted state surfaces as engine `system_error` | refinement boundary, not a pure state-transition theorem | `engine/tests/integration/test_cli_corrupt_state.c`, `engine/tests/integration/test_file_session_store.c`, `engine/tests/integration/test_file_user_store.c` |

## Verification Notes

- Lean model verification: `lake build` in `spec/`
- Engine verification: GCC builds and tests under `engine/tests`
- Exact JSON contract snapshots: `tests/golden/cli-json`

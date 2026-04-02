# Change Password Contract Cases

| Case | Document source | Lean source | Engine coverage |
| --- | --- | --- | --- |
| `unauthorized` keeps state unchanged when no session exists | `docs/system-specification.md` §5.3 branch 1 | `VerifiableAuth.ChangePasswordSpec.changePassword`, `changePassword_unauthorized_is_noop` | `engine/tests/unit/test_change_password.c`, `engine/tests/integration/test_cli_golden_json.c` |
| `system_error` is returned when the authenticated user is missing from state | `docs/system-specification.md` §5.3 branch 2 | `VerifiableAuth.ChangePasswordSpec.changePassword` | `engine/tests/unit/test_change_password.c` |
| persisted corrupted session state is surfaced as CLI `system_error` | `docs/system-specification.md` §15 and §16 | refinement boundary between Lean and CLI | `engine/tests/integration/test_cli_corrupt_state.c`, `engine/tests/integration/test_file_session_store.c` |
| `wrong_password` keeps salt and hash unchanged | `docs/system-specification.md` §5.3 branch 3 | `VerifiableAuth.ChangePasswordSpec.changePassword` | `engine/tests/unit/test_change_password.c` |
| `success` rotates salt, replaces hash, clears lock state, and preserves the session | `docs/system-specification.md` §5.3 branch 4 | `VerifiableAuth.ChangePasswordSpec.changePassword`, `user_changePassword_rotates_salt`, `user_changePassword_clears_failures`, `changePassword_preserves_session` | `engine/tests/unit/test_change_password.c`, `engine/tests/integration/test_cli_change_password.c`, `engine/tests/integration/test_cli_golden_json.c` |

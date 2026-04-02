# Logout Contract Cases

| Case | Document source | Lean source | Engine coverage |
| --- | --- | --- | --- |
| `success` clears the session and leaves users unchanged | `docs/system-specification.md` §5.5 | `VerifiableAuth.LogoutSpec.logout`, `logout_preserves_users`, `logout_clears_session` | `engine/tests/unit/test_logout.c`, `engine/tests/integration/test_cli_show_metrics.c` |

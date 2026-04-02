# Register Contract Cases

| Case | Document source | Lean source | Engine coverage |
| --- | --- | --- | --- |
| `success` inserts a new active user and keeps the session unchanged | `docs/system-specification.md` §5.1 | `VerifiableAuth.RegisterSpec.register`, `register_preserves_session` | `engine/tests/unit/test_register.c`, `engine/tests/integration/test_cli_register.c`, `engine/tests/integration/test_cli_golden_json.c` |
| `duplicate` leaves state unchanged except for observability output | `docs/system-specification.md` §5.1 | `VerifiableAuth.RegisterSpec.register` | `engine/tests/unit/test_register.c`, `engine/tests/integration/test_cli_register.c`, `engine/tests/integration/test_cli_golden_json.c` |

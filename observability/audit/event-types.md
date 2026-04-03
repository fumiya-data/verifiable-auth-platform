# Audit Event Types

The engine emits the following stable event kinds.

| Event Type | Meaning | Typical Result Codes |
| --- | --- | --- |
| `Register` | Registration attempt | `success`, `duplicate` |
| `LoginSuccess` | Successful login | `success` |
| `LoginFailure` | Login failure that is not a new lockout | `unknown_user`, `wrong_password`, `locked_out`, `already_authenticated` |
| `Lock` | Threshold-crossing login failure that creates a new lockout | `locked_out` |
| `PasswordChange` | Password change attempt | `success`, `wrong_password`, `unauthorized`, `system_error` |
| `Logout` | Logout execution | `success` |

## Notes

- `already_authenticated` is intentionally recorded as `LoginFailure` for audit
  traceability.
- A `locked_out` result may appear under either `LoginFailure` or `Lock`.
  `Lock` is used only when the current failed attempt causes the new lockout.

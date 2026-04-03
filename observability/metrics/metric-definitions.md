# Metrics Definitions

Metrics are derived from the audit log; they are not independently authored.

## Stable Counters

| Metric | Type | Definition |
| --- | --- | --- |
| `login_success_count` | non-negative integer | Number of `LoginSuccess` audit events |
| `login_failure_count` | non-negative integer | Number of login failures counted by the observability contract |
| `lockout_count` | non-negative integer | Number of `Lock` audit events |

## Counting Rule

`login_failure_count` includes:

- `LoginFailure` with `unknown_user`
- `LoginFailure` with `wrong_password`
- `LoginFailure` with `locked_out`
- `Lock` with `locked_out`

`login_failure_count` excludes:

- `LoginFailure` with `already_authenticated`

That exclusion is intentional and matches both the engine implementation and
`spec/VerifiableAuth/RefinementNotes.lean`.

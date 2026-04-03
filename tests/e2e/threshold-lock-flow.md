# Threshold Lock Flow

1. Register `alice`.
2. Attempt login with a wrong password three times.
3. Confirm the first two attempts report `wrong_password`.
4. Confirm the third attempt reports `locked_out`.
5. Run `show-audit` and confirm the terminal event is `Lock/locked_out`.
6. Run `show-metrics` and confirm:
   - `login_failure_count` includes all three failed attempts
   - `lockout_count` increments by one

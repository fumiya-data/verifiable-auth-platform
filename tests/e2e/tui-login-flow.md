# TUI Login Flow

1. Register `alice` through the engine or TUI.
2. Navigate to `Login`.
3. Submit `alice` with the correct password.
4. Confirm the status bar reports `login -> success`.
5. Confirm the home screen shows an authenticated session hint for `alice`.
6. Run `show-audit` and confirm a `LoginSuccess/success` event exists.
7. Run `show-metrics` and confirm `login_success_count` increments by one.

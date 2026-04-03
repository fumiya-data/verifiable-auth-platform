# TUI Register Flow

1. Build the engine and launch the TUI with `scripts/run-tui.sh`.
2. Navigate to `Register`.
3. Submit a new `login_id` and password.
4. Confirm the status bar reports `register -> success`.
5. Run `show-audit` and confirm the newest audit event is `Register/success`.
6. Run `show-metrics` and confirm login counters are unchanged.

# Go TUI Runbook

This runbook explains how to build, run, smoke-test, and extend the Go Bubble
Tea TUI for the verifiable auth platform.

## Scope

The TUI under `tui/` is a thin operational wrapper over the C engine CLI. It
must not implement authentication rules locally. Auth behavior flows through
the stable engine contract documented in [`engine-cli-contract.md`](./engine-cli-contract.md).

## Prerequisites

- Go version compatible with [`tui/go.mod`](../tui/go.mod).
- A C toolchain that can build the engine CLI.
- `cmake` plus a build backend such as Ninja.

On Windows, using MSYS2 UCRT GCC is the most predictable local path:

```powershell
Get-Command gcc,cmake,ninja
```

## Build the Engine CLI

The TUI expects an `engine_cli` executable. It searches these repo-relative
locations automatically:

- `engine/.build/engine_cli.exe`
- `engine/.build/engine_cli`
- `engine/build/engine_cli.exe`
- `engine/build/engine_cli`

### PowerShell

```powershell
cmake -S engine -B engine\build -G Ninja -DCMAKE_C_COMPILER=C:/msys64/ucrt64/bin/gcc.exe
cmake --build engine\build --target engine_cli
```

If a different compiler is already configured correctly, omit
`-DCMAKE_C_COMPILER=...`.

### Bash

```bash
cmake -S engine -B engine/build
cmake --build engine/build --target engine_cli
```

## Launch the TUI

### PowerShell

```powershell
.\scripts\run-tui.ps1 --data-dir .\.engine-data
```

### Bash

```bash
./scripts/run-tui.sh --data-dir ./.engine-data
```

If the engine binary is in a non-default location, pass it explicitly:

```powershell
.\scripts\run-tui.ps1 --engine-path .\engine\build\engine_cli.exe --data-dir .\.engine-data
```

Equivalent environment variables are also supported:

```powershell
$env:VERIFIABLE_AUTH_ENGINE_PATH = "C:\path\to\engine_cli.exe"
$env:VERIFIABLE_AUTH_DATA_DIR = "C:\path\to\data-dir"
.\scripts\run-tui.ps1
```

## Controls

```text
Up/Down or j/k  Move the home selection
Enter           Select an operation or submit a form
Esc             Return to the home screen
r               Reload audit or metrics screens
q               Quit from home, audit, or metrics screens
Ctrl+C          Quit from any screen
```

## Smoke Test

1. Launch the TUI.
2. Select `Register`.
3. Enter a new `login_id` and password.
4. Confirm the status bar reports `register -> success`.
5. Select `Login` with the same credentials.
6. Confirm the status bar reports `login -> success`.
7. Select `Show Audit` and confirm register/login events are visible.
8. Select `Show Metrics` and confirm login counters changed as expected.

For flow-specific evidence, see the E2E runbooks under [`tests/e2e`](../tests/e2e).

## Verify the Go TUI

Run the TUI package tests separately from the engine:

```powershell
Push-Location tui
go test ./...
Pop-Location
```

## Troubleshooting

`engine binary not found`

Build `engine_cli` into `engine/.build` or `engine/build`, or pass
`--engine-path` when launching the TUI.

`decode engine response`

Run the engine command directly and confirm it prints exactly one JSON object to
stdout. The TUI depends on the JSON envelope from `engine-cli-contract.md`.

Windows Clang fails on CRT deprecation warnings

Configure the build with MSYS2 UCRT GCC as shown above, or use another compiler
configuration that does not turn MSVC CRT deprecation warnings into build
failures.

Stale local auth state

The configured `--data-dir` stores engine-managed `users.tsv`, `session.txt`,
and `audit.log` files. Use a fresh data directory when testing a clean flow.

## Extension Points

Use these files when adding a new TUI operation:

- `docs/engine-cli-contract.md`
  - Define or update the public engine command first.
- `tui/internal/engineclient/`
  - Add the client method and response decoding shape.
- `tui/internal/commands/`
  - Wrap the client call in a Bubble Tea command.
- `tui/internal/messages/`
  - Add the completion message passed back into the update loop.
- `tui/internal/types/types.go`
  - Add route or selection values when the operation needs a screen.
- `tui/internal/screens/`
  - Add or update the screen model and view.
- `tui/internal/app/update.go`
  - Wire key handling, async command dispatch, and completion handling.
- `tui/internal/app/view.go`
  - Render the new route.

Keep validation and auth decisions in the C engine. The TUI should collect
input, call the engine, display the result, and preserve the CLI contract.

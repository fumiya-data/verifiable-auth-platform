# Verifiable Auth TUI

This directory contains the Go Bubble Tea terminal UI for the verifiable auth
platform.

## Boundary

The TUI is a thin operational wrapper over the engine CLI contract. It must not
implement authentication rules locally.

## Run

```powershell
go run ./cmd/auth-tui
```

For the full build, launch, smoke-test, and extension workflow, see
[`../docs/go-tui-runbook.md`](../docs/go-tui-runbook.md).

## Configuration

- `--engine-path`
  - Override the engine CLI binary path.
- `--data-dir`
  - Override the engine data directory passed to the engine.
- `VERIFIABLE_AUTH_ENGINE_PATH`
  - Environment override for the engine binary path.
- `VERIFIABLE_AUTH_DATA_DIR`
  - Environment override for the engine data directory.

If no engine path is supplied, the TUI searches common repo-relative engine
build locations.

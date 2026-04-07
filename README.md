# Verifiable Auth Platform

Verifiable Auth Platform is a local authentication foundation centered on verifiability across specification, implementation, testing, and observability.

## Documentation

- [Documentation Index](./docs/README.md)
- [System Specification](./docs/system-specification.md)
- [Lean Specification to C Engine Comparison Table](./docs/spec-engine-comparison-table.md)
- [Specification and Engine Alignment](./docs/spec-engine-alignment.md)
- [Engine CLI Contract](./docs/engine-cli-contract.md)
- [Authentication State Machine](./docs/state-machine.md)

## Architecture Decision Records

- [ADR 0001: Use Lean for the Formal Specification Layer](./docs/adr/0001-formal-specification-language.md)
- [ADR 0002: Use C for the Engine Implementation Layer](./docs/adr/0002-engine-implementation-language.md)
- [ADR 0003: Keep the Go TUI as a Thin Operational Wrapper](./docs/adr/0003-thin-tui-boundary.md)
- [ADR 0004: Use Python for Analysis and Reporting](./docs/adr/0004-python-analysis-and-reporting.md)

## Prerequisites

- Lean 4 via `elan`
  - The exact toolchain is pinned by [`spec/lean-toolchain`](./spec/lean-toolchain).
- A C toolchain for the engine
  - `cmake` + `ctest` are the preferred verification path.
  - `make` is an accepted fallback where available.
  - `gcc` or `clang` must be available to the chosen build system.
- Go for the TUI
  - The target version is pinned by [`tui/go.mod`](./tui/go.mod).
- Python 3.12 for the analysis layer
  - Install dependencies from [`analysis/requirements.txt`](./analysis/requirements.txt) before running analysis scripts.

## Verification

The repository-level verification entrypoints are:

- `scripts/run-spec-check.sh`
  - Builds the Lean reference model under `spec/`.
- `scripts/run-spec-check.ps1`
  - PowerShell entrypoint for the same Lean build flow on Windows.
- `scripts/run-engine-tests.sh`
  - Builds and tests the C engine from source.
- `scripts/run-engine-tests.ps1`
  - PowerShell entrypoint for engine verification on Windows.
- `scripts/run-tui.sh`
  - Starts the Bubble Tea TUI.
- `scripts/run-tui.ps1`
  - PowerShell entrypoint for launching the Bubble Tea TUI on Windows.
- `scripts/run-e2e.sh`
  - Runs the full verification flow: spec, engine, TUI tests, and fixture consistency.
- `scripts/run-e2e.ps1`
  - PowerShell entrypoint for the same end-to-end verification flow on Windows.

The Python analysis layer can be checked independently with:

- `python analysis/scripts/check_fixture_consistency.py`
- `python analysis/scripts/summarize_audit.py observability/audit/sample-events.json`
- `python analysis/scripts/summarize_metrics.py observability/metrics/sample-metrics.json`
- `python analysis/scripts/export_report.py --audit observability/audit/sample-events.json --metrics observability/metrics/sample-metrics.json --report both`

## Repository Layout

- `spec/`
  - Lean state machine and refinement notes.
- `engine/`
  - C auth engine, CLI contract, and persistence adapters.
- `tui/`
  - Go Bubble Tea operational wrapper over the engine CLI.
- `observability/`
  - Audit and metrics contract definitions.
- `analysis/`
  - Read-only Python summarization and reporting tooling.
- `tests/`
  - Contract notes, golden outputs, and E2E runbooks.
- `fixtures/`
  - Canonical sample state and scenario artifacts.
- `.github/workflows/`
  - GitHub Actions verification entrypoints for spec, engine, TUI, and end-to-end checks.

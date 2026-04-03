# Verifiable Auth Platform

Verifiable Auth Platform is a local authentication foundation centered on verifiability across specification, implementation, testing, and observability.

## Documentation

- [System Specification](./docs/system-specification.md)
- [Specification and Engine Alignment](./docs/spec-engine-alignment.md)

## Architecture Decision Records

- [ADR 0001: Use Lean for the Formal Specification Layer](./docs/adr/0001-formal-specification-language.md)
- [ADR 0002: Use C for the Engine Implementation Layer](./docs/adr/0002-engine-implementation-language.md)
- [ADR 0003: Keep the Go TUI as a Thin Operational Wrapper](./docs/adr/0003-thin-tui-boundary.md)
- [ADR 0004: Use Python for Analysis and Reporting](./docs/adr/0004-python-analysis-and-reporting.md)

## Verification

The repository-level verification entrypoints are:

- `scripts/run-spec-check.sh`
  - Builds the Lean reference model under `spec/`.
- `scripts/run-engine-tests.sh`
  - Builds and tests the C engine from source.
- `scripts/run-tui.sh`
  - Starts the Bubble Tea TUI.
- `scripts/run-e2e.sh`
  - Runs the full verification flow: spec, engine, TUI tests, and fixture consistency.

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

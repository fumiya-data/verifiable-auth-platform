# Observability Contract

This directory defines the read-only observability layer consumed by the TUI,
the analysis scripts, and downstream dashboards.

## Source of Truth

- Runtime production of audit events and derived metrics lives in the C engine.
- Behavioral intent comes from `docs/system-specification.md`.
- Symbolic refinement rules live in `spec/VerifiableAuth/RefinementNotes.lean`.

## Scope

- `audit/`
  - Stable event taxonomy and serialized audit record shape.
- `metrics/`
  - Stable derived counters and example payloads.
- `dashboards/`
  - Human-facing dashboard definitions derived from the audit and metrics
    contracts.

No file in this directory is allowed to introduce authentication logic. These
artifacts only describe and consume behavior already defined by the engine and
formal model.

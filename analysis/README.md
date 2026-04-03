# Analysis Layer

This directory contains the read-only Python reporting layer described by
ADR 0004.

## Principles

- Inputs are audit and metrics artifacts emitted by the engine.
- The analysis layer must not mutate authentication state.
- Derived metrics must remain consistent with the engine's observability rules.

## Entry Points

- `scripts/summarize_audit.py`
  - Parse audit TSV or JSON and emit a structured summary.
- `scripts/summarize_metrics.py`
  - Normalize a metrics JSON payload and emit a summary.
- `scripts/export_report.py`
  - Render Markdown reports from audit and metrics inputs.
- `scripts/check_fixture_consistency.py`
  - Verify that sample audit and metrics fixtures agree.

## Quick Start

```bash
python analysis/scripts/check_fixture_consistency.py
python analysis/scripts/summarize_audit.py observability/audit/sample-events.json
python analysis/scripts/export_report.py \
  --audit observability/audit/sample-events.json \
  --metrics observability/metrics/sample-metrics.json \
  --report both
```

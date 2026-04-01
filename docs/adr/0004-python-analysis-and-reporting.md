# ADR 0004: Use Python for Analysis and Reporting

## Status

Accepted

## Context

The analysis layer is responsible for aggregating audit data, visualizing outcomes, and producing reports from observability artifacts. This layer is intentionally read-only and must be practical for later expansion, including possible integration with database-backed workflows.

## Decision

We use `Python` for the analysis and reporting layer.

## Rationale

- Python is a strong fit for reporting, visualization, and data-oriented workflows.
- The language provides a practical path for future integration with databases and downstream analysis pipelines.
- Visualization and report generation are areas where Python has a mature and productive ecosystem.
- This makes Python a natural choice for turning audit logs and metrics into readable analytical outputs.

## Consequences

- The analysis layer can grow toward richer reporting and data integration without forcing changes into the engine or TUI.
- The project benefits from existing Python tooling for aggregation, charting, and report generation.
- The read-only boundary must remain explicit so that analysis does not become a second implementation of system logic.

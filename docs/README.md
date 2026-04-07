# Documentation Index

This directory contains the primary written evidence for how the project is
specified, implemented, and verified.

## Recommended Reading Order

1. [`system-specification.md`](./system-specification.md)
   - The prose-level contract for the platform.
2. [`spec-engine-comparison-table.md`](./spec-engine-comparison-table.md)
   - The main evidence artifact that aligns the Lean model with the C engine.
3. [`spec-engine-alignment.md`](./spec-engine-alignment.md)
   - A shorter cross-layer status summary.
4. [`engine-cli-contract.md`](./engine-cli-contract.md)
   - The stable CLI and JSON boundary consumed by the Go TUI.
5. [`state-machine.md`](./state-machine.md)
   - The concrete auth state machine view used to explain operation flow.

## Core Documents

- [`system-specification.md`](./system-specification.md)
  - Canonical prose specification for the platform.
- [`spec-engine-comparison-table.md`](./spec-engine-comparison-table.md)
  - Detailed Lean-to-C traceability table with explicit implementation compromises.
- [`spec-engine-alignment.md`](./spec-engine-alignment.md)
  - Shorter summary of the current cross-layer alignment status.
- [`engine-cli-contract.md`](./engine-cli-contract.md)
  - Stable command names, arguments, JSON envelope, and exit-code policy.
- [`state-machine.md`](./state-machine.md)
  - Focused explanation of the core password-auth state transitions.

## Architecture Decision Records

- [`adr/0001-formal-specification-language.md`](./adr/0001-formal-specification-language.md)
- [`adr/0002-engine-implementation-language.md`](./adr/0002-engine-implementation-language.md)
- [`adr/0003-thin-tui-boundary.md`](./adr/0003-thin-tui-boundary.md)
- [`adr/0004-python-analysis-and-reporting.md`](./adr/0004-python-analysis-and-reporting.md)

## Notes

- The comparison table is the central evidence artifact for the project. It is
  the document that makes the Lean specification and the C implementation face
  each other directly.
- Generated presentation artifacts such as `*.pretty.pdf` are derived from the
  Markdown sources and are not part of the tracked documentation set.

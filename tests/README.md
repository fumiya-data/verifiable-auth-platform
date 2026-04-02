# Test Artifacts

This directory tracks test intent and externally visible contract artifacts for
the platform.

## Structure

- `contract/`
  - Human-readable case lists and traceability notes from the specification to
    Lean and executable tests.
- `golden/`
  - Stable sample outputs that should not change without an intentional
    contract update.
- `e2e/`
  - End-to-end scenarios that describe cross-layer behavior for future TUI and
    system-level testing.

## Source of Truth

- Behavioral requirements come from `docs/system-specification.md`.
- Formal semantics come from `spec/VerifiableAuth`.
- Executable validation currently lives in `engine/tests`.

When behavior changes, update the contract notes and golden artifacts in this
directory alongside the implementation and Lean model.

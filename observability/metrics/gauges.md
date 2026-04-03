# Gauge Policy

The current observability contract does not define any gauges.

All first-class metrics in this repository are counters derived from the audit
history. If a future change introduces gauges, it must update:

- `docs/system-specification.md`
- `spec/VerifiableAuth/RefinementNotes.lean`
- this directory's metric definitions

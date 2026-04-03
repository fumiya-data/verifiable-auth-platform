# Specification, Lean, and Engine Alignment

This document records the current alignment status between:

- [`docs/system-specification.md`](./system-specification.md)
- [`spec/VerifiableAuth`](../spec/VerifiableAuth)
- [`engine/include`](../engine/include) and [`engine/src`](../engine/src)

## Current Status

The three layers are currently aligned on the following core behaviors:

- State model: `users + authenticated session`
- Operation set: `register`, `login`, `change_password`, `logout`
- Result codes exposed by the CLI contract
- Lockout threshold behavior and session-preservation rules
- Password-change semantics that replace both salt and hash
- Observability mapping for audit events and derived metrics
- The rule that `already_authenticated` is recorded as `LoginFailure` but does not increment `login_failure_count`

## Verified Sources

### Documented semantics

- [`docs/system-specification.md`](./system-specification.md)

### Lean model

- [`spec/VerifiableAuth/RegisterSpec.lean`](../spec/VerifiableAuth/RegisterSpec.lean)
- [`spec/VerifiableAuth/LoginSpec.lean`](../spec/VerifiableAuth/LoginSpec.lean)
- [`spec/VerifiableAuth/ChangePasswordSpec.lean`](../spec/VerifiableAuth/ChangePasswordSpec.lean)
- [`spec/VerifiableAuth/LogoutSpec.lean`](../spec/VerifiableAuth/LogoutSpec.lean)
- [`spec/VerifiableAuth/WellFormed.lean`](../spec/VerifiableAuth/WellFormed.lean)
- [`spec/VerifiableAuth/GlobalInvariants.lean`](../spec/VerifiableAuth/GlobalInvariants.lean)
- [`spec/VerifiableAuth/RefinementNotes.lean`](../spec/VerifiableAuth/RefinementNotes.lean)

### C engine

- Core state transitions under [`engine/src/core`](../engine/src/core)
- CLI contract under [`engine/src/cli/command_runner.c`](../engine/src/cli/command_runner.c)
- Audit and metrics persistence under [`engine/src/storage`](../engine/src/storage)

## Verification Performed

- `lake build` succeeded in `spec/`
- The repository now defines a canonical engine verification path through
  [`../scripts/run-engine-tests.sh`](../scripts/run-engine-tests.sh), which
  configures a fresh CMake build, compiles the C engine, and runs CTest.
- Contract and golden mappings are recorded under [`tests/contract`](../tests/contract) and [`tests/golden`](../tests/golden)

## Intentional Modeling Differences

The layers are aligned semantically, but they do not model every detail at the same level:

- Lean models salts and password hashes symbolically.
  - The engine uses random per-user salts and `PBKDF2-HMAC-SHA256`.
  - Lean uses symbolic `Salt.rotate` and `derivePasswordHash` to reason about state transitions without reproducing crypto internals.
- Lean does not model storage file formats or timestamps.
  - The engine defines concrete file-backed stores and runtime-generated UTC audit timestamps.
- The document is normative for behavior, while Lean and C are executable refinements of that behavior.

## Follow-Up Rule

When a future change touches any of the following, update all three layers together:

- operation branches or result codes
- invariants or well-formedness rules
- audit event mapping
- metrics counting rules
- CLI JSON field names or command names

The same change should also update the observability and analysis contracts
under [`../observability`](../observability) and [`../analysis`](../analysis).

# ADR 0001: Use Lean for the Formal Specification Layer

## Status

Accepted

## Context

This project is centered on verifiability rather than feature breadth. Its primary value is not only to implement authentication behavior, but to make the semantics of authentication explicit, analyzable, and defensible.

Because of that goal, the project requires a language and toolchain suited to formal reasoning rather than only practical implementation.

## Decision

We use `Lean` for the formal specification layer.

## Rationale

- The project places higher value on clarifying the semantics of authentication than on implementing the runtime system as quickly as possible.
- The name `verifiable-auth-platform` reflects the intent to prioritize verification as a first-class property.
- Lean is well suited to formal specification and formal verification.
- Lean provides a precise medium for stating invariants, state transitions, and correctness-related properties without depending on implementation detail.

## Consequences

- The specification layer can act as the semantic reference point for the rest of the system.
- Invariants and transition rules can be expressed explicitly and reviewed independently of the engine.
- The project takes on the cost of maintaining a formal model, but gains a stronger foundation for traceability and correctness.

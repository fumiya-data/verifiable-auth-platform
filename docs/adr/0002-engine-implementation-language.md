# ADR 0002: Use C for the Engine Implementation Layer

## Status

Accepted

## Context

The engine is the layer that realizes the authentication state machine in executable form. It must be suitable for systems-level implementation and should remain close to explicit control over data structures, memory, and runtime behavior.

Rust would also be a viable implementation language for this layer, and in some respects it may be preferable for safety and ergonomics. However, one of the goals of this project is to gain practical understanding of both the strengths and the essential difficulties of low-level systems implementation.

Because of that goal, the engine should be implemented in a language that exposes concerns such as memory handling, data representation, and explicit state-transition control directly.

## Decision

We use `C` for the engine implementation layer and write it in a modern `C23` style.

## Rationale

- The engine is a systems-oriented component, and C is a natural fit for systems programming.
- Rust is a credible alternative, but the project intentionally chooses C in order to confront low-level implementation concerns more directly.
- This includes practical exposure to memory handling, data representation, and explicit state-transition control at the engine boundary.
- The project aims to combine that low-level implementation model with a disciplined modern coding style rather than treating C as a purely legacy language.
- The choice is informed by the desire to work in a style aligned with modern C practice, including a `C23`-oriented approach.

## Consequences

- The engine remains close to the machine model and suitable for explicit state-transition implementation.
- The project accepts more engineering burden than it would likely face with a safer and more ergonomic language such as Rust.
- The codebase must enforce clear conventions to keep the C layer maintainable and safe.
- In exchange, the engine layer provides direct experience with the strengths and essential difficulties of low-level systems implementation.

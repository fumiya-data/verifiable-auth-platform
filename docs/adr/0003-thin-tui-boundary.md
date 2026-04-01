# ADR 0003: Keep the Go TUI as a Thin Operational Wrapper

## Status

Accepted

## Context

The project is not primarily about UI design. Its central theme is verifiable authentication behavior across specification, implementation, tests, and observability.

The UI must therefore support operation without becoming a second implementation of authentication logic.

## Decision

We use a `Go` TUI built with `Bubble Tea`, and we keep it as a thin wrapper over the engine contract.

## Rationale

- The UI only needs to wrap the engine and expose operations; it does not need to carry domain logic.
- Keeping the TUI thin preserves the architectural boundary between interaction and authentication semantics.
- Bubble Tea provides a relatively simple way to build a polished terminal UI.
- The framework is sufficient to produce a clean and visually refined interface without making UI development a central project concern.

## Consequences

- The TUI remains replaceable because core authentication rules stay outside the UI layer.
- UI behavior can evolve independently so long as the engine contract remains stable.
- The project reduces the risk of business logic leaking into presentation code.

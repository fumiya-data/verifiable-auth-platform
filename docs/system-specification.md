# Verifiable Auth Platform System Specification

Companion traceability documents:

- [`README.md`](./README.md)
- [`spec-engine-comparison-table.md`](./spec-engine-comparison-table.md)
- [`spec-engine-alignment.md`](./spec-engine-alignment.md)
- [`engine-cli-contract.md`](./engine-cli-contract.md)
- [`state-machine.md`](./state-machine.md)

The comparison table is the primary evidence artifact for this project. It is
the document that makes the Lean model and the C engine implementation face
each other directly, including the points where the implementation must become
more concrete than the formal model.

## 1. Purpose

The Verifiable Auth Platform is a local authentication foundation whose core property is verifiability. The system is not defined merely by the presence of authentication features, but by the requirement that its behavior can be specified, implemented, tested, observed, and analyzed in a consistent and traceable manner.

The platform is organized into four layers:

- Formal specification layer (`Lean`)
- Implementation layer (`C`)
- Operation layer (`Go` TUI)
- Observability and analysis layer (`observability` and `Python`)

The target domain is password authentication on a single node. The following are explicitly out of scope:

- Distributed authentication
- Multi-factor authentication
- External identity federation

## 2. Scope and Assumptions

### 2.1 Scope

The system supports account registration, login, password change, logout, audit inspection, and metric inspection for a single-node password authentication workflow.

### 2.2 Assumptions

- The runtime environment is local and constrained to a single process or a single node.
- Authentication is based on `login_id + password`.
- Passwords are never stored in plaintext.
- The hash function is treated as a deterministic function.
- A unique salt is generated independently for each user.
- Authentication state is represented as a single session: `Option<LoginId>`.
- The TUI uses only the engine's published contract and does not contain authentication logic.
- The observability and analysis layer is read-only and must not mutate authentication state.

## 3. System Model

The system is defined as a state transition system.

### 3.1 State

```text
State:
  users: List<User>
  authenticated: Option<LoginId>
```

### 3.2 User

```text
User:
  login_id
  salt
  password_hash
  failed_attempts
  lock_state
```

### 3.3 Operations

The system exposes the following state-transition operations:

- `register(id, password)`
- `login(id, password)`
- `change_password(old, new)`
- `logout`

## 4. Core Invariants

The following invariants define the required safety and consistency properties of the platform.

- `I-01`: Plaintext passwords must never appear in state, logs, or outputs.
- `I-02`: `login_id` must be unique.
- `I-03`: `password_hash = hash(password, salt)` must always hold.
- `I-04`: `failed_attempts >= 0`.
- `I-05`: If `failed_attempts >= threshold`, then `lock_state = Locked`.
- `I-06`: If `lock_state = Locked`, successful login is impossible.
- `I-07`: On successful login, `failed_attempts = 0`.
- `I-08`: On successful registration, `failed_attempts = 0` and `lock_state = Active`.
- `I-09`: On successful password change, both the salt and hash must be replaced with newly derived values.
- `I-10`: `logout` must not modify `users`.
- `I-11`: Authentication state must be either `Unauthenticated` or `Authenticated`.
- `I-12`: Failed operations must leave the state unchanged unless the specification explicitly permits a state update.
- `I-13`: `WellFormed(state)` must be preserved by every operation.
- `I-14`: The formal specification, engine, tests, and observability model must remain aligned.

## 5. Operation Semantics

### 5.1 Register

#### Precondition

- The specified `login_id` is not already registered.

#### Transition

```text
salt <- freshSalt
hash <- hash(password, salt)
user <- mkUser(id, salt, hash)
users <- insert(user)
```

#### Results

- `success`
- `duplicate`

#### Properties

- The authentication state remains unchanged.
- A newly created user is initialized with `lock_state = Active`.
- A newly created user is initialized with `failed_attempts = 0`.

### 5.2 Login

#### Branches

1. User does not exist
   - Result: `unknown_user`
   - State: unchanged

2. User is locked
   - Result: `locked_out`
   - State: unchanged

3. Password hash does not match
   - `failed_attempts <- failed_attempts + 1`
   - If the threshold is not reached:
     - Result: `wrong_password`
   - If the threshold is reached:
     - `lock_state <- Locked`
     - Result: `locked_out`

4. Password hash matches
   - `failed_attempts <- 0`
   - `authenticated <- some id`
   - Result: `success`

#### Properties

- Only `success` may change the authentication state.
- On failure, `authenticated` remains unchanged.
- `locked_out` may mean either that the user was already locked or that the current failed attempt caused the lockout.
- If `authenticated = some other_id`, login as `id` must fail with `already_authenticated`, and the state remains unchanged.
- If `authenticated = some id`, repeated login as the same user must fail with `already_authenticated`, and the state remains unchanged.

### 5.3 Change Password

#### Precondition

- `authenticated = some id`

#### Branches

1. No authenticated session
   - Result: `unauthorized`
   - State: unchanged

2. User record is missing despite an authenticated session
   - Result: `system_error`
   - Interpretation: integrity violation

3. Old password does not match
   - Result: `wrong_password`
   - State: unchanged

4. Old password matches
   - `salt <- freshSalt`
   - `hash <- hash(new, salt)`
   - `user <- rehashUser`
   - `failed_attempts <- 0`
   - `lock_state <- Active`
   - Result: `success`

#### Properties

- The authenticated session is preserved.
- A successful password change also clears any prior lock state.
- `change_password(old, new)` applies only to the currently authenticated user.

### 5.4 Register While Authenticated

If `authenticated = some id`, `register(new_id, password)` remains valid and does not change the authentication state.

### 5.5 Logout

#### Transition

```text
authenticated <- none
```

#### Result

- `success`

#### Properties

- `users` remains unchanged.

## 6. State Transitions

### 6.1 Account State

```text
Unregistered -> Active
Active -> Locked
Locked -> Active    (via change_password)
```

### 6.2 Session State

```text
Unauthenticated -> Authenticated
Authenticated -> Unauthenticated
```

## 7. Data Model

### 7.1 User Record

```text
UserRecord:
  login_id          (unique)
  salt
  password_hash
  failed_attempts   >= 0
  lock_state        in {Active, Locked}
```

### 7.2 Global State

```text
State:
  users: List<User>
  authenticated: Option<LoginId>
```

### 7.3 Audit Event

```text
AuditEvent:
  event_type in {
    Register,
    LoginSuccess,
    LoginFailure,
    Lock,
    PasswordChange,
    Logout
  }
  timestamp
  login_id
  result
```

### 7.4 Metrics

```text
Metric:
  login_success_count
  login_failure_count
  lockout_count
```

### 7.5 Observability Mapping

- `register -> success` records `event_type = Register`, `result = success`, and does not change login metrics.
- `register -> duplicate` records `event_type = Register`, `result = duplicate`, and does not change login metrics.
- `login -> success` records `event_type = LoginSuccess`, `result = success`, and increments `login_success_count`.
- `login -> wrong_password` records `event_type = LoginFailure`, `result = wrong_password`, and increments `login_failure_count`.
- `login -> unknown_user` records `event_type = LoginFailure`, `result = unknown_user`, and increments `login_failure_count`.
- `login -> locked_out` records `event_type = Lock` if the attempt causes a new lockout, otherwise `event_type = LoginFailure`; in both cases `result = locked_out`, `login_failure_count` increments, and `lockout_count` increments only on a new lockout.
- `login -> already_authenticated` records `event_type = LoginFailure`, `result = already_authenticated`, and does not change login metrics.
- `change_password -> success` records `event_type = PasswordChange`, `result = success`, and does not change login metrics.
- `change_password -> wrong_password | unauthorized | system_error` records `event_type = PasswordChange` with the corresponding `result`, and does not change login metrics.
- `logout -> success` records `event_type = Logout`, `result = success`, and does not change login metrics.

## 8. System Architecture

```text
spec (Lean)
  -> defines
engine (C)
  -> exposes CLI contract
tui (Go Bubble Tea)
  -> interacts via contract
observability (logs and metrics schema)
  -> consumed by
analysis (Python)
```

### Responsibilities

- `spec`: defines invariants and operational semantics
- `engine`: implements the state transitions
- `tui`: provides the operational interface
- `observability`: defines the recording model for audits and metrics
- `analysis`: visualizes and aggregates recorded behavior

## 9. Interface Contract

The engine must expose the following CLI commands:

- `register`
- `login`
- `change-password`
- `logout`
- `show-audit`
- `show-metrics`

All outputs must be machine-readable and serialized as JSON.

The CLI contract consists of:

- stable command names
- stable JSON response field names
- stable result codes
- deterministic serialization for equivalent results

Every command response must include:

- `ok: boolean`
- `result: string`
- `data: object | null`
- `error: object | null`

If `ok = true`, then `error = null`.

If `ok = false`, then `result` must still contain a stable machine-readable code, and `error` must describe the failure without exposing secret material.

The TUI is only allowed to invoke the engine contract. It must not embed authentication rules or duplicate business logic.

## 10. Test Strategy

### 10.1 Test Categories

- Contract tests for specification alignment
- Unit tests for engine internals
- Integration tests for storage and CLI behavior
- End-to-end tests for TUI interactions
- Golden tests for fixed output behavior

### 10.2 Traceability Rules

- Every specified case in the formal model must map to at least one contract test.
- CLI outputs must be stabilized with golden files where appropriate.

## 11. Observability

### 11.1 Recorded Artifacts

- Audit logs as an event sequence
- Metrics as aggregate counters

### 11.2 Constraints

- No secret material may appear in logs or metrics.
- Recorded behavior must remain traceable.
- Recorded behavior must remain reproducible for analysis.

## 12. Analysis

The Python analysis layer may be used for:

- Audit aggregation
- Failure distribution analysis
- Lockout occurrence analysis
- Test-result visualization

### Analysis Constraints

- The analysis layer is strictly read-only.
- The analysis layer must not modify authentication state.

## 13. Repository Structure

```text
verifiable-auth-platform/
├─ docs/
├─ spec/
├─ engine/
├─ tui/
├─ observability/
├─ analysis/
├─ tests/
├─ fixtures/
├─ scripts/
└─ ops/
```

## 14. Naming Conventions

- Repository names, documentation names, and JSON files: `kebab-case`
- C identifiers and file names: `snake_case`
- Go packages: `lowercase`
- Go file names: `snake_case`
- Python modules and file names: `snake_case`
- Lean modules and types: `PascalCase`

## 15. Edge Cases

- `threshold = 0` is prohibited.
- Whether `unknown_user` and `wrong_password` are presented distinctly or uniformly is a UI-level policy decision.
- Empty passwords must be explicitly allowed or prohibited by specification.
- Storage corruption must result in `system_error`.

## 16. Failure Modes

The following architectural failures must be actively prevented:

- Divergence between the formal specification and the engine
- Leakage of authentication logic into the TUI
- Degradation of observability into unstructured logging
- Reimplementation of authentication logic inside the analysis layer
- Weakening of `WellFormed(state)` such that consistency collapses
- UI breakage caused by an unstable CLI contract

## 17. Verification Objective

The objective of this platform is not merely to provide authentication features. It is to establish an authentication implementation base in which:

- the specification is explicit,
- the implementation conforms to the specification,
- the tests verify the specification, and
- logs and analysis make behavior traceable.

Accordingly:

```text
verifiable-auth-platform = a verifiable implementation foundation for authentication state transitions
```

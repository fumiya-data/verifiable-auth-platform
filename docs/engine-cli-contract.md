# Engine CLI Contract

This document defines the stable command-line and JSON boundary exposed by the
C engine. The Go TUI and any future external tooling must treat this boundary
as the public interface, rather than reaching into engine storage files
directly.

For the higher-level system semantics, see
[`system-specification.md`](./system-specification.md). For the formal-to-C
traceability argument, see
[`spec-engine-comparison-table.md`](./spec-engine-comparison-table.md).

## Scope

The engine CLI exposes six commands:

- `register`
- `login`
- `change-password`
- `logout`
- `show-audit`
- `show-metrics`

The first four commands may mutate engine state. The last two commands are
read-only observability queries.

## Invocation Form

The general shape is:

```text
engine_cli <command> [options]
```

The engine accepts one positional command name and these options:

- `--data-dir <path>`
  - Optional. Defaults to `.engine-data`.
- `--login-id <value>`
  - Required for `register` and `login`.
- `--password-stdin`
  - Required for `register` and `login`. Reads one password line from stdin.
- `--old-password-stdin`
  - Required for `change-password`. Reads the first password line from stdin.
- `--new-password-stdin`
  - Required for `change-password`. Reads the next password line from stdin.

Unknown options, missing option values, missing required command arguments, or
an unknown command name produce an `invalid_request` JSON response and a usage
error exit code.

Plaintext password values are not accepted through argv. Requests using
`--password`, `--old-password`, or `--new-password` are rejected as
`invalid_request`. Stdin password transport is line based; the line ending is a
transport delimiter and is not part of the password value.

Login IDs and passwords must be non-empty, within the engine's configured
length bounds, and free of control characters. Login IDs also must not contain
TSV delimiters because they are stored in `users.tsv`, `session.txt`, and
`audit.log`.

## Persisted Files Behind `--data-dir`

The CLI uses these engine-managed files under the configured data directory:

- `users.tsv`
- `session.txt`
- `audit.log`

These files are implementation details of the engine. External consumers should
not treat them as the public contract. The public contract is the CLI response
JSON documented below.

## JSON Envelope

Every successful CLI invocation writes exactly one JSON object to `stdout` with
this envelope:

```json
{
  "ok": true,
  "result": "success",
  "data": null,
  "error": null
}
```

The envelope fields are stable:

- `ok`
  - Boolean. `true` only for successful domain outcomes.
- `result`
  - Stable machine-readable result code.
- `data`
  - Either `null` or a command-specific JSON object.
- `error`
  - `null` for successful outcomes.
  - `{"message":"..."}` for invalid requests or runtime failures.

The engine uses a deliberate distinction:

- Domain failures such as `duplicate`, `wrong_password`, or `locked_out` are
  still valid CLI executions.
- Runtime failures such as failed state loading are engine failures.

That distinction is reflected both in the `ok` field and in the process exit
code.

## Exit Codes

The engine exposes these stable process exit codes from
[`engine/include/cli/exit_codes.h`](../engine/include/cli/exit_codes.h):

- `0`
  - Command execution completed, even when `ok` is `false` in the JSON body.
- `1`
  - Runtime failure, such as failed path construction, persistence load,
    persistence save, or audit append.
- `2`
  - Invalid CLI request, such as unknown command, unknown option, or missing
    required arguments.

This policy lets clients distinguish:

- transport/runtime failure,
- request-shape failure, and
- domain-level authentication outcomes.

## Command Results

### `register`

Required options:

- `--login-id`
- `--password-stdin`

Stable `result` codes:

- `success`
- `duplicate`
- `system_error`
- `invalid_request`

Success and duplicate both return `data: null`.

Example success output:

```json
{"ok":true,"result":"success","data":null,"error":null}
```

Reference golden outputs:

- [`tests/golden/cli-json/register-success.json`](../tests/golden/cli-json/register-success.json)
- [`tests/golden/cli-json/register-duplicate.json`](../tests/golden/cli-json/register-duplicate.json)

### `login`

Required options:

- `--login-id`
- `--password-stdin`

Stable `result` codes:

- `success`
- `unknown_user`
- `locked_out`
- `wrong_password`
- `already_authenticated`
- `system_error`
- `invalid_request`

Successful and failed login responses both return `data: null`.

Reference golden outputs:

- [`tests/golden/cli-json/login-success.json`](../tests/golden/cli-json/login-success.json)
- [`tests/golden/cli-json/login-unknown-user.json`](../tests/golden/cli-json/login-unknown-user.json)
- [`tests/golden/cli-json/login-wrong-password.json`](../tests/golden/cli-json/login-wrong-password.json)
- [`tests/golden/cli-json/login-locked-out.json`](../tests/golden/cli-json/login-locked-out.json)
- [`tests/golden/cli-json/login-already-authenticated.json`](../tests/golden/cli-json/login-already-authenticated.json)

### `change-password`

Required options:

- `--old-password-stdin`
- `--new-password-stdin`

Stable `result` codes:

- `success`
- `unauthorized`
- `wrong_password`
- `system_error`
- `invalid_request`

All responses return `data: null`.

Reference golden outputs:

- [`tests/golden/cli-json/change-password-success.json`](../tests/golden/cli-json/change-password-success.json)
- [`tests/golden/cli-json/change-password-unauthorized.json`](../tests/golden/cli-json/change-password-unauthorized.json)

### `logout`

Required options:

- none

Stable `result` codes:

- `success`
- `system_error`
- `invalid_request`

All successful command completions return `data: null`.

### `show-audit`

Required options:

- none

Stable `result` codes:

- `success`
- `system_error`
- `invalid_request`

`data` shape:

```json
{
  "events": [
    {
      "timestamp": "2026-01-01T00:00:00Z",
      "event_type": "Register",
      "login_id": "alice",
      "result": "success"
    }
  ]
}
```

Stable event fields:

- `timestamp`
  - UTC ISO-8601 timestamp generated by the engine.
- `event_type`
  - One of `Register`, `LoginSuccess`, `LoginFailure`, `Lock`,
    `PasswordChange`, or `Logout`.
- `login_id`
  - Login identifier associated with the event.
- `result`
  - Stable machine-readable result code recorded for the event.

Reference sample:

- [`observability/audit/sample-events.json`](../observability/audit/sample-events.json)

### `show-metrics`

Required options:

- none

Stable `result` codes:

- `success`
- `system_error`
- `invalid_request`

`data` shape:

```json
{
  "login_success_count": 1,
  "login_failure_count": 2,
  "lockout_count": 1
}
```

Stable metric fields:

- `login_success_count`
- `login_failure_count`
- `lockout_count`

Reference sample:

- [`observability/metrics/sample-metrics.json`](../observability/metrics/sample-metrics.json)

## Domain Failure vs Runtime Failure

This distinction is a core part of the contract.

Domain failures:

- still produce valid JSON,
- still exit with code `0`, and
- communicate the auth outcome through `ok = false` and a stable `result`.

Runtime failures:

- still produce JSON,
- exit with code `1`, and
- use `result = "system_error"` or `result = "invalid_request"` depending on
  whether the failure was operational or caused by request shape.

## Contract Consumers

The current intended consumers are:

- the Go Bubble Tea TUI under [`tui/`](../tui/),
- future read-only analysis/reporting helpers, and
- contract and golden tests under [`tests/`](../tests/).

Those consumers should rely on:

- command names,
- stable option names,
- stdin secret transport for password values,
- JSON field names,
- stable `result` codes, and
- exit-code policy.

They should not rely on:

- `users.tsv`, `session.txt`, or `audit.log` file formats as a public API,
- internal engine struct layout, or
- internal helper function names.

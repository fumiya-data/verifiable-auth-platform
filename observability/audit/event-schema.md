# Audit Event Schema

The engine persists audit records as tab-separated lines in `audit.log` and
exposes them through the `show-audit` CLI command as JSON.

## Persisted Line Format

Each non-empty line is serialized as:

```text
timestamp<TAB>event_type<TAB>login_id<TAB>result
```

Example:

```text
2026-01-01T00:02:00Z	LoginFailure	alice	wrong_password
```

## JSON Envelope

`show-audit` returns the standard CLI envelope:

```json
{
  "ok": true,
  "result": "success",
  "data": {
    "events": [
      {
        "timestamp": "2026-01-01T00:02:00Z",
        "event_type": "LoginFailure",
        "login_id": "alice",
        "result": "wrong_password"
      }
    ]
  },
  "error": null
}
```

## Record Constraints

- `timestamp`
  - UTC, RFC3339-like engine format: `YYYY-MM-DDTHH:MM:SSZ`
- `event_type`
  - One of the stable names documented in `event-types.md`
- `login_id`
  - The login ID associated with the operation
  - May be an empty string for unauthenticated password-change or logout paths
- `result`
  - Stable machine-readable result code such as `success` or `wrong_password`

## Ordering

- Events are appended in file order.
- Consumers must preserve input order unless they explicitly document sorting.

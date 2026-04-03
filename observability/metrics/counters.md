# Counter Semantics

The engine exposes metrics through `show-metrics` as a JSON `data` payload:

```json
{
  "login_success_count": 1,
  "login_failure_count": 2,
  "lockout_count": 1
}
```

All counters are monotonic with respect to appended audit history. Recomputing
metrics from the same audit event sequence must yield the same values.

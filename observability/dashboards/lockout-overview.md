# Lockout Overview Dashboard

Primary questions:

- How often are new lockouts occurring?
- Which login IDs are repeatedly locking out?
- Are lockouts clustered in a narrow time window?

Suggested panels:

1. `lockout_count`
2. Count of `Lock` events by login ID
3. Time histogram of `Lock` events

Primary filter:

- `event_type == "Lock"`

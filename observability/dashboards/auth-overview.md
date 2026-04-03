# Auth Overview Dashboard

Primary questions:

- Are users authenticating successfully?
- Are login failures rising?
- Are failures concentrated in a small set of login IDs?

Suggested panels:

1. `login_success_count`
2. `login_failure_count`
3. Success-to-failure ratio over the sampled audit window
4. Top login IDs by failure count

Primary data sources:

- `show-metrics`
- `show-audit`

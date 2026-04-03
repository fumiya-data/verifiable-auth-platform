from __future__ import annotations

from pathlib import Path

from common import compute_metrics_from_events, load_audit_events, load_metrics


def main() -> int:
    root = Path(__file__).resolve().parents[2]
    audit_json = root / "observability" / "audit" / "sample-events.json"
    audit_log = root / "tests" / "golden" / "audit" / "sample-audit-output.txt"
    fixture_audit_log = root / "fixtures" / "logs" / "sample-audit.log"
    metrics_json = root / "observability" / "metrics" / "sample-metrics.json"

    events_from_json = load_audit_events(audit_json)
    events_from_log = load_audit_events(audit_log)
    events_from_fixture_log = load_audit_events(fixture_audit_log)
    metrics = load_metrics(metrics_json)
    derived_from_json = compute_metrics_from_events(events_from_json)
    derived_from_log = compute_metrics_from_events(events_from_log)
    derived_from_fixture_log = compute_metrics_from_events(events_from_fixture_log)

    if events_from_json != events_from_log:
        raise SystemExit("fixture mismatch: JSON and TSV audit fixtures differ")
    if events_from_json != events_from_fixture_log:
        raise SystemExit("fixture mismatch: observability audit JSON and fixtures sample log differ")
    if metrics != derived_from_json:
        raise SystemExit("fixture mismatch: metrics JSON does not match audit-derived metrics")
    if metrics != derived_from_log:
        raise SystemExit("fixture mismatch: metrics JSON does not match log-derived metrics")
    if metrics != derived_from_fixture_log:
        raise SystemExit("fixture mismatch: metrics JSON does not match fixtures sample log")

    print("fixture consistency OK")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

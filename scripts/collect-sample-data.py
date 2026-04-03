from __future__ import annotations

from pathlib import Path
import json
import sys

ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from analysis.scripts.common import compute_metrics_from_events, load_audit_events


def main() -> int:
    audit_log = ROOT / "tests" / "golden" / "audit" / "sample-audit-output.txt"
    fixture_audit_log = ROOT / "fixtures" / "logs" / "sample-audit.log"
    audit_json = ROOT / "observability" / "audit" / "sample-events.json"
    metrics_json = ROOT / "observability" / "metrics" / "sample-metrics.json"

    events = load_audit_events(audit_log)
    audit_payload = {"ok": True, "result": "success", "data": {"events": events}, "error": None}
    metrics_payload = {"ok": True, "result": "success", "data": compute_metrics_from_events(events), "error": None}

    fixture_audit_log.write_text(audit_log.read_text(encoding="utf-8"), encoding="utf-8")
    audit_json.write_text(json.dumps(audit_payload, indent=2) + "\n", encoding="utf-8")
    metrics_json.write_text(json.dumps(metrics_payload, indent=2) + "\n", encoding="utf-8")
    print("sample observability data refreshed")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

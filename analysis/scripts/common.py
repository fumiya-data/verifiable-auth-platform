from __future__ import annotations

from collections import Counter
from pathlib import Path
import json
from typing import Any


def read_json(path: Path) -> Any:
    return json.loads(path.read_text(encoding="utf-8"))


def normalize_audit_events(payload: Any) -> list[dict[str, Any]]:
    if isinstance(payload, dict):
        if "data" in payload and isinstance(payload["data"], dict) and "events" in payload["data"]:
            payload = payload["data"]["events"]
        elif "events" in payload:
            payload = payload["events"]

    if not isinstance(payload, list):
        raise ValueError("audit payload did not contain an events list")

    events: list[dict[str, Any]] = []
    for event in payload:
        if not isinstance(event, dict):
            raise ValueError("audit event must be an object")
        events.append(
            {
                "timestamp": str(event.get("timestamp", "")),
                "event_type": str(event.get("event_type", "")),
                "login_id": str(event.get("login_id", "")),
                "result": str(event.get("result", "")),
            }
        )
    return events


def load_audit_events(path_like: str | Path) -> list[dict[str, Any]]:
    path = Path(path_like)
    text = path.read_text(encoding="utf-8").strip()
    if not text:
        return []

    if path.suffix.lower() in {".log", ".txt"} and "\t" in text:
        events = []
        for raw_line in text.splitlines():
            line = raw_line.strip()
            if not line:
                continue
            timestamp, event_type, login_id, result = line.split("\t", 3)
            events.append(
                {
                    "timestamp": timestamp,
                    "event_type": event_type,
                    "login_id": login_id,
                    "result": result,
                }
            )
        return events

    return normalize_audit_events(json.loads(text))


def normalize_metrics(payload: Any) -> dict[str, int]:
    if isinstance(payload, dict) and "data" in payload and isinstance(payload["data"], dict):
        payload = payload["data"]

    if not isinstance(payload, dict):
        raise ValueError("metrics payload must be an object")

    return {
        "login_success_count": int(payload.get("login_success_count", 0)),
        "login_failure_count": int(payload.get("login_failure_count", 0)),
        "lockout_count": int(payload.get("lockout_count", 0)),
    }


def load_metrics(path_like: str | Path) -> dict[str, int]:
    return normalize_metrics(read_json(Path(path_like)))


def compute_metrics_from_events(events: list[dict[str, Any]]) -> dict[str, int]:
    login_success_count = 0
    login_failure_count = 0
    lockout_count = 0

    for event in events:
        event_type = event["event_type"]
        result = event["result"]

        if event_type == "LoginSuccess":
            login_success_count += 1

        counts_as_failure = False
        if event_type == "Lock":
            counts_as_failure = True
        elif event_type == "LoginFailure" and result != "already_authenticated":
            counts_as_failure = True

        if counts_as_failure:
            login_failure_count += 1

        if event_type == "Lock":
            lockout_count += 1

    return {
        "login_success_count": login_success_count,
        "login_failure_count": login_failure_count,
        "lockout_count": lockout_count,
    }


def summarize_audit_events(events: list[dict[str, Any]]) -> dict[str, Any]:
    by_event_type = Counter(event["event_type"] for event in events)
    by_result = Counter(event["result"] for event in events)
    by_login_id = Counter(event["login_id"] for event in events if event["login_id"])

    return {
        "event_count": len(events),
        "first_timestamp": events[0]["timestamp"] if events else None,
        "last_timestamp": events[-1]["timestamp"] if events else None,
        "by_event_type": dict(sorted(by_event_type.items())),
        "by_result": dict(sorted(by_result.items())),
        "by_login_id": dict(sorted(by_login_id.items())),
        "derived_metrics": compute_metrics_from_events(events),
    }


def emit_json(data: Any) -> None:
    print(json.dumps(data, indent=2, sort_keys=True))

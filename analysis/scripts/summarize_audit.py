from __future__ import annotations

import argparse

from common import emit_json, load_audit_events, summarize_audit_events


def main() -> int:
    parser = argparse.ArgumentParser(description="Summarize audit TSV or JSON payloads.")
    parser.add_argument("input", help="Path to audit.log, sample JSON, or show-audit JSON output.")
    args = parser.parse_args()

    events = load_audit_events(args.input)
    emit_json(summarize_audit_events(events))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

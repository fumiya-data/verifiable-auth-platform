from __future__ import annotations

import argparse

from common import emit_json, load_metrics


def main() -> int:
    parser = argparse.ArgumentParser(description="Normalize a metrics JSON payload.")
    parser.add_argument("input", help="Path to sample-metrics or show-metrics JSON output.")
    args = parser.parse_args()

    metrics = load_metrics(args.input)
    total_attempts = metrics["login_success_count"] + metrics["login_failure_count"]
    summary = {
        **metrics,
        "total_login_attempts_counted": total_attempts,
        "success_ratio": (metrics["login_success_count"] / total_attempts) if total_attempts else None,
        "failure_ratio": (metrics["login_failure_count"] / total_attempts) if total_attempts else None,
    }
    emit_json(summary)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

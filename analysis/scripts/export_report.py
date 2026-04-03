from __future__ import annotations

import argparse
from pathlib import Path

from common import load_audit_events, load_metrics, summarize_audit_events

try:
    from jinja2 import Environment, FileSystemLoader
except ImportError:  # pragma: no cover - exercised only in minimal environments
    Environment = None
    FileSystemLoader = None


def render_template(template_name: str, context: dict[str, object]) -> str:
    if Environment is None or FileSystemLoader is None:
        if template_name == "audit_report.md.j2":
            audit = context["audit"]
            return "\n".join(
                [
                    "# Audit Report",
                    "",
                    f"- Total events: {audit['event_count']}",
                    f"- First timestamp: {audit['first_timestamp'] or 'n/a'}",
                    f"- Last timestamp: {audit['last_timestamp'] or 'n/a'}",
                ]
            )
        metrics = context["metrics"]
        return "\n".join(
            [
                "# Metrics Report",
                "",
                f"- Login success count: {metrics['login_success_count']}",
                f"- Login failure count: {metrics['login_failure_count']}",
                f"- Lockout count: {metrics['lockout_count']}",
            ]
        )
    template_dir = Path(__file__).resolve().parent.parent / "templates"
    env = Environment(loader=FileSystemLoader(str(template_dir)), autoescape=False, trim_blocks=True, lstrip_blocks=True)
    return env.get_template(template_name).render(**context)


def main() -> int:
    parser = argparse.ArgumentParser(description="Render Markdown reports from audit and metrics artifacts.")
    parser.add_argument("--audit", required=True, help="Path to audit TSV or JSON data.")
    parser.add_argument("--metrics", required=True, help="Path to metrics JSON data.")
    parser.add_argument("--report", choices=("audit", "metrics", "both"), default="both")
    parser.add_argument("--output", help="Optional file to write. Defaults to stdout.")
    args = parser.parse_args()

    events = load_audit_events(args.audit)
    audit_summary = summarize_audit_events(events)
    metrics = load_metrics(args.metrics)

    parts: list[str] = []
    if args.report in {"audit", "both"}:
        parts.append(render_template("audit_report.md.j2", {"audit": audit_summary}))
    if args.report in {"metrics", "both"}:
        parts.append(render_template("metrics_report.md.j2", {"metrics": metrics}))

    report = "\n\n".join(parts).strip() + "\n"
    if args.output:
        Path(args.output).write_text(report, encoding="utf-8")
    else:
        print(report, end="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

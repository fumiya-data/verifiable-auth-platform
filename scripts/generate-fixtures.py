from __future__ import annotations

from pathlib import Path
import subprocess
import sys


def main() -> int:
    root = Path(__file__).resolve().parents[1]
    output_dir = root / "analysis" / "output"
    output_dir.mkdir(parents=True, exist_ok=True)

    command = [
        sys.executable,
        str(root / "analysis" / "scripts" / "export_report.py"),
        "--audit",
        str(root / "observability" / "audit" / "sample-events.json"),
        "--metrics",
        str(root / "observability" / "metrics" / "sample-metrics.json"),
        "--report",
        "both",
        "--output",
        str(output_dir / "sample-report.md"),
    ]
    subprocess.run(command, check=True)
    print(f"wrote {output_dir / 'sample-report.md'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

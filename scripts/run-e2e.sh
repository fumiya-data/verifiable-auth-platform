#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

"${ROOT_DIR}/scripts/run-spec-check.sh"
"${ROOT_DIR}/scripts/run-engine-tests.sh"

cd "${ROOT_DIR}/tui"
go test ./...

cd "${ROOT_DIR}"
python analysis/scripts/check_fixture_consistency.py

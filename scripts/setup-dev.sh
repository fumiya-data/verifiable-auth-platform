#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

command -v cmake >/dev/null
command -v go >/dev/null
command -v python >/dev/null
command -v lake >/dev/null

python -m pip install -r "${ROOT_DIR}/analysis/requirements.txt"

echo "development dependencies available"

#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${ROOT_DIR}/engine/.build"

run_with_cmake() {
  cmake -S "${ROOT_DIR}/engine" -B "${BUILD_DIR}"
  cmake --build "${BUILD_DIR}"
  ctest --test-dir "${BUILD_DIR}" --output-on-failure
}

run_with_make() {
  make -C "${ROOT_DIR}/engine" test
}

if command -v cmake >/dev/null 2>&1 && command -v ctest >/dev/null 2>&1; then
  if run_with_cmake; then
    exit 0
  fi
  echo "cmake-based engine verification failed; attempting make-based fallback" >&2
fi

if command -v make >/dev/null 2>&1; then
  run_with_make
  exit 0
fi

echo "no supported engine test toolchain found (expected cmake+ctest or make)" >&2
exit 1

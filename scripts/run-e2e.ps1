$ErrorActionPreference = "Stop"

$RootDir = Split-Path -Parent $PSScriptRoot

& (Join-Path $PSScriptRoot "run-spec-check.ps1")
& (Join-Path $PSScriptRoot "run-engine-tests.ps1")

Push-Location (Join-Path $RootDir "tui")
try {
    go test ./...
} finally {
    Pop-Location
}

Push-Location $RootDir
try {
    python analysis/scripts/check_fixture_consistency.py
} finally {
    Pop-Location
}

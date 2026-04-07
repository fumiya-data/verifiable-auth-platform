$ErrorActionPreference = "Stop"

$RootDir = Split-Path -Parent $PSScriptRoot

Push-Location (Join-Path $RootDir "tui")
try {
    go run ./cmd/auth-tui @args
} finally {
    Pop-Location
}

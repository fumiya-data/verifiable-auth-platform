$ErrorActionPreference = "Stop"

$RootDir = Split-Path -Parent $PSScriptRoot
$ElanBin = Join-Path $HOME ".elan\bin"

if (Test-Path $ElanBin) {
    $env:PATH = "$ElanBin;$env:PATH"
}

Push-Location (Join-Path $RootDir "spec")
try {
    lake build
} finally {
    Pop-Location
}

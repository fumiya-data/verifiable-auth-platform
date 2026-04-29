$ErrorActionPreference = "Stop"

$RootDir = Split-Path -Parent $PSScriptRoot

function Invoke-NativeCommand {
    param(
        [Parameter(Mandatory = $true)]
        [string] $FilePath,

        [string[]] $ArgumentList = @()
    )

    & $FilePath @ArgumentList
    if ($LASTEXITCODE -ne 0) {
        throw "command failed with exit code ${LASTEXITCODE}: $FilePath $($ArgumentList -join ' ')"
    }
}

& (Join-Path $PSScriptRoot "run-spec-check.ps1")
& (Join-Path $PSScriptRoot "run-engine-tests.ps1")

Push-Location (Join-Path $RootDir "tui")
try {
    Invoke-NativeCommand "go" @("test", "./...")
} finally {
    Pop-Location
}

Push-Location $RootDir
try {
    Invoke-NativeCommand "python" @("analysis/scripts/check_fixture_consistency.py")
} finally {
    Pop-Location
}

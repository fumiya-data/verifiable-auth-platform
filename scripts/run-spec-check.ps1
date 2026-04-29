$ErrorActionPreference = "Stop"

$RootDir = Split-Path -Parent $PSScriptRoot
$ElanBin = Join-Path $HOME ".elan\bin"

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

if (Test-Path $ElanBin) {
    $env:PATH = "$ElanBin;$env:PATH"
}

Push-Location (Join-Path $RootDir "spec")
try {
    Invoke-NativeCommand "lake" @("build")
} finally {
    Pop-Location
}

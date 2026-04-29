$ErrorActionPreference = "Stop"

$RootDir = Split-Path -Parent $PSScriptRoot
$EngineDir = Join-Path $RootDir "engine"
$BuildDir = Join-Path $EngineDir ".build"

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

$cmake = Get-Command cmake -ErrorAction SilentlyContinue
$ctest = Get-Command ctest -ErrorAction SilentlyContinue

if ($cmake -and $ctest) {
    try {
        Invoke-NativeCommand $cmake.Source @("-S", $EngineDir, "-B", $BuildDir)
        Invoke-NativeCommand $cmake.Source @("--build", $BuildDir)
        Invoke-NativeCommand $ctest.Source @("--test-dir", $BuildDir, "--output-on-failure")
        return
    } catch {
        Write-Warning "cmake-based engine verification failed; attempting make-based fallback"
    }
}

$mingwMake = Get-Command mingw32-make -ErrorAction SilentlyContinue
if ($mingwMake) {
    Invoke-NativeCommand $mingwMake.Source @("-C", $EngineDir, "test")
    return
}

$make = Get-Command make -ErrorAction SilentlyContinue
if ($make) {
    Invoke-NativeCommand $make.Source @("-C", $EngineDir, "test")
    return
}

throw "no supported engine test toolchain found (expected cmake+ctest, mingw32-make, or make)"

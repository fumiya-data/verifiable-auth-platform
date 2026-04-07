$ErrorActionPreference = "Stop"

$RootDir = Split-Path -Parent $PSScriptRoot
$EngineDir = Join-Path $RootDir "engine"
$BuildDir = Join-Path $EngineDir ".build"

$cmake = Get-Command cmake -ErrorAction SilentlyContinue
$ctest = Get-Command ctest -ErrorAction SilentlyContinue

if ($cmake -and $ctest) {
    try {
        cmake -S $EngineDir -B $BuildDir
        cmake --build $BuildDir
        ctest --test-dir $BuildDir --output-on-failure
        return
    } catch {
        Write-Warning "cmake-based engine verification failed; attempting make-based fallback"
    }
}

$mingwMake = Get-Command mingw32-make -ErrorAction SilentlyContinue
if ($mingwMake) {
    & $mingwMake.Source -C $EngineDir test
    return
}

$make = Get-Command make -ErrorAction SilentlyContinue
if ($make) {
    & $make.Source -C $EngineDir test
    return
}

throw "no supported engine test toolchain found (expected cmake+ctest, mingw32-make, or make)"

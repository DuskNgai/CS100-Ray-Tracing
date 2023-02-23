# run-debug.ps1  Copyright (C) 2023  Haizhao Dai
#
# This program comes with ABSOLUTELY NO WARRANTY.
# This is free software, and you are welcome to redistribute it
# under certain conditions.

function info() {
    Write-Host "$args" -ForegroundColor Blue
}

info "[script] Generating image.ppm..."
.\"..\windows-build\x64\Debug\CS100-Ray-Tracing.exe" 960 540 20 "..\result\image.ppm"
info "[script] Converting image.ppm to image.png..."
python "ppm-to-png.py" "../result/image.ppm"

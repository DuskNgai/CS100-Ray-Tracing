# run-debug.ps1  Copyright (C) 2023  Haizhao Dai
#
# This program comes with ABSOLUTELY NO WARRANTY.
# This is free software, and you are welcome to redistribute it
# under certain conditions.

function info() {
    Write-Host "$args" -ForegroundColor Blue
}

info "[script] Compiling..."
gcc (Get-ChildItem ..\src\*.c) -o "..\windows-build\Debug\CS100-Ray-Tracing" -I "..\include" -g -std=c17 -Wall -Wextra -Wpedantic -Werror -lm

info "[script] Generating image.ppm..."
.\"..\windows-build\Debug\CS100-Ray-Tracing.exe" | out-file "..\result\image.ppm" -encoding utf8

info "[script] Converting image.ppm to image.png..."
python "ppm-to-png.py" "..\result\image.ppm"

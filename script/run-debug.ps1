# run-debug.ps1  Copyright (C) 2023  Haizhao Dai
#
# This program comes with ABSOLUTELY NO WARRANTY.
# This is free software, and you are welcome to redistribute it
# under certain conditions.

echo "[script] Generating image.ppm..."
.\..\windows-build\x64\Debug\CS100-Ray-Tracing.exe | out-file ..\result\image.ppm -encoding utf8
echo "[script] Converting image.ppm to image.png..."
python ppm-to-png.py ../result/image.ppm

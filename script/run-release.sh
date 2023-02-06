# run-release.sh  Copyright (C) 2023  Haizhao Dai
#
# This program comes with ABSOLUTELY NO WARRANTY.
# This is free software, and you are welcome to redistribute it
# under certain conditions.

echo "[script] Compling..."
gcc ../src/main.c -o ../linux-build/Debug/CS100-Ray-Tracing -O3 -march=native -Wall -Wextra -Wpedantic -Werror -std=C11
echo "[script] Generating image.ppm..."
./../linux-build/Release/CS100-Ray-Tracing > ../result/image.ppm
echo "[script] Converting image.ppm to image.png..."
python ppm-to-png.py ../result/image.ppm

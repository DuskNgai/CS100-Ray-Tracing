# run-debug.sh  Copyright (C) 2023  Haizhao Dai
#
# This program comes with ABSOLUTELY NO WARRANTY.
# This is free software, and you are welcome to redistribute it
# under certain conditions.

function info() {
    echo -e "\e[34m""$@""\e[0m"
}

function error() {
    echo -e "\e[31m""$@""\e[0m" >&2
}

function run() {
    "$@" || { error "Error in executing: $@, got $?"; exit; }
}

# Create a directory that contains the binary files.
bin_dir_name="../linux-build/Debug"
mkdir -p "$bin_dir_name"

# Create a directory that contains the result files.
result_dir_name="../result"
mkdir -p "$result_dir_name"

info "[script] Compiling..."
run g++ "../src/"*.cpp "../src/geometry/"*.cpp \
    -o "../linux-build/Debug/CS100-Ray-Tracing"  \
    -I "../include"                              \
    -g -std=c17 -Wall -Wextra -Wpedantic -Werror \
    -lm

info "[script] Generating image.ppm..."
run ./"../linux-build/Debug/CS100-Ray-Tracing" 960 540 20 "..\result\image.ppm" > "../result/image.ppm"

info "[script] Converting image.ppm to image.png..."
run python "ppm-to-png.py" "../result/image.ppm"

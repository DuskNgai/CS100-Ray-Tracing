# run-debug.ps1  Copyright (C) 2023  Haizhao Dai and Zhonghan Zhang
#
# This program comes with ABSOLUTELY NO WARRANTY.
# This is free software, and you are welcome to redistribute it
# under certain conditions.

function info() {
    Write-Host "$args" -ForegroundColor Blue
}

function error() {
    Write-Host "[ERROR] $args" -ForegroundColor Red
}

function handle_error($command) {
    if(-not $?) {
        error "Error occurs when executing $($command)"
        exit 1;
    }
}

function make_dir($path) {
    if(-not (Test-Path $path)) {
        mkdir $path | Out-Null
    }
}


$current_directory_is_script = (pwd).Path -match 'script$'
if(-not $current_directory_is_script) {
    error "Working directory error."
    info "Please switch to 'script' directory and run this srcipt."
    info "Try to use command 'cd ./script/'."
    exit 1;
}

$bin_dir_name = "../windows-build/Debug"
make_dir $bin_dir_name

$result_dir_name = "../result"
make_dir $result_dir_name

$build_executable_name = "CS100-Ray-Tracing.exe"
info "[script] Compiling..."
gcc (Get-ChildItem ..\src\*.c) -o "$($bin_dir_name)/$($build_executable_name)" -I $include_dir_name -g -std=c17 -Wall -Wextra -Wpedantic -Werror -lm
handle_error "gcc"

info "[script] Generating image.ppm..."
&"$($bin_dir_name)/$($build_executable_name)" | Out-File -FilePath "$($result_dir_name)\image.ppm" -Encoding utf8
handle_error "$($bin_dir_name)/$($build_executable_name)"

info "[script] Converting image.ppm to image.png..."
python ".\ppm-to-png.py" "$($result_dir_name)\image.ppm"
handle_error "python"

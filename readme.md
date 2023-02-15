# Outline of Introduction to Programming (CS100)

This project is intended for recitation of Introduction to Programming (CS100) at Shanghaitech. To help students understand the basic concepts of programming, we will use C and C++ to implement a simple ray tracer. During the process, we will cover the topics and concepts of programming C and C++ that related to the course on that week. The project is based on the book [Ray Tracing in One Weekend](https://raytracing.github.io/).

## Usage

### Visual Studio

For students who uses Visual Studio, we recommend you follows the instructions below:

#### Create the Project

1. Create a new Visual Studio project named `CS100-Ray-Tracing`.
2. Create a `windows-build` directory and drag all the projection files into it.
3. Create a `scripts` directory which stores the scripts for building the project.
4. Create a `src` directory which stores the source files.
5. Create a `include` directory which stores the header files.
6. Create a `main.c` file in the `src` directory. Add it to projected managed source files.

#### Run the Project

1. After done writing the code, make the project.
2. Go to the `scripts` directory and run `run-debug.ps1` in `PowerShell`.

### GCC/Clang

For students who uses GCC/Clang, we recommend you follows the instructions below:

If you are in Windows, you can
1. [recommanded] use `bash` contained in [git](https://git-scm.com/downloads).
2. use [WSL](https://docs.microsoft.com/en-us/windows/wsl/install-win10).

for running the shell scripts.

#### Create the Project

1. Create a new directory named `CS100-Ray-Tracing`.
2. Create a `linux-build` directory.
3. Create a `scripts` directory which stores the scripts for building the project.
4. Create a `src` directory which stores the source files.
5. Create a `include` directory which stores the header files.
6. Create a `main.c` file in the `src` directory.

#### Run the Project

1. [Windows only] Open the `git bash` and go to the directory where you want to store the project. Also, if you have add `git` into the `PATH` environment variable, you can type `bash` to open bash in your vscode terminal.
2. Go into scripts directory and run one of the following scripts:
    1. `run-debug.sh` by `./run-debug.sh`.
    2. `run-release.sh` by `./run-release.sh`.

    which is
    ```bash
    cd scripts
    ./run-debug.sh # or ./run-release.sh
    ```

## Weekly Schedule

### Week 1

1. Choosing the recitation class.

### Week 2

1. Introduction to C and C++.
2. Compiling and running a program through VS2022/GCC/Clang.
3. Introduction to the project.
4. Establishing the project environment.

## References

1. [Ray Tracing in One Weekend](https://raytracing.github.io/)
2. [cppreference](https://en.cppreference.com/w/)
3. 21st Century C
4. C++ Primer
5. C++ Template: The Complete Guide

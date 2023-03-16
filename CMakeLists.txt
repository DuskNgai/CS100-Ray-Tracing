cmake_minimum_required(VERSION 3.20)

# Set the project name.
set(PROJECT_NAME "CS100-Ray-Tracing")
project(${PROJECT_NAME})

# Set language standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE "Release")

# Set compiler flags.
if(MSVC)
    set(CMAKE_CXX_FLAGS "/_CRT_SECURE_NO_WARNINGS")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wpedantic -Wno-missing-field-initializers")
endif()

# Third libraries' settings, from their project readme.
set(JSON_BuildTests OFF CACHE INTERNAL "")
set(JSON_Install OFF CACHE INTERNAL "")

# Third libraries.
add_subdirectory("dependencies/eigen")
add_subdirectory("dependencies/nlohmann")

# Set the include directories.
set(CS100_RAY_TRACING_INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/args
    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/eigen
    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/nlohmann/include
    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/stb
)

# Set the linking libraries.
set(CS100_RAY_TRACING_LINKING_LIBRARIES
    eigen
    nlohmann_json::nlohmann_json
)

# Set the source files.
aux_source_directory(src SRC_FILES)
aux_source_directory(src/geometry SRC_FILES)
aux_source_directory(src/material SRC_FILES)
aux_source_directory(src/utils SRC_FILES)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CS100_RAY_TRACING_INCLUDE_DIRECTORIES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CS100_RAY_TRACING_LINKING_LIBRARIES})

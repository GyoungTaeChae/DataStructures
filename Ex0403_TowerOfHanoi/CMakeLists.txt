# Set the minimum required version of CMake.
cmake_minimum_required(VERSION 3.16)

# Set the project name.
project(Ex0403_TowerOfHanoi)

# Specify the include directories.
# The `shared` directory is included for accessing the shared header files.
include_directories(${CMAKE_SOURCE_DIR}/../shared)

# Add the executable target. This includes the source file for this example.
add_executable(Ex0403_TowerOfHanoi Ex0403_TowerOfHanoi.cpp)

set_target_properties(Ex0403_TowerOfHanoi PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
)
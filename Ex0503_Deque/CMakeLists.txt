# Set the minimum required version of CMake.
cmake_minimum_required(VERSION 3.16)

# Set the project name.
project(Ex0503_Deque)

# Specify the include directories.
# The `shared` directory is included for accessing the shared header files.
include_directories(${CMAKE_SOURCE_DIR}/../shared)

# Add the executable target. This includes the source file for this example.
add_executable(Ex0503_Deque Ex0503_Deque.cpp)

set_target_properties(Ex0503_Deque PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
)
# 최소 요구 CMake 버전 설정
cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름 및 버전 설정
project(Matrix VERSION 1.0)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 실행 파일을 생성할 소스 파일들을 지정
add_executable(Matrix
    Ex0304_Matrix.cpp
    Matrix.cpp
)

# 헤더 파일 경로를 포함하도록 지정
target_include_directories(Matrix PUBLIC "${PROJECT_SOURCE_DIR}")

# 실행 파일의 출력 디렉토리 설정
set_target_properties(Matrix PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
)

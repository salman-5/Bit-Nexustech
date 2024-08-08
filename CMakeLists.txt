cmake_minimum_required(VERSION 3.10)

project(bit VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
add_executable(bit
    src/main.cpp
    src/interactive_terminal.cpp
    src/Bit.cpp
)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)




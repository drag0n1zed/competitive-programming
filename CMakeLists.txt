cmake_minimum_required(VERSION 4.0)
project(CompetitiveProgramming)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(scratchpad scratchpad.cpp)

# Optimization flags
target_compile_options(scratchpad PRIVATE -O2 -Wall -Wextra)

# Find include/bits/stdc++.h AND define LOCAL macro
target_compile_definitions(scratchpad PRIVATE
        PROJECT_ROOT="${CMAKE_SOURCE_DIR}"
        LOCAL
)
cmake_minimum_required(VERSION 4.0)
project(CompetitiveProgramming)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(scratchpad scratchpad.cpp)

# Flags
target_compile_options(scratchpad PRIVATE -O0 -Wall -Wextra)

# Find include/bits/stdc++.h
target_include_directories(scratchpad PRIVATE ${CMAKE_SOURCE_DIR}/include)

# define LOCAL macro and project root
target_compile_definitions(scratchpad PRIVATE LOCAL)
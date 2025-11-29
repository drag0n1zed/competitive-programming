cmake_minimum_required(VERSION 4.0)
project(CompetitiveProgramming)

set(CMAKE_CXX_STANDARD 20)

# Optimization flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra")

add_compile_definitions(PROJECT_ROOT="${CMAKE_SOURCE_DIR}")

add_compile_definitions(LOCAL)

# Find include/bits/stdc++.h
include_directories(include)

# Find every .cpp file
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
foreach (source ${sources})
    get_filename_component(name ${source} NAME_WE)
    add_executable(${name} ${source}
            include/bits/stdc++.h)
endforeach ()
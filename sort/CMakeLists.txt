cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
project(sort CXX)
add_executable(sort "main.cpp" "../core/methods.cpp" "../core/options.cpp" "sort_types.cpp")
target_compile_options(sort
    PRIVATE
    # -ftime-trace

)
target_include_directories(sort
    PUBLIC
    "./"
    "../core/"
)

cmake_minimum_required(VERSION 3.15)
project(sort CXX)
add_executable(sort "main.cpp")
target_compile_options(sort
    PRIVATE
    # -ftime-trace
)

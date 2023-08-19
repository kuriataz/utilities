cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
project(uniq CXX)
add_executable(uniq "main.cpp" "uniq.cpp" "../core/options.cpp" "../core/methods.cpp")
target_compile_options(uniq
    PRIVATE
    # -ftime-trace

)
target_include_directories(uniq
    PUBLIC
    "./"
    "../core/"
)
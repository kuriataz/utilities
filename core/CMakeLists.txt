cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(uniq CXX)
add_executable(uniq "../uniq/main.cpp" "../uniq/uniq.cpp" "options.cpp" "methods.cpp" "../sort/sort_types.cpp")
target_compile_options(uniq
    PRIVATE
    # -ftime-trace

)
target_include_directories(uniq
    PUBLIC
    "./"
    "../uniq/"
    "../sort/"
)

project(sort CXX)
add_executable(sort "../sort/main.cpp" "methods.cpp" "options.cpp" "../sort/sort_types.cpp")
target_compile_options(sort
    PRIVATE
    # -ftime-trace

)
target_include_directories(sort
    PUBLIC
    "./"
    "../sort/"
)
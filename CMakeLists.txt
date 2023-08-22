cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_BUILD_TYPE Debug)
project(utilities CXX)

add_library(core
    "core/array.hpp"
    "core/expected.hpp"
    "core/methods.cpp"
    "core/methods.hpp"
    "core/options.hpp"
    "core/options.cpp"
)

target_include_directories(core
    PUBLIC
    "core/"
)

add_executable(uniq
    "uniq/main.cpp"
    "uniq/uniq.hpp"
    "uniq/uniq.cpp"
)
target_compile_options(uniq
    PRIVATE
    # -ftime-trace
)
target_include_directories(uniq
    PRIVATE
    "uniq/"
)
target_link_libraries(uniq PRIVATE core)

add_executable(sort
    "sort/main.cpp"
    "sort/sort.hpp"
    "sort/sort.cpp"
)
target_compile_options(sort
    PRIVATE
    # -ftime-trace
)
target_include_directories(sort
    PRIVATE
    "sort/"
)
target_link_libraries(sort PRIVATE core)

add_executable(dict
    "dict/main.cpp"
    "dict/dict.hpp"
    "dict/dict.cpp"
)
target_compile_options(dict
    PRIVATE
    # -ftime-trace
)
target_include_directories(dict
    PRIVATE
    "dict/"
)
target_link_libraries(dict PRIVATE core)
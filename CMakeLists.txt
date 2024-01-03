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
    "core/list.hpp"
    "core/iterator.hpp"
)
target_include_directories(core
PUBLIC
"core/"
)

add_subdirectory(mariadb-connector-cpp)


# set_target_properties(mariadb PROPERTIES LINKER_LANGUAGE CXX)

add_executable(uniq
    "uniq/main.cpp"
    "uniq/uniq.hpp"
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
    "dict/db_interface.hpp"
    "dict/shell.hpp"
    "dict/shell.cpp"
    "dict/pretty_print.hpp"
    "dict/pretty_print.cpp"
)
target_compile_options(dict
    PRIVATE
    # -ftime-trace
)
target_include_directories(dict
    PRIVATE
    "dict/"
    "sort/"
    "uniq/"
)
target_link_libraries(dict PRIVATE core include)



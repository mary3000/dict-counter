cmake_minimum_required(VERSION 3.20)
project(dict_counter)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(third_party)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)

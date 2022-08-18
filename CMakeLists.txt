cmake_minimum_required(VERSION 3.20)
project(dict_counter)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(third_party)

add_executable (dict_counter main.cpp)
target_link_libraries(dict_counter fmt::fmt)


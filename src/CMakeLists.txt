cmake_minimum_required(VERSION 3.20)

file(GLOB_RECURSE LIB_CXX_SOURCES dict/*.cpp)
file(GLOB_RECURSE LIB_HEADERS dict/*.hpp)
set(LIB_SOURCES dict/*.cpp dict/*.hpp)
add_library(dict STATIC ${LIB_CXX_SOURCES} ${LIB_HEADERS})
target_include_directories(dict PUBLIC .)

add_executable(dict_counter main.cpp)
target_link_libraries(dict_counter fmt::fmt dict)

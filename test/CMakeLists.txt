cmake_minimum_required(VERSION 3.20)

add_executable(
        dict_test
        test.cpp
)
target_link_libraries(
        dict_test
        GTest::gtest_main
        dict
)

include(GoogleTest)
gtest_discover_tests(dict_test)

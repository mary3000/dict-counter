cmake_minimum_required(VERSION 3.20)

include(FetchContent)

# --------------------------------------------------------------------

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 9.0.0
)

set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(fmt)

# --------------------------------------------------------------------

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# --------------------------------------------------------------------

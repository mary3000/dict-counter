cmake_minimum_required(VERSION 3.20)

include(FetchContent)

# --------------------------------------------------------------------

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 36c23bd5fd92ad846cdbf8b7ecd6a87b7d3efae4
)

set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(fmt)

# --------------------------------------------------------------------

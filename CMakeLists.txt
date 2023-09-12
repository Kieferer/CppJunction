cmake_minimum_required(VERSION 3.25)
project(CppJunction)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        src/TreeSet.cpp
)

set(INCLUDE_DIRS
        include
)

add_library(CppJunction ${SOURCE_FILES})
target_include_directories(CppJunction PUBLIC ${INCLUDE_DIRS})

include(FetchContent)
set(FETCHCONTENT_GOOGLETEST_TAG "release-1.11.0")
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/${FETCHCONTENT_GOOGLETEST_TAG}.zip
)

FetchContent_MakeAvailable(googletest)

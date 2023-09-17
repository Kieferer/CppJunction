cmake_minimum_required(VERSION 3.25)
project(CppJunction)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        library.cpp
        src/TreeSet.cpp
)

set(INCLUDE_DIRS
        include
)

add_library(CppJunction ${SOURCE_FILES})
target_include_directories(CppJunction PUBLIC ${INCLUDE_DIRS})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(CppJunctionTests test/TreeSetTest.cpp)

target_link_libraries(CppJunctionTests CppJunction GTest::GTest GTest::Main)

add_test(NAME CppJunctionTests COMMAND CppJunctionTests)


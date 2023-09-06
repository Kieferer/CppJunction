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

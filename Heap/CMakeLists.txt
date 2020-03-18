cmake_minimum_required(VERSION 2.6)
project(heap LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})

add_executable(main_maxheap main_maxheap.cc)
add_executable(main_heapsort1 main_heapsort1.cc)
add_executable(main_heapsort2 main_heapsort2.cc)
add_executable(main_indexmaxheap main_indexmaxheap.cc)
add_executable(main_stlmakeheap main_stlmakeheap.cc)


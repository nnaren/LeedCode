cmake_minimum_required(VERSION 3.20)
project(heap_sort)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(heap_sort
        heapsort.hpp
        main.cpp)

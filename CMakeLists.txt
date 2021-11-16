cmake_minimum_required(VERSION 3.20)
project(task1_dynamic_memory_allocation_Dinahussam_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(task1_dynamic_memory_allocation_Dinahussam_main
        catch.hpp
        main.cpp
        MyArray.tpp
        MyArray.h
        test.cpp)

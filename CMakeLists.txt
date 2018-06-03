cmake_minimum_required(VERSION 3.6)
project(hash_table)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp hash_table.cpp hash_table.h)
add_executable(hash_table ${SOURCE_FILES})
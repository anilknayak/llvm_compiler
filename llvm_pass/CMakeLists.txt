# project name
# LLVM_DIR=/usr/local/opt/llvm/lib/cmake/llvm cmake ..

cmake_minimum_required(VERSION 3.1)
project(llvm_pass)

find_package(LLVM REQUIRED CONFIG)
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})

add_subdirectory(function_pass)  # Use your pass name here.
add_subdirectory(mutable_function_pass)  # Use your pass name here.

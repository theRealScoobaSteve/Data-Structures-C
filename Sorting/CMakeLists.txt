cmake_minimum_required(VERSION 3.9)
project(Sorting)

set(CMAKE_CXX_STANDARD 11)

add_executable(Sorting main.cpp sort.h insertionSort.h quickSort.h heapSort.h)
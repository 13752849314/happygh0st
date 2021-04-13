cmake_minimum_required(VERSION 3.15)
project(Linklist)

set(CMAKE_CXX_STANDARD 14)

add_executable(Linklist main.cpp Linklist/linklist.h Linklist/linklist.cpp)

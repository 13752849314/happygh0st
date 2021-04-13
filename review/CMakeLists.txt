cmake_minimum_required(VERSION 3.15)
project(review C)

set(CMAKE_C_STANDARD 99)

add_executable(review main.c Array.c Array.h LinkList.c LinkList.h xxb/DLinklist.c
        xxb/DLinklist.h xxb/LoopLinklist.c xxb/LoopLinklist.h)

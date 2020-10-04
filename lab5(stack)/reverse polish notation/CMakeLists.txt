cmake_minimum_required(VERSION 3.15)
project(reverse_polish_notation C)

set(CMAKE_C_STANDARD 11)

add_executable(reverse_polish_notation main.c stack.c stack.h)
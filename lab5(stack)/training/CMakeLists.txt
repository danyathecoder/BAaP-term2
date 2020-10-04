cmake_minimum_required(VERSION 3.15)
project(training C)

set(CMAKE_C_STANDARD 11)

add_executable(training main.c stack.h stack.c)
cmake_minimum_required(VERSION 3.6)
project(project1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        sudoku-driver.cpp Sudoku.cpp Sudoku.h)

add_executable(project1 ${SOURCE_FILES})
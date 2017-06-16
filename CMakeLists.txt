cmake_minimum_required(VERSION 3.7)
project(ExamDiPro)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Matriciosamente.h Matrix.h ValoMatrix.h)
add_executable(ExamDiPro ${SOURCE_FILES})
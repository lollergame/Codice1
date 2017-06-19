cmake_minimum_required(VERSION 3.7)
project(ExamDiPro)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES main.cpp Matrix.h SquareMatrix.h MatrixDesigner.h SquareMatrix.h MatrixStyle.h MatrixDesigner.h RowVector.h ColVector.h RectangleMatrix.h)
add_executable(ExamDiPro main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ExamDiPro core)

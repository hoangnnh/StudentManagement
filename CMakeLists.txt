cmake_minimum_required(VERSION 3.27)
project(StudentManagement)

set(CMAKE_CXX_STANDARD 17)

add_executable(StudentManagement main.cpp
        Student.cpp
        Student.h
        Classroom.cpp
        Classroom.h)

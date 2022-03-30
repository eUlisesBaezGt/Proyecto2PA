cmake_minimum_required(VERSION 3.21)
project(Exam2PA)

set(CMAKE_CXX_STANDARD 14)

include_directories(Project)

add_executable(Exam2PA
        Project/Admin.h
        Project/Enums.h
        Project/main.cpp
        Project/Menu.h
        Project/Student.h)

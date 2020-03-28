cmake_minimum_required(VERSION 3.14)
project(OS_project1)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(OS_project1
        FileNode.cpp
        FileNode.h
        FileTree.cpp
        FileTree.h
        main.cpp
        utilities.cpp
        utilities.h
        )

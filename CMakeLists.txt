cmake_minimum_required(VERSION 3.10)
project(OS_project1)

find_package(Qt5Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(OS_project1
        src/FileNode.c
        src/FileNode.h
        src/FileTree.c
        src/FileTree.h
        src/main.c
        src/utilities.c
        src/utilities.h
        src/vector.h)

target_link_libraries(OS_project1 Qt5::Widgets)
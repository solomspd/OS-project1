cmake_minimum_required(VERSION 3.10)
project(OS_project1 C)

set(CMAKE_C_STANDARD 11)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})
include_directories(.)

add_executable(OS_project1
        FileNode.c
        FileNode.h
        FileTree.c
        FileTree.h
        main.c
        utilities.c
        utilities.h
        vector.h)

cmake_minimum_required(VERSION 3.10)
project(OS_project1 C)

set(CMAKE_C_STANDARD 11)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTKMM gtkmm)
INCLUDE_DIRECTORIES(${GTKMM_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTKMM_LIBRARY_DIRS})
ADD_DEFINITIONS(${GTKMM_CFLAGS_OTHER})
include_directories(.)

add_executable(OS_project1
        src/FileNode.c
        src/FileNode.h
        src/FileTree.c
        src/FileTree.h
        src/main.c
        src/utilities.c
        src/utilities.h
        src/vector.h)

cmake_minimum_required(VERSION 3.10)
project(OS_project1)

set(CMAKE_C_STANDARD 20)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTKMM gtkmm)
INCLUDE_DIRECTORIES(${GTKMM_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTKMM_LIBRARY_DIRS})
ADD_DEFINITIONS(${GTKMM_CFLAGS_OTHER})
include_directories(.)

add_executable(OS_project1 src/main.cpp src/node.cpp src/node.h)

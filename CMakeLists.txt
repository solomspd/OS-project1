cmake_minimum_required(VERSION 3.10)
project(OS_project1)

set(CMAKE_C_STANDARD 20)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(OS_project1 src/main.cpp src/node.cpp src/node.h)

target_link_libraries(OS_project1 ${GTKMM_LIBRARIES})

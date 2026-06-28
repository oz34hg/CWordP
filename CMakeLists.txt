cmake_minimum_required(VERSION 3.16)

project(CWORDP VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(CWordP
    src/main.cpp
    src/MainWindow.cpp
    include/MainWindow.hpp
)

target_link_libraries(CWordP PRIVATE Qt6::Widgets)

target_include_directories(CWordP PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

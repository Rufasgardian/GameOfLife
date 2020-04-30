cmake_minimum_required(VERSION 3.17)

project(console LANGUAGES C)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE ansi_gui.c ansi_gui.h)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


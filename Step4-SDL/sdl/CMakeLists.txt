cmake_minimum_required(VERSION 3.17)

project(sdl LANGUAGES C)

find_package(SDL2 CONFIG REQUIRED )

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE sdl.c sdl.h)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2main SDL2::SDL2)
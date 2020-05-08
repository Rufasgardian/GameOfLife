cmake_minimum_required(VERSION 3.17)

project(game LANGUAGES C)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE logic.c logic.h)

target_link_libraries(${PROJECT_NAME} PUBLIC sdl)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
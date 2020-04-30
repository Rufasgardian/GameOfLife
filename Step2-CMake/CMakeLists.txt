cmake_minimum_required(VERSION 3.17)
cmake_policy(SET CMP0076 NEW)

project(GameOfLife LANGUAGES C)

set(SRC main.c)

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(console)
add_subdirectory(game)

target_link_libraries(${PROJECT_NAME} PUBLIC console)
target_link_libraries(${PROJECT_NAME} PUBLIC game)

add_custom_target(doc COMMAND doxygen dconfig WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_target(cleandoc COMMAND rm -rf html latex WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_target(dist COMMAND tar -zcf ${PROJECT_NAME}.tar.gz game console main.c WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_target(cleandist COMMAND rm ${PROJECT_NAME}.tar.gz WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


cmake_minimum_required(VERSION 3.11)
cmake_policy(SET CMP0076 NEW)

project(pract_test C)

set(GameOfLifeLogic functions)
set(SRC CUnit_tests.c gameoflife.c)
set(HEADERS CUnit_tests.h gameoflife.h)
add_library(${GameOfLifeLogic})
target_sources(${GameOfLifeLogic} PRIVATE ${SRC} ${HEADERS})
target_link_libraries(${GameOfLifeLogic} INTERFACE m)

target_link_libraries(${GameOfLifeLogic} PUBLIC gcov)
target_compile_options(${GameOfLifeLogic} PUBLIC "--coverage")
target_link_options(${GameOfLifeLogic} PUBLIC "--coverage")

set(Project test_logic)
add_executable(${Project})
target_sources(${Project} PUBLIC CUnit_tests.c)
target_link_libraries(${Project} PUBLIC ${GameOfLifeLogic} cunit)
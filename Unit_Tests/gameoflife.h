#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <CUnit/Basic.h>
#include <stdbool.h>

// functions
int **create_area(int x, int y);
void print_area(int **area, int x, int y);
void add_live_cells(int **area, int r, int c);
void add_dead_cells(int **area, int r, int c);
int **clipped(int **area, int row, int column);
int **circular(int **area, int row, int column);

#endif
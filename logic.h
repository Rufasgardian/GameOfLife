#ifndef LOGIC_H
#define LOGIC_H
#include <stdlib.h>
#include <stdio.h>

int **create_area(int x, int y);
void print_area(int **area, int x, int y);
void add_live_cells(int **area, int r, int c);
void add_dead_cells(int **area, int r, int c);




#endif
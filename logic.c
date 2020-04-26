#include "logic.h"

int **create_area(int x, int y){
    int **area = (int**)malloc(x * sizeof(int*));
    for (size_t i = 0; i < x; i++)
    {
        area[i] = (int*)malloc(y * sizeof(int));
    }
    
    for (size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            area[i][j] = 0;
        }
    }
    return area;
}

void print_area(int **area, int x, int y){

    for (size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            printf("%d", area[i][j]);
        }
        printf("\n");
    }
}

void add_live_cells(int **area, int r, int c){
    area[r][c] = 1;
    return;
}

void add_dead_cells(int **area, int r, int c){
    area[r][c] = 0;
    return;    
}
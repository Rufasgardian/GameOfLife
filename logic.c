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

int **neighbor_decides_dead_or_alive(int **area, int row, int column){
    int neighbor = 0;
    int **newarea = create_area(row, column);
    for(int i=0; i< row; i++){
            for(int j=0; j<column; j++){
                if(j>0 && area[i][j-1] == 1){
                    neighbor +=1;
                }
                if(i>0 && j > 0 && area[i-1][j-1] == 1){
                    neighbor += 1;   
                }
                if(row > i+1 && j > 0 && area[i+1][j-1] == 1){
                    neighbor += 1;   
                }
                if(i > 0 && area[i-1][j] == 1){
                    neighbor +=1;   
                }
                if(i > 0 && column > j+1 && area[i-1][j+1] == 1){
                    neighbor += 1;  
                }
                if(column > j+1 && area[i][j+1] == 1){
                    neighbor += 1;
                }
                if(row > i+1 && area[i+1][j] == 1){   
                    neighbor += 1;  
                }
                if(row > i+1 && column > j+1 && area[i+1][j+1] == 1){
                    neighbor += 1;
                }

                if(area[i][j] == 1){
                    if(neighbor < 2 || neighbor >3){
                        newarea[i][j] = 0;
                    }else{
                        newarea[i][j] = 1;
                    }
                }else if(area[i][j] == 0){
                    if(neighbor == 3){
                        newarea[i][j] = 1;
                    }
                }
                neighbor = 0;
            }
        }

        print_area(newarea, row, column);
        
    return newarea;
}

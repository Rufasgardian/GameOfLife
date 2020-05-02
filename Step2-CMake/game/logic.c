#include "logic.h"

/*!
 *\brief Creates new board with given width and height
 *\param x height of board
 *\param y width of board
*/
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

/*!
 *\brief Prints the board with its values
 *\param area pointer to the board 
 *\param x height of board
 *\param y width of board
*/
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

/*!
 *\brief Changes the value of given position to 1(live cell)
 *\param area pointer to the board 
 *\param r given row position
 *\param c given column position
*/
void add_live_cells(int **area, int r, int c){
    area[r][c] = 1;
    return;
}

/*!
 *\brief Changes the value of given position to 0(dead cell)
 *\param area pointer to the board 
 *\param r given row position
 *\param c given column position
*/
void add_dead_cells(int **area, int r, int c){
    area[r][c] = 0;
    return;    
}

/*!
 *\brief Checks each cell to decide it will be dead or alive for the next generation
 * and returns next generated board
 *\param area pointer to the board 
 *\param row height of board
 *\param column width of board
*/
int **neighbor_decides_dead_or_alive(int **area, int row, int column){
    int neighbor = 0;
    int **newarea = create_area(row, column);
    for(int i=0; i < row; i++){
        for(int j=0; j<column; j++){

                if(j-1 < 0 && i > 0 &&  area[i-1][column-1] == 1){
                    neighbor += 1;
                }
                if(j-1 < 0 && i >= 0 && i+1 < row && area[i+1][column-1] == 1){
                    neighbor += 1;
                }
                if(j-1 < 0 && i >= 0 && area[i][column-1] == 1){
                    neighbor += 1;
                }
                if(j>0 && area[i][j-1] == 1){
                    neighbor += 1;
                }
                if(i>0 && j > 0 && area[i-1][j-1] == 1){
                    neighbor += 1;
                }
                if(row > i+1 && j > 0 && area[i+1][j-1] == 1){
                    neighbor += 1;
                }
                if(i > 0 && area[i-1][j] == 1){
                    neighbor += 1;
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
                if(column == j+1 && area[i][0] == 1){
                    neighbor += 1;
                }
                if(i > 0 && column == j+1 && area[i-1][0] == 1){
                    neighbor += 1;
                }
                if(row > i+1 && column == j+1 && area[i+1][0] == 1){
                    neighbor += 1;
                }
                if(row == i+1 && area[0][j] == 1){
                    neighbor += 1;
                }
                if(row == i+1 && j > 0 && area[0][j-1] == 1){
                    neighbor += 1;
                }
                if(row == i+1 && column > j+1 && area[0][j+1] == 1){
                    neighbor += 1;
                }
                if(row == i+1 && column == j+1 && area[0][0] == 1){
                    neighbor += 1;
                }
                if(row == i+1 && j == 0 && area[0][column-1] == 1){
                    neighbor += 1;
                }
                if(i == 0 && area[row-1][j] == 1){

                    neighbor += 1;
                }
                if(i == 0 && j > 0 && area[row-1][j-1] == 1){
                    neighbor += 1;
                }
                if(i == 0 && column > j+1 && area[row-1][j+1] == 1){
                    neighbor += 1;
                }
                if(i == 0 && j == 0 && area[row-1][column-1] == 1){
                    neighbor += 1;
                }
                if(i == 0 && column == j+1 && area[row-1][0] == 1){
                    neighbor += 1;
                }

                if(area[i][j] == 1){
                    if(neighbor < 2 || neighbor > 3){
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

    return newarea;

}
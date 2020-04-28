#include "ansi_gui.h"

/*!
 *\brief Draws the given board with the help of ansi and waits 0.5 second. 
 * Live cells described with red color and dead cells with black color 
 *\param area pointer to the board 
 *\param row height of board
 *\param col width of board
*/
void draw_ansi(int **area, int row, int col){
    struct timespec tim1, tim2;
    tim1.tv_sec = 0;
    tim1.tv_nsec = 500000000;

    // clear screen
    printf("\033[2J");

    // go to 0, 0
    printf("\033[0;0H");
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int c = (area[i][j] == 1) ? 101 : 40;
            printf("\033[%dm  ", c);
        }
        printf("\n");
    }
    
    // sleep 0.5 sec
    if(nanosleep(&tim1 , &tim2) < 0 )
    {
        perror("nanosleep");
        exit(1);
    }
}
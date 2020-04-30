/*! 
* \authors Rufat Huseynov and Shirin Shukurov
* \version 2.0
* \mainpage The Game Of Life Console Application
* \section intro_sec Introduction
* This is the second version of Game of Life Application with CMake. 
* \section rules_sec Rules
* 1.Any live cell with fewer than two live neighbours dies, as if by underpopulation.\n
* 2.Any live cell with two or three live neighbours lives on to the next generation.\n
* 3.Any live cell with more than three live neighbours dies, as if by overpopulation.\n
* 4.Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction. 
* \section compile_sec Compilation
* Use "make all" command to compile code, then execute the new generated program called "GameOfLife".
*
* "make clean" can be used to delete new created object files and GameOfLife executable file
*
* "make dist" creates a distribution tar file for this program\n
* "make cleandist" removes generated tar file 
*
* "make doc" creates the necessary documentation files for this program\n
* "make cleandoc" removes generated documentation files
*/

#include "logic.h"
#include "ansi_gui.h"

/*!
 *\brief Main function that starts the program
*/
int main(int argc, char const *argv[])
{
    int x = 40, y = 40;

    int **area = create_area(x, y);

    add_live_cells(area, 13, 17);
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            add_live_cells(area, 13+i, 18+j);
        }
        
    }

    // hide cursor
    printf("\033[?251");

    draw_ansi(area, x, y);
    // draw for first time
    int **next_gen = neighbor_decides_dead_or_alive(area, x, y);
    draw_ansi(next_gen, x, y);

    while (1)
    {
        int **next_gen2;
        next_gen2 = neighbor_decides_dead_or_alive(next_gen, x, y);
        next_gen = next_gen2;
        draw_ansi(next_gen, x, y);
    }
    
    return 0;
}

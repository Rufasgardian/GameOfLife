#include "logic.h"

int main(int argc, char const *argv[])
{
    int x, y;
    printf("Enter the size of box (row and column in order): ");
    scanf("%d %d", &x, &y);

    int **area = create_area(x, y);
    print_area(area, x, y);

    while (1)
    {
        float row,col;
        int lrow, lcol;
        printf("Enter the positions of live cells(row and column).To finish enter (0, 0) : ");
        scanf("%f %f", &row, &col);

        if (row == 0 && col == 0)
        {
            break;
        }
        lrow = row-1;
        lcol = col-1;
        if (lrow > x-1 || lcol > y-1)
        {
            printf("Out of range. Please try again\n");
            continue;
        }
        
        add_live_cells(area, lrow, lcol);
    }

    print_area(area, x, y);

    printf("\n\n");
    
    neighbor_decides_dead_or_alive(area, x, y);
    return 0;
}
#include "logic.h"

/*! 
* Circular version game rules
*/
void circular_game_rule(int area[][AREA_WIDTH]){
    int neighbor = 0; // counter of neighbors
    int newarea[AREA_HEIGHT][AREA_WIDTH]; // temporary area
    for(int i=0; i < AREA_HEIGHT; i++){
            for(int j=0; j < AREA_WIDTH; j++){
                if(j-1 < 0 && i > 0 &&  area[i-1][AREA_WIDTH-1] == ALIVE){
                    neighbor += 1;
                }
                if(j-1 < 0 && i >= 0 && i+1 < AREA_HEIGHT && area[i+1][AREA_WIDTH-1] == ALIVE){
                    neighbor += 1;
                }
                if(j-1 < 0 && i >= 0 && area[i][AREA_WIDTH-1] == ALIVE){
                    neighbor += 1;
                }
                if(j>0 && area[i][j-1] == ALIVE){
                    neighbor += 1;
                }
                if(i>0 && j > 0 && area[i-1][j-1] == ALIVE){
                    neighbor += 1;
                }
                if(AREA_HEIGHT > i+1 && j > 0 && area[i+1][j-1] == ALIVE){
                    neighbor += 1;
                }
                if(i > 0 && area[i-1][j] == ALIVE){
                    neighbor += 1;
                }
                if(i > 0 && AREA_WIDTH > j+1 && area[i-1][j+1] == ALIVE){
                    neighbor += 1;
                }
                if(AREA_WIDTH > j+1 && area[i][j+1] == ALIVE){
                    neighbor += 1;
                }
                if(AREA_HEIGHT > i+1 && area[i+1][j] == ALIVE){   
                    neighbor += 1;
                }
                if(AREA_HEIGHT > i+1 && AREA_WIDTH > j+1 && area[i+1][j+1] == ALIVE){
                    neighbor += 1;
                }
                if(AREA_WIDTH == j+1 && area[i][0] == ALIVE){
                    neighbor += 1;
                }
                if(i > 0 && AREA_WIDTH == j+1 && area[i-1][0] == ALIVE){
                    neighbor += 1;
                }
                if(AREA_HEIGHT > i+1 && AREA_WIDTH == j+1 && area[i+1][0] == ALIVE){
                    neighbor += 1;
                }
                if(AREA_HEIGHT == i+1 && area[0][j] == ALIVE){
                    neighbor += 1;
                }
                if(AREA_HEIGHT == i+1 && j > 0 && area[0][j-1] == ALIVE){
                    neighbor += 1;
                }
                if(AREA_HEIGHT == i+1 && AREA_WIDTH > j+1 && area[0][j+1] == ALIVE){
                    neighbor += 1;
                }
                if(AREA_HEIGHT == i+1 && AREA_WIDTH == j+1 && area[0][0] == ALIVE){
                    neighbor += 1;
                }
                if(AREA_HEIGHT == i+1 && j == 0 && area[0][AREA_WIDTH-1] == ALIVE){
                    neighbor += 1;
                }
                if(i == 0 && area[AREA_HEIGHT-1][j] == ALIVE){

                    neighbor += 1;
                }
                if(i == 0 && j > 0 && area[AREA_HEIGHT-1][j-1] == ALIVE){
                    neighbor += 1;
                }
                if(i == 0 && AREA_WIDTH > j+1 && area[AREA_HEIGHT-1][j+1] == ALIVE){
                    neighbor += 1;
                }
                if(i == 0 && j == 0 && area[AREA_HEIGHT-1][AREA_WIDTH-1] == ALIVE){
                    neighbor += 1;
                }
                if(i == 0 && AREA_WIDTH == j+1 && area[AREA_HEIGHT-1][0] == ALIVE){
                    neighbor += 1;
                }
		
		    // deciding cell should be dead or alive 
                    if(area[i][j] == ALIVE){
                        if(neighbor < 2 || neighbor > 3){
                            newarea[i][j] = DEAD;
                        }else{
                            newarea[i][j] = ALIVE;
                        }
                    }else if(area[i][j] == DEAD){
                        if(neighbor == 3){
                            newarea[i][j] = ALIVE;
                        }else{
                            newarea[i][j] = DEAD;
                        }
                    }
                neighbor = 0;
            }
        }
        
    // updating area
    for(int i = 0; i < AREA_HEIGHT; i++){
        for(int j = 0; j < AREA_WIDTH; j++){
            area[i][j] = newarea[i][j];
        }
    }
    
}

#include "logic.h"

// clipped game rules
void clipped_game_rule(int area[][AREA_WIDTH]){
    int neighbor = 0; // neighbor counter
    int newarea[AREA_HEIGHT][AREA_WIDTH];
    for(int i=0; i < AREA_HEIGHT; i++){
            for(int j=0; j < AREA_WIDTH; j++){
                    if(j>0 && area[i][j-1] == ALIVE){
                        neighbor +=1;
                    }
                    if(i>0 && j > 0 && area[i-1][j-1] == ALIVE){
                        neighbor += 1;   
                    }
                    if(AREA_HEIGHT > i+1 && j > 0 && area[i+1][j-1] == ALIVE){
                        neighbor += 1;   
                    }
                    if(i > 0 && area[i-1][j] == ALIVE){
                        neighbor +=1;   
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
        
    for(int i = 0; i < AREA_HEIGHT; i++){
        for(int j = 0; j < AREA_WIDTH; j++){
            area[i][j] = newarea[i][j];
        }
    }
    
}
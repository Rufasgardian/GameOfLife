#include "sdl.h"

/*! 
* Draws grid
*/
void drawGrid(SDL_Renderer *r){
    
    // draw vertical line
    for(int vertical = CELL_SIZE; vertical < SCREEN_WIDTH; vertical += CELL_SIZE){

        SDL_SetRenderDrawColor(r, 110, 110, 110, 110);

        SDL_RenderDrawLine(r, vertical, 0, vertical, SCREEN_HEIGHT);
    
    }

    // draw horizontal lines
    for(int horizontal = CELL_SIZE; horizontal < SCREEN_HEIGHT; horizontal += CELL_SIZE){

        SDL_SetRenderDrawColor(r, 110, 110, 110, 110);

        SDL_RenderDrawLine(r, 0, horizontal, SCREEN_WIDTH, horizontal);

    }
}

/*! 
* Draws the cells
*/
void drawCells(SDL_Renderer *r, int a[][AREA_WIDTH]){
    
    SDL_Rect cellRect;
    cellRect.w = CELL_SIZE + 1; 
    cellRect.h = CELL_SIZE + 1; 

    // Draw living cells
    int j, i;
    for(i = 0; i < AREA_HEIGHT; i++){
        for(j = 0; j < AREA_WIDTH; j++){
            if(a[i][j] == ALIVE){
                // Set cell x/y pos
                cellRect.x = j * CELL_SIZE;
                cellRect.y = i * CELL_SIZE;

                SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
                SDL_RenderFillRect(r, &cellRect);
            }
        }
    }
}

/*! 
* Creates window
*/
SDL_Window *createWindow(char *title){
    SDL_Window *window = SDL_CreateWindow(
        title,                  
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        SCREEN_WIDTH,           
        SCREEN_HEIGHT,          
        0                       
    );

    if(!window){
        printf("Failed to create window. %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    return window;
}

/*! 
* Creates renderer
*/
SDL_Renderer *createRenderer(SDL_Window *window){
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,                     
        -1,                        
        SDL_RENDERER_ACCELERATED    
    );

    if(!renderer){
        printf("Failed to create renderer. %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    return renderer;
}

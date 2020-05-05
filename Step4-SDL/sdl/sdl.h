#ifndef SDL_H
#define SDL_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define CELL_SIZE 15
#define AREA_WIDTH 40
#define AREA_HEIGHT 40
#define SCREEN_WIDTH (AREA_WIDTH * CELL_SIZE)
#define SCREEN_HEIGHT (AREA_HEIGHT * CELL_SIZE)


typedef enum {ALIVE, DEAD} State;
typedef struct{
    int x;
    int y;
    State state;
} Cell;

// SDL related functions
SDL_Window *createWindow(char *title);
SDL_Renderer *createRenderer(SDL_Window *window);
void drawGrid(SDL_Renderer *r);
void drawCells(SDL_Renderer *r, int a[][AREA_WIDTH]);

#endif
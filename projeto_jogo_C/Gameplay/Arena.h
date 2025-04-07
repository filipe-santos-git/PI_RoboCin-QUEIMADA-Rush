#ifndef ARENA
#define ARENA
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CarregarTexturas/loadtextures.h"

typedef struct Arena
{
    Rectangle rec;
    float line_thick;
    Texture quadra;
    Color color;
    double TimeGame;
    char time[10];
}Arena;

Arena arena;

#endif
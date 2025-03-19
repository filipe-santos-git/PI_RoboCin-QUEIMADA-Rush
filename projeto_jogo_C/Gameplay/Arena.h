#ifndef ARENA
#define ARENA
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arena
{
    Rectangle rec;
    float line_thick;
    Color color;
}Arena;

Arena arena;

#endif
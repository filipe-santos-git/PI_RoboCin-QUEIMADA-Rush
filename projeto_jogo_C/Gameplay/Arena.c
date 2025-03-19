#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arena.h"





void CreateArena()
{
    const int center_x = GetScreenWidth()/2;
    const int center_y = GetScreenHeight()/2;
    arena.rec.x = center_x;
    arena.rec.y = center_y;
    arena.rec.height = 500;
    arena.rec.width = 500;
    arena.rec.x -= arena.rec.width/2;
    arena.rec.y -= arena.rec.height/2 - 60;
    arena.line_thick = 6;
}

void ArenaDraw()
{
    ClearBackground(BLACK);
    DrawRectangleLinesEx(arena.rec, arena.line_thick, RAYWHITE);
}
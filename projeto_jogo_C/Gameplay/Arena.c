#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "General_Classes/Screen_Details.h"
#include "Arena.h"






void CreateArena()
{
    const int center_x = S_l/2;
    const int center_y = S_a/2;
    arena.quadra = quadra;
    arena.fundo=fundo;
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
    float scale = 2.0f;
    Vector2 position = {0, 0};
    DrawTextureEx(arena.fundo, position, 0.0f, scale, WHITE);
    DrawTexture(arena.quadra,arena.rec.x, arena.rec.y, WHITE);
    DrawText(arena.time, 20, 50, 90, YELLOW);
}
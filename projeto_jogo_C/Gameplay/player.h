#ifndef PLAYER
#define PLAYER
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player
{
    float height;
    float width;
    Vector2 pos;
    Vector2 vel;
    Color color;
}Player;

void GreenState();
void ArenaColision();
void CreatePlayer();
void PlayerUpdate(float dt);
void PlayerDraw();


#include "player.c"
#endif











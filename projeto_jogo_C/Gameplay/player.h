#ifndef PLAYER
#define PLAYER
#include "raylib.h"
#include "HP.h"
#include "CarregarTexturas/loadtextures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player
{
    Vida hp;
    float height;
    float width;
    Vector2 pos;
    Vector2 dir;
    int vel;
    Color color;
    int ready;
    double now, time, dash_t;
    Color reflect;
    Rectangle rec;
    Sound dash;
    double hitted;
    int hit, dash_ready, dano;
    Texture texture;
    Color tone;

    
}Player;

Player Blanky;
void GreenState();
void ArenaColision();
void CreatePlayer();
void PlayerUpdate(float dt);
void PlayerDraw();


#include "player.c"
#endif











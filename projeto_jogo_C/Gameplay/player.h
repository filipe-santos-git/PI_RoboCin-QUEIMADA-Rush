#ifndef PLAYER
#define PLAYER

#include "raylib.h"
#include "HP.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../assets/audios/audio_effects.h"



typedef struct Player
{
    Vida hp;
    float height;
    float width;
    Vector2 pos;
    Vector2 vel;
    Color color;
    int ready;
    double now, time;
    Color reflect;
    Sound som_verde;
}Player;

void GreenState();
void ArenaColision();
void CreatePlayer();
void PlayerUpdate(float dt);
void PlayerDraw();


#include "player.c"
#endif











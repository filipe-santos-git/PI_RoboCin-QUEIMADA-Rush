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
    Sound sound;
    int ready;
    double now, time;
    Color reflect;
<<<<<<< Updated upstream
    Sound som_verde;
=======
    Rectangle rec;
    double hitted;
    int hit, dash_ready;
>>>>>>> Stashed changes
}Player;

void GreenState();
void ArenaColision();
void CreatePlayer();
void PlayerUpdate(float dt);
void PlayerDraw();


#include "player.c"
#endif











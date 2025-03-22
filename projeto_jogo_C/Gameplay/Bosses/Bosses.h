#ifndef BOSS
#define BOSS
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Boss
{
    float height, width;
    Vector2 pos;
    Vector2 vel;
    Vector2 shot_dir;
    int ataque;
    Color color;
    Rectangle rec;
    int hp, hit;
    double hitted, mana;

    double start_attack;
}Boss;
Boss dummy;


#include "Dummy.c"
#endif


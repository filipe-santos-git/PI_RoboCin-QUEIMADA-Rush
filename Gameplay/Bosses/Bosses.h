#ifndef BOSS
#define BOSS
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CarregarTexturas/loadtextures.h"

typedef struct Boss
{
    float height, width;
    Vector2 pos;
    Vector2 vel;
    Vector2 shot_dir;
    int ataque;
    Color color;
    Rectangle rec;
    Texture robocin_atordoado;
    Texture robocin_nivel_1;
    int hp, hit;
    double hitted, mana;

    double start_attack;
    int B;
}Boss;
Boss dummy;


#include "Dummy.c"
#endif


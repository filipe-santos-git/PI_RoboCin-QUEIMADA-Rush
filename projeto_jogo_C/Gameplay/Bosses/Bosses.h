#ifndef BOSS
#define BOSS
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gameplay/coletáveis/coracao.h"
#include "CarregarTexturas/loadtextures.h"
#include "assets/audios/audios_effects.h"

typedef struct Boss
{
    float height, width;
    Vector2 pos;
    Vector2 vel;
    Vector2 shot_dir;
    int ataque;
    Color color;
    Rectangle rec;
    Texture atordoado;
    Texture nivel;
    Texture atual;
    Sound Boss_dmg;
    int hp, hit;
    int flag_move;
    double hitted, mana;

    double start_attack;
    int B;
}Boss;
Boss dummy;


#include "Dummy.c"
#endif


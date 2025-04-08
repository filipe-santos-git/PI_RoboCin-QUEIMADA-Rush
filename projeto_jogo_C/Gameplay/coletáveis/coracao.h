#ifndef CORACAO
#define CORACAO
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CarregarTexturas/loadtextures.h"
#include "Gameplay/Arena.h"
#include "Gameplay/player.h"

typedef struct Coracao 
{
    float x, y, H;
    Texture coracao;
    struct Coracao *next, *before;
    double time;


} Coracao;

Coracao *hearts;



#include "coracao.c"
#endif 

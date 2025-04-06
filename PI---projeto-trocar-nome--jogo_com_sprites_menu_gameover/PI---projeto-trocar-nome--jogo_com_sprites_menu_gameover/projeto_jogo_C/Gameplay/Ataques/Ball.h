#ifndef BALL
#define BALL
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CarregarTexturas/loadtextures.h"



typedef struct Ball
{
    int tam, tempo;
    Vector2 pos;
    Vector2 dir;
    Color color;
    Texture ball;
    struct Ball *next;
    struct Ball *before;
    float vel, acel;
    double C, N;
    int type;

    //para a s_ball:
    float s_b_a, s_b_f;
    int i;

    //para a b_ball:
    int bounce;



}Ball;

Ball *ball;
Ball *r_ball;
Ball *s_ball;
Ball *b_ball;

#include "R_Ball.c"
#include "Ball.c"
#include "Sen_ball.c"
#include "B_Ball.c"
#endif
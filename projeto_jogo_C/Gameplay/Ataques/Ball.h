#ifndef BALL
#define BALL
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Ball
{
    int tam, tempo;
    Vector2 pos;
    Vector2 dir;
    Color color;
    struct Ball *next;
    struct Ball *before;
    float vel, acel;
    double C, N;
}Ball;

Ball *ball;
Ball *r_ball;
Ball *s_ball;

#include "R_Ball.c"
#include "Ball.c"
#include "Sen_ball.c"
#endif
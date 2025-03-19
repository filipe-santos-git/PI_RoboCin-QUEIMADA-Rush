#ifndef BALL
#define BALL
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Ball
{
    int tam;
    Vector2 pos;
    Vector2 dir;
    Color color;
    struct Ball *next;
    struct Ball *before;
}Ball;

Ball *ball;




#include "Ball.c"
#endif
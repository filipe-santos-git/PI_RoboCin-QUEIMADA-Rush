#ifndef BUTTON
#define BUTTON
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Button
{
    Rectangle rec;
    Color color;
    char text[100];
    int tx, ty;
    Color text_color;
}Button;


#endif
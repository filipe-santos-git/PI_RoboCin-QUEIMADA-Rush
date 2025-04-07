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
    Texture start1;
    Texture start2;
    Texture sair;
    Texture tente_novamente;
    char text[100];
    int tx, ty;
    Color text_color;
}Button;

#include "Button.c"
#endif
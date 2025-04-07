#ifndef MAIN
#define MAIN

#include "raylib.h"
#include "General_Classes/Button.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CarregarTexturas/loadtextures.h"




typedef struct Menu
{
    Rectangle rec;
    Button button;
    char Title[100];
    Texture menu;
    Texture game_over;
    Texture start1;
    Texture start2;
    Texture sair;
    Texture tente_novamente;
    Color BackGround_color;
    Color Tiltle_color;
}Menu;




#endif

#ifndef MAIN
#define MAIN

#include "raylib.h"
#include "General_Classes/Button.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CarregarTexturas/loadtextures.h"




typedef struct Vitoria
{
    Rectangle rec;
    Button menu_button;
    char Title[100];
    Texture menu;
    Texture tela_vitoria;
    Color BackGround_color;
    Color Tiltle_color;
}Vitoria;




#endif
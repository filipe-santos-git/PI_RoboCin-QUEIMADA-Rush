#ifndef HISTORIA
#define HISTORIA

#include "raylib.h"
#include "General_Classes/Button.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CarregarTexturas/loadtextures.h"




typedef struct Historia
{
    Rectangle rec;
    Button h_menu_button;
    Button h_seta_button;
    char Title[100];
    Texture menu;
    Texture tela_historia;
    Color BackGround_color;
    Color Tiltle_color;
}Historia;


#endif
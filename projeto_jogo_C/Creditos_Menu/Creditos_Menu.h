#ifndef CREDITOS
#define CREDITOS

#include "raylib.h"
#include "General_Classes/Button.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CarregarTexturas/loadtextures.h"




typedef struct Creditos
{
    Rectangle rec;
    Button c_menu_button;
    char Title[100];
    Texture menu;
    Texture tela_creditos;
    Color BackGround_color;
    Color Tiltle_color;
}Creditos;

#endif
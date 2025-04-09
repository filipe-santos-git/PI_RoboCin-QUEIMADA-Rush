#ifndef WIN
#define WIN

#include "raylib.h"
#include "General_Classes/Button.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CarregarTexturas/loadtextures.h"
#include "assets/audios/audios_effects.h"




typedef struct Win
{
    Rectangle rec;
    Button menu_button;
    char Title[100];
    Texture tela_win;
    Texture start1;
    Texture start2;
    Texture sair;
    Sound Crowd;
    Texture tente_novamente;
    Color BackGround_color;
    Color Tiltle_color;
}Win;




#endif
#ifndef PAUSE
#define PAUSE
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CarregarTexturas/loadtextures.h"

typedef struct Pause
{
    Rectangle rec_back;
    Color back;
    Rectangle rec_menu;
    Texture quit1;
    Texture quit2;
    Texture resume1;
    Texture resume2;
    Texture pauseScreen;
    Color color_rec;
    char Text[100];
    int tx, ty;
    Color text_color;
    int fonte_tam;
    
}Pause;


#endif

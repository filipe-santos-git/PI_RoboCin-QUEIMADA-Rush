#ifndef INSTRUCTION
#define INSTRUCTION

#include "raylib.h"
#include "General_Classes/Button.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CarregarTexturas/loadtextures.h"




typedef struct Instruction
{
    Rectangle rec;
    Button i_menu_button;
    char Title[100];
    Texture menu;
    Texture tela_instruction;
    Color BackGround_color;
    Color Tiltle_color;
}Instruction;
Instruction instruction;

#endif
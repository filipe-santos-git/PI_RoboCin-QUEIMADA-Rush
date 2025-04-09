#include "raylib.h"
#include "General_Classes/Screen_Details.h"
#include "General_Classes/Button.h"
#include "State_Manager.h"
#include "Instruction_Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Instruction instruction;



void CreateInstruction()
{
    strcpy(instruction.i_menu_button.text, "Menu");

    Rectangle r5 = {60, (S_a - 160), botao_menu.width*0.4, botao_menu.height*0.4};
    instruction.i_menu_button.rec = r5;
    instruction.i_menu_button.text_color = RAYWHITE;
    instruction.i_menu_button.color = BLACK;
    Color b, t;
    b = instruction.i_menu_button.color;
    t = instruction.i_menu_button.text_color;
    Mouse_Button(&instruction.i_menu_button, 'M', b, t);    
}


void InstructionUpdate()
{
    Rectangle r5 = {60, (S_a - 160), botao_menu.width*0.4, botao_menu.height*0.4};
    instruction.i_menu_button.rec = r5;
    Color b, t;
    b = instruction.i_menu_button.color;
    t = instruction.i_menu_button.text_color;
    instruction.BackGround_color = BLACK;
    instruction.Tiltle_color = RAYWHITE;
    Mouse_Button(&instruction.i_menu_button, 'M', b, t);
}

void InstructionDraw()
{
    ClearBackground(instruction.BackGround_color);
    float scale = 2.0f;
    Vector2 position = {0, 0};
    DrawTextureEx(tela_instrucoes, position, 0.0f, scale, WHITE);
    Vector2 mouse = GetMousePosition();
    Vector2 menuzinho = {60, S_a - 150};
    Rectangle r3 = {60, (S_a - 160), botao_menu.width*0.4, botao_menu.height*0.4};
    if (CheckCollisionPointRec(mouse, r3)) {
        DrawTextureEx(botao_menu_pressionando, menuzinho, 0, 0.4 , WHITE);
    } else {
        DrawTextureEx(botao_menu, menuzinho, 0, 0.4, WHITE);
    }
    
}
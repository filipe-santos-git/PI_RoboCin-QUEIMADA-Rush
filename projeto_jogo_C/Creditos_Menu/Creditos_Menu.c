#include "raylib.h"
#include "General_Classes/Screen_Details.h"
#include "General_Classes/Button.h"
#include "State_Manager.h"
#include "Creditos_Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Creditos credito;



void CreateCreditos()
{
    strcpy(credito.c_menu_button.text, "Menu");

    Rectangle r5 = {60, (S_a - 160), botao_menu.width*0.4, botao_menu.height*0.4};
    credito.c_menu_button.rec = r5;
    credito.c_menu_button.text_color = RAYWHITE;
    credito.c_menu_button.color = BLACK;
    Color b, t;
    b = credito.c_menu_button.color;
    t = credito.c_menu_button.text_color;
    Mouse_Button(&credito.c_menu_button, 'M', b, t);    
}


void CreditosUpdate()
{
    Rectangle r5 = {S_l-60-botao_menu.width*0.4, (S_a - 160), botao_menu.width*0.4, botao_menu.height*0.4};
    credito.c_menu_button.rec = r5;
    Color b, t;
    b = credito.c_menu_button.color;
    t = credito.c_menu_button.text_color;
    credito.BackGround_color = BLACK;
    credito.Tiltle_color = RAYWHITE;
    Mouse_Button(&credito.c_menu_button, 'M', b, t);
}

void CreditosDraw()
{
    ClearBackground(credito.BackGround_color);
    float scale = 2.0f;
    Vector2 position = {0, 0};
    DrawTextureEx(tela_creditos, position, 0.0f, scale, WHITE);
    Vector2 mouse = GetMousePosition();
    Vector2 creditinho = {S_l-60-botao_menu.width*0.4, S_a - 150};
    Rectangle r3 = {S_l-60-botao_menu.width*0.4, (S_a - 160), botao_menu.width*0.4, botao_menu.height*0.4};
    if (CheckCollisionPointRec(mouse, r3)) {
        DrawTextureEx(botao_menu_pressionando, creditinho, 0, 0.4 , WHITE);
    } else {
        DrawTextureEx(botao_menu, creditinho, 0, 0.4, WHITE);
    }
    
}
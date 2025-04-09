#include "raylib.h"
#include "General_Classes/Screen_Details.h"
#include "General_Classes/Button.h"
#include "State_Manager.h"
#include "Historia_Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Historia historias;
int fase=1;


void CreateHistoria()
{
    strcpy(historias.h_menu_button.text, "Menu");
    strcpy(historias.h_seta_button.text, "Seta");

    Rectangle r5 = {60, (S_a - 160), botao_menu.width*0.4, botao_menu.height*0.4};
    historias.h_menu_button.rec = r5;
    historias.h_menu_button.text_color = RAYWHITE;
    historias.h_menu_button.color = BLACK;
    Color b, t;
    b = historias.h_menu_button.color;
    t = historias.h_menu_button.text_color;
    Mouse_Button(&historias.h_menu_button, 'M', b, t);

    Rectangle r9 = {S_l-60 - seta.width, (S_a - 160), seta.width*0.4, seta.height*0.4};
    historias.h_seta_button.rec = r9;
    historias.h_seta_button.text_color = RAYWHITE;
    historias.h_seta_button.color = BLACK;  
}


void HistoriaUpdate()
{
    Rectangle r5 = {60, (S_a - 160), botao_menu.width*0.4, botao_menu.height*0.4};
    historias.h_menu_button.rec = r5;
    historias.BackGround_color = BLACK;
    historias.Tiltle_color = RAYWHITE;

    Rectangle r9 = {S_l-60 - seta.width, (S_a - 160), seta.width*0.4, seta.height*0.4};
    historias.h_seta_button.rec = r5;
    historias.h_seta_button.text_color = RAYWHITE;
    historias.h_seta_button.color = BLACK;
    


    switch (fase)
    {
    case 1:
        historias.tela_historia = historia_1;
        //botao next
        if(CheckCollisionPointRec(GetMousePosition(), r9))
        {
            if(IsMouseButtonPressed(0))
            {
                fase += 1;
            }
        }
        
        break;
    case 2:
        historias.tela_historia = historia_2;
        //botao next
        if(CheckCollisionPointRec(GetMousePosition(), r9))
        {
            if(IsMouseButtonPressed(0))
            {
                fase += 1;
            }
        }
        break;
    case 3:
        historias.tela_historia = historia_3;
        //botao next
        if(CheckCollisionPointRec(GetMousePosition(), r9))
        {
            if(IsMouseButtonPressed(0))
            {
                fase += 1;
            }
        }
        break;
    case 4:
        historias.tela_historia = historia_4;
        if(CheckCollisionPointRec(GetMousePosition(), r9))
        {
            if(IsMouseButtonPressed(0))
            {
                state = 'M';
                fase = 1;
            }
        }
        break;
    default:  break;
    }




}

void HistoriaDraw()
{


    Color b, t;
    b = historias.h_menu_button.color;
    t = historias.h_menu_button.text_color;
    Mouse_Button(&historias.h_menu_button, 'M', b, t);
    ClearBackground(historias.BackGround_color);
    float scale = 2.0f;
    Vector2 position = {0, 0};
    DrawTextureEx(historias.tela_historia, position, 0.0f, scale, WHITE);
    Vector2 mouse = GetMousePosition();
    Vector2 menuzinhoh = {60, S_a - 150};
    Rectangle r3 = {60, (S_a - 160), botao_menu.width*0.4, botao_menu.height*0.4};
    if (CheckCollisionPointRec(mouse, r3)) {
        DrawTextureEx(botao_menu_pressionando, menuzinhoh, 0, 0.4 , WHITE);
    } else {
        DrawTextureEx(botao_menu, menuzinhoh, 0, 0.4, WHITE);
    }
    Vector2 setinha = {S_l-60 - historias.h_seta_button.rec.width, S_a - 150};
    Rectangle r9 = {S_l-60 - historias.h_seta_button.rec.width, (S_a - 160), botao_menu.width*0.2-20, botao_menu.height*0.4-20};
    if (CheckCollisionPointRec(mouse, r9)) {
        DrawTextureEx(seta_pressionada, setinha, 0, 0.4 , WHITE);
    } else {
        DrawTextureEx(seta, setinha, 0, 0.4, WHITE);
    }
    
}
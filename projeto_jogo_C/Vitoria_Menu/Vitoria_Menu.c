#include "raylib.h"
#include "General_Classes/Screen_Details.h"
#include "General_Classes/Button.h"
#include "State_Manager.h"
#include "Vitoria_Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void CreateVitoria()
{
    strcpy(victory.menu_button.text, "Menu");

    victory.menu_button.start1 = botao_menu;
    victory.menu_button.start2 = botao_menu_pressionando;
    victory.menu_button.rec.x = S_l/2-600;
    victory.menu_button.rec.y = S_a/1.5;
    victory.menu_button.rec.height = 200;
    victory.menu_button.rec.width = 600;
    victory.menu_button.rec.x -= victory.menu_button.rec.width/2;
    victory.menu_button.tx = victory.menu_button.rec.x + victory.menu_button.rec.width/2 - 55;
    victory.menu_button.ty = victory.menu_button.rec.y + victory.menu_button.rec.height/4;
    victory.tela_vitoria = tela_vitoria;
    victory.menu_button.text_color = RAYWHITE;
    victory.menu_button.color = BLACK;    
}


void VitoriaUpdate()
{
    Color b, t;
    b = victory.menu_button.color;
    t = victory.menu_button.text_color;
    victory.tela_vitoria = tela_vitoria;
    victory.BackGround_color = BLACK;
    victory.Tiltle_color = RAYWHITE;
    Mouse_Button(&victory.menu_button, 'M', b, t);
}

void VitoriaDraw()
{
    ClearBackground(victory.BackGround_color);
    float scale = 2.0f;
    Vector2 position = {0, 0};
    DrawTextureEx(victory.tela_vitoria, position, 0.0f, scale, WHITE);
    Vector2 mouse = GetMousePosition();
    Rectangle r1 ={ S_l/2-900, S_a/1.5-5, 500, 240};
    if (CheckCollisionPointRec(mouse, r1)) {
        DrawTexture(botao_menu_pressionando, victory.menu_button.rec.x, victory.menu_button.rec.y, WHITE);
    } else {
        DrawTexture(botao_menu, victory.menu_button.rec.x, victory.menu_button.rec.y, WHITE);
    }
}
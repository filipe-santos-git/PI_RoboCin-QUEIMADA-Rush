#include "raylib.h"
#include "Vtoria_Menu.h"
#include "General_Classes/Screen_Details.h"
#include "General_Classes/Button.h"
#include "State_Manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vitoria vitoria;


void MenuButton()
{
    vitoria.menu_button = proxima_fase;
    vitoria.menu_button.rec.x = S_l/2;
    vitoria.menu_button.rec.y = S_a/1.5;
    vitoria.menu_button.rec.height = 200;
    vitoria.menu_button.rec.width = 600;
    vitoria.menu_button.rec.x -= vitoria.menu_button.rec.width/2;
    vitoria.menu_button.tx = vitoria.menu_button.rec.x + vitoria.menu_button.rec.width/2 - 55;
    vitoria.menu_button.ty = vitoria.menu_button.rec.y + vitoria.menu_button.rec.height/4;
    vitoria.tela_vitoria = tela_vitoria;
    vitoria.menu_button.text_color = RAYWHITE;
    vitoria.menu_button.color = BLACK;
    Color b, t;
    b = vitoria.menu_button.color;
    t = vitoria.menu_button.text_color;

    Mouse_Button(&vitoria.menu_button, 'M', b, t);
}


void VitoriaUpdate()
{
    vitoria.tela_vitoria = tela_vitoria;
    vitoria.BackGround_color = BLACK;
    vitoria.Tiltle_color = RAYWHITE;
    MenuButton();
}

void VitoriaDraw()
{
    ClearBackground(vitoria.BackGround_color);
    float scale = 2.0f;
    Vector2 position = {0, 0};
    DrawTextureEx(vitoria.tela_vitoria, position, 0.0f, scale, WHITE);
    Vector2 mouse = GetMousePosition();
    if (CheckCollisionPointRec(mouse, vitoria.menu_button.rec)) {
        DrawTexture(proxima_fase, vitoria.menu_button.rec.x, vitoria.menu_button.rec.y, WHITE);
    } else {
        DrawTexture(proxima_fase, vitoria.menu_button.rec.x, vitoria.menu_button.rec.y, WHITE);
    }
}
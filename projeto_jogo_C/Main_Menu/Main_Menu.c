#include "raylib.h"
#include "Main_Menu.h"
#include "General_Classes/Screen_Details.h"
#include "General_Classes/Button.h"
#include "State_Manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Menu menu;


void StartButton()
{
    
    strcpy(menu.button.text, "Start");

    menu.button.rec.x = S_l/2;
    menu.button.rec.y = S_a/1.5;
    menu.button.rec.height = 200;
    menu.button.rec.width = 600;
    menu.button.rec.x -= menu.button.rec.width/2;
    menu.button.tx = menu.button.rec.x + menu.button.rec.width/2 - 55;
    menu.button.ty = menu.button.rec.y + menu.button.rec.height/4;
    menu.start1 = start1;
    menu.start2 = start2;
    menu.sair= sair;
    menu.sair_azul= sair_azul;
    menu.tente_novamente = tente_novamente;
    menu.tente_novamente_2= tente_novamente_2;
    menu.button.text_color = RAYWHITE;
    menu.button.color = BLACK;
    Color b, t;
    b = menu.button.color;
    t = menu.button.text_color;

    Mouse_Button(&menu.button, 'G', b, t);
}


void MenuUpdate()
{
    menu.menu = menu_imagem;
    menu.game_over = game_over;
    menu.BackGround_color = BLACK;
    menu.Tiltle_color = RAYWHITE;
    StartButton();
}

void MenuDraw()
{
    ClearBackground(menu.BackGround_color);
    float scale = 2.0f;
    Vector2 position = {0, 0};
    DrawTextureEx(menu.menu, position, 0.0f, scale, WHITE);
    Vector2 mouse = GetMousePosition();
    if (CheckCollisionPointRec(mouse, menu.button.rec)) {
        DrawTexture(menu.start2, menu.button.rec.x, menu.button.rec.y, WHITE);
    } else {
        DrawTexture(menu.start1, menu.button.rec.x, menu.button.rec.y, WHITE);
    }
}
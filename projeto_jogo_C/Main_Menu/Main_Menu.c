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
    S_a = GetScreenHeight();
    S_l = GetScreenWidth();
    strcpy(menu.button.text, "Start");

    menu.button.rec.x = S_l/2;
    menu.button.rec.y = 500;
    menu.button.rec.height = 100;
    menu.button.rec.width = 300;
    menu.button.rec.x -= menu.button.rec.width/2;
    menu.button.tx = menu.button.rec.x + menu.button.rec.width/2 - 55;
    menu.button.ty = menu.button.rec.y + menu.button.rec.height/4;
    menu.button.text_color = RAYWHITE;
    menu.button.color = BLACK;
    Color b, t;
    b = menu.button.color;
    t = menu.button.text_color;

    Mouse_Button(&menu.button, 'G', b, t);
}


void MenuUpdate()
{
    

    menu.BackGround_color = BLACK;
    menu.Tiltle_color = RAYWHITE;
    StartButton();
    
    
}

void MenuDraw()
{
    ClearBackground(menu.BackGround_color);
    strcpy(menu.Title, "ACM Super Final Boss");
    DrawText(menu.Title, S_l/2 - 625, 100, 110, menu.Tiltle_color);
    strcpy(menu.Title, "Queimada Rush!!");
    DrawText(menu.Title, S_l/2 - 250, 300, 70, menu.Tiltle_color);
    DrawRectangleRec(menu.button.rec, menu.button.color);
    DrawRectangleLinesEx(menu.button.rec, 5, RAYWHITE);
    DrawText(menu.button.text, menu.button.tx, menu.button.ty, 40, menu.button.text_color);
}
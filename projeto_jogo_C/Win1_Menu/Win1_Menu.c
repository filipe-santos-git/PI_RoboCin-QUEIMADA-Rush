#include "raylib.h"
#include "Win1_Menu.h"
#include "General_Classes/Screen_Details.h"
#include "General_Classes/Button.h"
#include "State_Manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Win win;


void PFaseButton()
{
    
    strcpy(win.menu_button.text, "next_stage");

    win.menu_button.start1 = next_stage;
    win.menu_button.start2 = next_stage_pressionado;
    win.menu_button.rec.x = S_l/2;
    win.menu_button.rec.y = S_a/1.5;
    win.menu_button.rec.height = 200;
    win.menu_button.rec.width = 600;
    win.menu_button.rec.x -= win.menu_button.rec.width/2;
    win.tela_win = tela_win;
    win.menu_button.text_color = RAYWHITE;
    win.menu_button.color = BLACK;

}


void Win1Update()
{   
    Color b, t;
    b = win.menu_button.color;
    t = win.menu_button.text_color;
    win.tela_win = tela_win;
    win.BackGround_color = BLACK;
    win.Tiltle_color = RAYWHITE;

    Mouse_Button(&win.menu_button, 'G', b, t);
}

void Win1Draw()
{
    PFaseButton();
    ClearBackground(win.BackGround_color);
    float scale = 2.0f;
    Vector2 position = {0, 0};
    DrawTextureEx(win.tela_win, position, 0.0f, scale, WHITE);
    Vector2 mouse = GetMousePosition();
    Rectangle r ={ S_l/2-300, S_a/1.5-5, 690, 297};
    if (CheckCollisionPointRec(mouse, r)) {
        DrawTexture(next_stage_pressionado, win.menu_button.rec.x, win.menu_button.rec.y, WHITE);
    } else {
        DrawTexture(next_stage, win.menu_button.rec.x, win.menu_button.rec.y, WHITE);
    }
}
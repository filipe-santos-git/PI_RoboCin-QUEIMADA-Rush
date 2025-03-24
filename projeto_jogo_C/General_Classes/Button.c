#include "raylib.h"
#include "State_Manager.h"
#include "Screen_Details.h"
#include "Gameplay/player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void Mouse_Button(Button *button, char s, Color b, Color t)
{
    Vector2 posB = {S_l/2, S_a/2 + 90};
    Vector2 mouse = GetMousePosition();
    if(mouse.x >= button->rec.x && mouse.x <= button->rec.x + button->rec.width 
    && mouse.y >= button->rec.y && mouse.y <= button->rec.y + button->rec.height)
    {
        button->color = t;
        button->text_color = b;
        if(IsMouseButtonPressed(0)){ state = s; if(state == 'G') {arena.TimeGame = GetTime();} Blanky.pos = posB;}
    }
    else{ button->color = b; button->text_color = t;}
}

void ButtonDraw(Button *button)
{
    DrawRectangleRec(button->rec, button->color);
}
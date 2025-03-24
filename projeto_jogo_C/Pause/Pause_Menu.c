#include "raylib.h"
#include "Pause_Menu.h"
#include "General_Classes/Screen_Details.h"
#include "Gameplay/Arena.h"
#include "General_Classes/Button.h"
#include "State_Manager.h"
#include "Gameplay/Ataques/Ball.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Pause pause;
Button p_menu, resume;


void CreatePause()
{
    S_a = GetScreenHeight();
    S_l = GetScreenWidth();
    Rectangle rec_back = {0, 0, S_l, S_a};
    pause.rec_back = rec_back;
    Color back = {100, 100, 100, 70};
    pause.back = back;

    Rectangle rec_menu = {S_l/2, S_a/2, 700, 400};
    pause.rec_menu = rec_menu;
    pause.rec_menu.x -= pause.rec_menu.width/2;
    pause.rec_menu.y -= pause.rec_menu.height/2;
    pause.color_rec = BLACK;

    strcpy(pause.Text, "Pause");
    pause.fonte_tam = 60;
    pause.text_color = RAYWHITE;
    pause.tx = S_l/2 - 90;
    pause.ty = 60;

    Rectangle button = {pause.rec_menu.x, pause.rec_menu.y, 200, 150};
    p_menu.rec = button;
    p_menu.rec.x += 70;
    p_menu.rec.y += pause.rec_menu.y/4;
    p_menu.color = RAYWHITE;


    
    resume.rec = button;
    resume.rec.x += 425;
    resume.rec.y += pause.rec_menu.y/4;
    resume.color = RAYWHITE;





}

void PauseUpdate()
{
    Vector2 mouse = GetMousePosition();
    if(mouse.x > p_menu.rec.x && mouse.x < p_menu.rec.x + p_menu.rec.width &&
       mouse.y > p_menu.rec.y && mouse.y < p_menu.rec.y + p_menu.rec.height)
    {
        p_menu.color = RED;
        if(IsMouseButtonPressed(0)) {state = 'M'; DeEspawn(); DeEspawnR_Ball(); DeEspawn_S(); DeEspawnB_Ball();}
    } else {p_menu.color = RAYWHITE;}

    if(mouse.x > resume.rec.x && mouse.x < resume.rec.x + resume.rec.width &&
       mouse.y > resume.rec.y && mouse.y < resume.rec.y + resume.rec.height)
    {
        resume.color = GREEN;
        if(IsMouseButtonPressed(0)) {state = 'G';}
    } else {resume.color = RAYWHITE;}
}

void PauseDraw()
{
    DrawRectangleRec(pause.rec_back, pause.back);
    DrawRectangleRec(pause.rec_menu, pause.color_rec);
    DrawRectangleRec(p_menu.rec, p_menu.color);
    DrawRectangleRec(resume.rec, resume.color);
    DrawText(pause.Text, pause.tx, pause.ty, pause.fonte_tam, pause.text_color);
    DrawText(arena.time, 20, 30, 40, GREEN);

}
#include "raylib.h"
#include "General_Classes/Button.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Button over_resume;
Button main_menu;

Color bm, tm;
Color br, tr;
void CreateGameOver()
{

    main_menu.rec.width = 300;
    main_menu.rec.height = 100;
    main_menu.rec.x = GetScreenWidth()/10;
    main_menu.rec.y = GetScreenHeight()/1.5;
    main_menu.color = MAROON;
    main_menu.rec.x += main_menu.rec.width/2;
    main_menu.rec.y += main_menu.rec.height/2;
    main_menu.text_color = RAYWHITE;
    bm = main_menu.color;
    tm = main_menu.text_color;


    over_resume.rec.width = 300;
    over_resume.rec.height = 100;
    over_resume.rec.x = 5 * GetScreenWidth() / 10;
    over_resume.rec.y = GetScreenHeight()/1.5;
    over_resume.color = LIME;
    over_resume.rec.x += over_resume.rec.width/2;
    over_resume.rec.y += over_resume.rec.height/2;
    over_resume.text_color = RAYWHITE;
    br = over_resume.color;
    tr = over_resume.text_color;



}

void GameOverUpdate()
{
    Mouse_Button(&main_menu, 'M', bm, tm);
    Mouse_Button(&over_resume, 'G', br, tr);
}

void GameOverDraw()
{
    ClearBackground(BLACK);
    ButtonDraw(&main_menu);
    ButtonDraw(&over_resume);
    DrawText("Game Over", 450, 300, 100, RED);
}
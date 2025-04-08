#include "raylib.h"
#include "General_Classes/Button.h"
#include "General_Classes/Screen_Details.h"
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
    main_menu.rec.x = S_l/2;
    main_menu.rec.y = S_a/1.5;
    main_menu.color = MAROON;
    main_menu.rec.x -= main_menu.rec.width/2 + 500;
    main_menu.rec.y -= main_menu.rec.height/2;
    main_menu.text_color = RAYWHITE;
    bm = main_menu.color;
    tm = main_menu.text_color;


    over_resume.rec.width = 300;
    over_resume.rec.height = 100;
    over_resume.rec.x = 5 * GetScreenWidth() / 10;
    over_resume.rec.y = S_a/1.5;
    over_resume.color = LIME;
    over_resume.rec.x -= over_resume.rec.width/2 - 500;
    over_resume.rec.y -= over_resume.rec.height/2;
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
    float scale = 2.0f;
    Vector2 position = {0, 0};
    DrawTextureEx(menu.game_over, position, 0.0f, scale, WHITE);
    float scale2 = 0.5f;
    Vector2 position2 = {main_menu.rec.x, main_menu.rec.y};
    
    if (CheckCollisionPointRec(GetMousePosition(), main_menu.rec))
    {
        DrawTextureEx(menu.sair_azul, position2, 0.0f, scale2, WHITE);  
    }
    else
    {
        DrawTextureEx(menu.sair, position2, 0.0f, scale2, WHITE);
    }

    float scale3 = 0.5f;
    Vector2 position3 = {over_resume.rec.x, over_resume.rec.y};
    
    if (CheckCollisionPointRec(GetMousePosition(), over_resume.rec))
    {
        DrawTextureEx(menu.tente_novamente_2, position3, 0.0f, scale3, WHITE);
    }
    else
    {
        DrawTextureEx(menu.tente_novamente, position3, 0.0f, scale3, WHITE); 
    }

    // Desenha o tempo
    DrawText(arena.time, S_l / 2 - 60, S_a / 1.7, 200, RAYWHITE);
}

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
    menu.tente_novamente = tente_novamente;
    menu.button.text_color = RAYWHITE;
    menu.button.color = BLACK;
    Color b, t;
    b = menu.button.color;
    t = menu.button.text_color;
    Rectangle r2 = {60, (S_a - 160), instrucoes.width*0.4, instrucoes.height*0.4};
    menu.instruction.rec = r2;
    Rectangle r6 = {60,(S_a - 270), creditos.width*0.4,creditos.height*0.4};
    menu.creditos.rec = r6;
    Rectangle r10 = {60, (S_a - 390), historia.width*0.4, historia.height*0.4};
    menu.historia.rec = r10;
    Mouse_Button(&menu.button, 'G', b, t);
    Mouse_Button(&menu.instruction, 'I', b, t);
    Mouse_Button(&menu.creditos, 'C', b, t);
    Mouse_Button(&menu.historia, 'H', b, t);


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

    Vector2 instrucao = {60, S_a - 130};
    Rectangle r2 = {60, (S_a - 140), instrucoes.width*0.4, instrucoes.height*0.4};
    if (CheckCollisionPointRec(mouse, r2)) {
        DrawTextureEx(instrucoes_pressionado, instrucao, 0, 0.4 , WHITE);
    } else {
        DrawTextureEx(instrucoes, instrucao, 0, 0.4, WHITE);
    }

    Vector2 credito = {60, S_a - 240};
    Rectangle r3 = {60, (S_a - 250), creditos.width*0.4, creditos.height*0.4};
    if (CheckCollisionPointRec(mouse, r3)) {
        DrawTextureEx(creditos, credito, 0, 0.4 , WHITE);
    } else {
        DrawTextureEx(creditos_pressionado, credito, 0, 0.4, WHITE);
    }
    Vector2 hist = {60, S_a - 350};
    Rectangle r4 = {60, (S_a - 360), historia.width*0.4, historia.height*0.4};
    if (CheckCollisionPointRec(mouse, r4)) {
        DrawTextureEx(historia, hist, 0, 0.4 , WHITE);
    } else {
        DrawTextureEx(historia_pressionado, hist, 0, 0.4, WHITE);
    }
}
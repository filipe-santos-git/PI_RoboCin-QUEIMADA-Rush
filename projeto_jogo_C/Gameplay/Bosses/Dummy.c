#include "raylib.h"
#include "Bosses.h"
#include "Gameplay/Arena.h"
#include "Gameplay/player.h"
#include "General_Classes/Screen_Details.h"
#include "Gameplay/Ataques/Ball.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "State_Manager.h"

Color norm = RED, met = ORANGE;

double EscolherAtaque(int num,  double mana)
{
    switch (num)
    {
    case 1:
        if(mana > 2.5)
        {
            mana = 0;
            switch (dummy.B)
            {
            case 1:
                CreateBall_to_player(3, dummy.B);
                CreateBall_to_player(4, dummy.B);
                CreateBall_to_player(3, dummy.B);
                break;
            case 2:
                CreateBall_to_player(GetRandomValue(3, 6), dummy.B);
                CreateBall_to_player(GetRandomValue(3, 6), dummy.B);
                CreateBall_to_player(GetRandomValue(3, 6), dummy.B);
                break;
            
            default:
                break;
            }
            
            
        }
        break;
    
    case 2:
        if(mana > 0.6)
        {
            mana = 0;
            switch (dummy.B)
            {
            case 1: 
                //CreateS_ball(1600, S_a/2 - 100, 800, dummy.B);
                CreateS_ball(1600, S_a/2 - 50, 800, dummy.B);
                CreateS_ball(1600, S_a/2 + 50, 800, dummy.B);
                CreateS_ball(1600, S_a/2 + 100, 800, dummy.B);
                CreateS_ball(1600, S_a/2 + 200, 800, dummy.B);
                //CreateS_ball(1600, S_a/2 + 250, 800, dummy.B);
                break;
            
            case 2:
                CreateS_ball(1600, S_a/2, 900, dummy.B);
                break;
            default:
                break;
            }
        }
        break;
    
    case 3:
        if(mana > 0.4)
        {
            mana = 0;
            switch (dummy.B)
            {
            case 1: 
                CreateB_Ball(400, dummy.B);
                break;
            case 2:
                CreateB_Ball(650, dummy.B);
                break;
            default:
                break;
            }
            
        }
    default:
        break;
    }
    return mana;
}
int last_a;
int N_AT;

int health;
void CreateDummy()
{
    dummy.nivel = robocin_nivel_1;
    dummy.atordoado = robocin_atordoado;
    dummy.B = 1;
    dummy.pos.x = S_l/2;
    dummy.pos.y = S_a/12;
    dummy.vel.x = 0;
    dummy.vel.y = 0;
    dummy.mana = 0;
    dummy.ataque = 0;
    dummy.height = 110;
    dummy.width = 300;
    dummy.pos.x -= dummy.width/2;
    dummy.pos.y -= dummy.height/2;
    dummy.hp = 100;
    health = dummy.hp;
    dummy.start_attack = GetTime();
    N_AT = GetRandomValue(1,3);
    last_a = N_AT;

}

Color tone;  
void DummyUpdate(float dt)
{
    Rectangle rec = {dummy.pos.x, dummy.pos.y, dummy.width, dummy.height};
    dummy.rec = rec;

    int var = 0;
    switch (last_a)
    {
    case 1: var = 3; break;
    case 2: var = 7; break;
    case 3: var = 5; break;
    default: break;
    }

    dummy.mana += 5 *dt;
    if(GetTime() > 23 -(10 - var)  + dummy.start_attack) {last_a = N_AT; N_AT = GetRandomValue(1,3); dummy.start_attack = GetTime(); if(Blanky.dano == 0) {CreateCoracao();} Blanky.dano = 0;}
    else if(GetTime() > var + dummy.start_attack) 
    {dummy.mana = EscolherAtaque(N_AT, dummy.mana);}
    
    

    BallUpdate(dt);
    S_BallUpdate(dt);
    B_BallUpdate(dt);

    
    if(dummy.hp > 0) 
    {
        Color Tone = {255, 255/(health/dummy.hp), 255/(health/dummy.hp), 255};
        tone = Tone;
    }
    
    
    if (GetTime() < dummy.hitted + 0.3) {dummy.atual = dummy.atordoado;}
    else {dummy.atual = dummy.nivel;}



    if(dummy.hp <= 97 && dummy.B == 1) 
    {
        DeEspawn(); 
        DeEspawnR_Ball(); 
        DeEspawn_S(); 
        DeEspawnB_Ball(); 
        state = 'W';
    }
    if(dummy.hp <= 197 && dummy.B == 2)
    {
        DeEspawn(); 
        DeEspawnR_Ball(); 
        DeEspawn_S(); 
        DeEspawnB_Ball(); 
        state = 'M';
    }




}

void DummyDraw()
{
    char mana[10];
    sprintf(mana, "%i", dummy.hp);
    DrawText(mana, (S_l-200), S_a/7, 80, BLACK);
    //DrawRectangle(0,0, dummy.mana * 100, 30, PURPLE);
    float scale = 1.3f;
    float textureWidth = dummy.width * scale;
    float textureHeight = dummy.height * scale;
    Vector2 spritePosition =  {(dummy.pos.x - textureWidth/2), (dummy.pos.y - textureHeight/2)};
    DrawTextureEx(dummy.atual, spritePosition, 0.0f, scale, tone);
    CoracaoDraw();
    CoracaoDraw();
    BallDraw();
    S_BallDraw();
    B_BallDraw();
}



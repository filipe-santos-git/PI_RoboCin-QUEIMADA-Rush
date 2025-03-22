#include "raylib.h"
#include "Bosses.h"
#include "Gameplay/Arena.h"
#include "Gameplay/player.h"
#include "General_Classes/Screen_Details.h"
#include "Gameplay/Ataques/Ball.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





double EscolherAtaque(int num,  double mana)
{
    switch (num)
    {
    case 1:
        if(mana > 2.5)
        {
            mana = 0;
            CreateBall_to_player();
            CreateBall_to_player();
            CreateBall_to_player();
            
        }
        break;
    
    case 2:
        if(mana > 0.6)
        {
            mana = 0;
            CreateS_ball(1600);
            //CreateS_ball(400);
        }
    
    default:
        break;
    }
    return mana;
}

int N_AT;
void CreateDummy()
{
    dummy.pos.x = S_l/2;
    dummy.pos.y = S_a/12;
    dummy.vel.x = 0;
    dummy.vel.y = 0;
    dummy.mana = 0;
    dummy.ataque = 0;
    dummy.height = 80;
    dummy.width = 300;
    dummy.pos.x -= dummy.width/2;
    dummy.pos.y -= dummy.height/2;
    dummy.color = RED;
    Rectangle rec = {dummy.pos.x, dummy.pos.y, dummy.width, dummy.height};
    dummy.rec = rec;
    dummy.hp = 70;
    dummy.start_attack = GetTime();
    N_AT = GetRandomValue(1,2);

}


void DummyUpdate(float dt)
{
    int var;

    dummy.mana += 5 *dt;
    if(N_AT == 2) {var = 2;}
    else {var = 7;}
    if(GetTime() > 23 -(10 - var)  + dummy.start_attack) {N_AT = GetRandomValue(1,2); dummy.start_attack = GetTime();}
    else if(GetTime() > var + dummy.start_attack) 
    {dummy.mana = EscolherAtaque(N_AT, dummy.mana);}
    
    

    BallUpdate(dt);
    S_BallUpdate(dt);
    if(GetTime() > dummy.hitted + 0.3)
    {
        if(dummy.hp > 35){dummy.color = RED;}
        else if(dummy.hp >= 10) {dummy.color = ORANGE;}
        else {dummy.color.a = 128;}
    }




}

void DummyDraw()
{
    char mana[10];
    sprintf(mana, "%.4f", GetTime());
    DrawText(mana, S_l/2, S_a/2, 40, GRAY);
    //DrawRectangle(0,0, dummy.mana * 100, 30, PURPLE);
    DrawRectangle(dummy.pos.x, dummy.pos.y, dummy.width, dummy.height, dummy.color);
    BallDraw();
    S_BallDraw();
}



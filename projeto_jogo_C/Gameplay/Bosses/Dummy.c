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
        }
        break;
    
    case 3:
        if(mana > 0.4)
        {
            mana = 0;
            CreateB_Ball();
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
    dummy.color = RED;
    Rectangle rec = {dummy.pos.x, dummy.pos.y, dummy.width, dummy.height};
    dummy.rec = rec;
    dummy.hp = 200;
    health = dummy.hp;
    dummy.start_attack = GetTime();
    N_AT = GetRandomValue(1,3);
    last_a = N_AT;

}


void DummyUpdate(float dt)
{
    int var = 0;
    switch (last_a)
    {
    case 1: var = 3; break;
    case 2: var = 7; break;
    case 3: var = 5; break;
    default:
        break;
    }

    dummy.mana += 5 *dt;
    if(GetTime() > 23 -(10 - var)  + dummy.start_attack) {last_a = N_AT; N_AT = GetRandomValue(1,3); dummy.start_attack = GetTime();}
    else if(GetTime() > var + dummy.start_attack) 
    {dummy.mana = EscolherAtaque(N_AT, dummy.mana);}
    
    

    BallUpdate(dt);
    S_BallUpdate(dt);
    B_BallUpdate(dt);
    if(GetTime() > dummy.hitted + 0.3)
    {
        if(dummy.hp > health/2){dummy.color = RED;}
        else if(dummy.hp >= health/4) {dummy.color = ORANGE;}
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
    B_BallDraw();
}



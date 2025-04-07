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
    dummy.color = norm;
    dummy.hp = 100;
    health = dummy.hp;
    dummy.start_attack = GetTime();
    N_AT = GetRandomValue(1,3);
    last_a = N_AT;

}


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
    default:
        break;
    }

    dummy.mana += 5 *dt;
    if(GetTime() > 23 -(10 - var)  + dummy.start_attack) {last_a = N_AT; N_AT = GetRandomValue(1,3); dummy.start_attack = GetTime();}
    else if(GetTime() > var + dummy.start_attack) 
    {dummy.mana = EscolherAtaque(1, dummy.mana);}
    
    

    BallUpdate(dt);
    S_BallUpdate(dt);
    B_BallUpdate(dt);
    if(GetTime() > dummy.hitted + 0.3)
    {
        if(dummy.hp > health/2){dummy.color = norm;}
        else if(dummy.hp >= health/4) {dummy.color = met;}
        else {dummy.color.a = 200;}
    }


    if(dummy.hp <= 0 && dummy.B == 1) 
    {
        norm = BROWN;
        met = DARKBROWN;
        dummy.width = 90;
        dummy.height = 90;
        dummy.pos.x = S_l/2 - dummy.width/2;
        dummy.pos.y = S_a/12 - dummy.height/2;
        dummy.hp = 200;
        health = dummy.hp;
        dummy.B++;
    }
    if(dummy.hp <= 0 && dummy.B == 2)
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
    DrawText(mana, S_l/2, S_a/2, 40, GRAY);
    //DrawRectangle(0,0, dummy.mana * 100, 30, PURPLE);
    DrawRectangle(dummy.pos.x, dummy.pos.y, dummy.width, dummy.height, dummy.color);
    BallDraw();
    S_BallDraw();
    B_BallDraw();
}



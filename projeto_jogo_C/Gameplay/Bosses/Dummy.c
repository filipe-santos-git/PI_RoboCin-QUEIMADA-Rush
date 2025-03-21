#include "raylib.h"
#include "Bosses.h"
#include "Gameplay/Arena.h"
#include "Gameplay/player.h"
#include "General_Classes/Screen_Details.h"
#include "Gameplay/Ataques/Ball.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void HitDummy()
{

}


void CreateDummy()
{
    dummy.pos.x = S_l/2;
    dummy.pos.y = S_a/12;
    dummy.vel.x = 0;
    dummy.vel.y = 0;
    dummy.mana = 0;
    dummy.mana2 = 0;
    dummy.ataque = 0;
    dummy.height = 80;
    dummy.width = 300;
    dummy.pos.x -= dummy.width/2;
    dummy.pos.y -= dummy.height/2;
    dummy.color = RED;
    Rectangle rec = {dummy.pos.x, dummy.pos.y, dummy.width, dummy.height};
    dummy.rec = rec;
    dummy.hp = 70;

}

int test = 1;
void DummyUpdate(float dt)
{
    dummy.mana += 5 *dt;
    dummy.mana2 += 5*dt;
    if(dummy.mana >= 2.5)
    {
        dummy.mana = 0;
        //CreateBall_to_player();
        //CreateBall_to_player();
        //CreateBall_to_player();
        
        test = 0;
    }
    if(dummy.mana2 >= 0.5) { dummy.mana2 = 0; CreateS_ball();}
    

    BallUpdate(dt);
    S_BallUpdate(dt);


    if(dummy.hit == 1) {}



}

void DummyDraw()
{
    char mana[10];
    sprintf(mana, "%.4f", dummy.mana);
    DrawText(mana, S_l/2, S_a/2, 40, GRAY);
    //DrawRectangle(0,0, dummy.mana * 100, 30, PURPLE);
    DrawRectangle(dummy.pos.x, dummy.pos.y, dummy.width, dummy.height, dummy.color);
    BallDraw();
    S_BallDraw();
}



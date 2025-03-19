#include "raylib.h"
#include "Bosses.h"
#include "Gameplay/Arena.h"
#include "Gameplay/player.h"
#include "General_Classes/Screen_Details.h"
#include "Gameplay/Ataques/Ball.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void CreateDummy()
{
    S_l = GetScreenWidth();
    S_a = GetScreenHeight();
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

}

void DummyUpdate(float dt)
{
    dummy.mana += 5 *dt;
    if(dummy.mana >= 2.5)
    {
        dummy.mana = 0;
        CreateBall_to_player();
        CreateBall_to_player();
        CreateBall_to_player();
    }

    BallUpdate(dt);



}

void DummyDraw()
{
    char mana[10];
    sprintf(mana, "%.4f", dummy.mana);
    DrawText(mana, S_l/2, S_a/2, 40, GRAY);
    //DrawRectangle(0,0, dummy.mana * 100, 30, PURPLE);
    DrawRectangle(dummy.pos.x, dummy.pos.y, dummy.width, dummy.height, dummy.color);
    BallDraw();
}



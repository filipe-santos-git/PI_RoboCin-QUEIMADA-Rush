#include "raylib.h"
#include "Bosses.h"
#include "Gameplay/Arena.h"
#include "Gameplay/player.h"
#include "General_Classes/Screen_Details.h"
#include "Gameplay/Ataques/Ball.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Boss
{
    float height, width, mana;
    Vector2 pos;
    Vector2 vel;
    Vector2 shot_dir;
    int ataque;
    Color color;
}Boss;
Boss dummy;


void CreateDummy()
{
    S_l = GetScreenWidth();
    S_a = GetScreenHeight();
    dummy.pos.x = S_l/16;
    dummy.pos.y = S_a/2;
    dummy.vel.x = 0;
    dummy.vel.y = 0;
    dummy.mana = 0;
    dummy.ataque = 0;
    dummy.height = 470;
    dummy.width = 300;
    dummy.pos.x -= dummy.width/2 - 110;
    dummy.pos.y -= dummy.height/2 + 30;
    dummy.color = RED;

}

void DummyUpdate(float dt)
{
    dummy.mana += 5 *dt;
    if(dummy.mana >= 40)
    {
        dummy.mana = 0;
        int x = GetRandomValue(arena.rec.x, arena.rec.x + arena.rec.width), y = GetRandomValue(arena.rec.y, arena.rec.y + arena.rec.height);
        Vector2 pos = {x, y};
        CreateBall_to_player(pos);
    }

    BallUpdate(dt);



}

void DummyDraw()
{
    char mana[10];
    sprintf(mana, "%.4f", dummy.mana);
    DrawText(mana, S_l/2, S_a/2, 40, GRAY);
    DrawRectangle(dummy.pos.x, dummy.pos.y, dummy.width, dummy.height, dummy.color);
    BallDraw();
}



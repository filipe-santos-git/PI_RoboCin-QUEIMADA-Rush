#include "raylib.h"
#include "player.h"
#include "Arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Player Blanky;
double time;


void CreatePlayer()
{
    int S_l = GetScreenWidth();
    int S_a = GetScreenHeight();
    Vector2 pos = {S_l/2, S_a/2};
    Vector2 vel = {0, 0};
    Blanky.vel = vel;
    Blanky.pos = pos;
    Blanky.height = 20;
    Blanky.width = 20;
    Blanky.pos.x -= Blanky.width; Blanky.pos.y -= Blanky.height;
    Blanky.color = BLUE;
    time = GetTime();
}



void GreenState()
{
    double now = GetTime();
    if(IsKeyPressed(32))
    {
        Blanky.color = GREEN; 
        time = GetTime();
    }
    else if(now > time + 0.3) {Blanky.color = BLUE;}
}

void ArenaColision()
{
    if(Blanky.pos.x <= arena.rec.x + arena.line_thick){Blanky.pos.x = arena.rec.x + arena.line_thick;}
    else if(Blanky.pos.x >= arena.rec.x + arena.rec.width - arena.line_thick - Blanky.width) 
    {Blanky.pos.x = arena.rec.x + arena.rec.width - arena.line_thick - Blanky.width;}

    if(Blanky.pos.y <= arena.rec.y + arena.line_thick){Blanky.pos.y = arena.rec.y + arena.line_thick;}
    else if(Blanky.pos.y >= arena.rec.y + arena.rec.height - arena.line_thick - Blanky.height) 
    {Blanky.pos.y = arena.rec.y + arena.rec.height - arena.line_thick - Blanky.height;}
}



void PlayerUpdate(float dt)
{
    float vel = 300;
    if(IsKeyDown(65)) {Blanky.vel.x = -vel;}
    else if(IsKeyDown(68)) {Blanky.vel.x = vel;}
    else {Blanky.vel.x = 0;}
    if(IsKeyDown(83)) {Blanky.vel.y = vel;}
    else if(IsKeyDown(87)) {Blanky.vel.y = -vel;}
    else {Blanky.vel.y = 0;}

    Blanky.pos.x += Blanky.vel.x * dt;
    Blanky.pos.y += Blanky.vel.y * dt;

    ArenaColision();
    GreenState();
    
    
}

void PlayerDraw()
{
    DrawRectangle(Blanky.pos.x, Blanky.pos.y, Blanky.width, Blanky.height, Blanky.color);
}




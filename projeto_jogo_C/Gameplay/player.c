#include "raylib.h"
#include "player.h"
#include "Arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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
    Blanky.ready = 1;
    Blanky.reflect = SKYBLUE;

    Blanky.hp.width = 10;
    Blanky.hp.height = 25;
    Blanky.hp.x = 1100;
    Blanky.hp.y = 300;
    Blanky.hp.color = LIME;
    time = GetTime();

    

}



void GreenState()
{
    Blanky.now = GetTime();
    if((IsKeyPressed(32) || IsMouseButtonPressed(0)) && Blanky.ready == 1)
    {
        Blanky.color = GREEN; 
        Blanky.time = GetTime();
        Blanky.ready = 0;
    }
    else if(Blanky.now > Blanky.time + 0.5) {Blanky.color = BLUE;}
    if(Blanky.now > Blanky.time + 1) {Blanky.ready = 1;}
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
    Rectangle rec = {Blanky.pos.x, Blanky.pos.y, Blanky.width, Blanky.height};
    Blanky.rec = rec;

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

    if(Blanky.hp.width > 10) {Blanky.hp.width = 10;}
    
    
    
}

void PlayerDraw()
{
    double a;
    a = Blanky.now - Blanky.time;
    if(a> 1) { a = 1; Blanky.reflect = GOLD;} else {Blanky.reflect = SKYBLUE;}
    DrawRectangle(Blanky.hp.x, Blanky.hp.y- 50, a * 150, Blanky.hp.height, Blanky.reflect);
    DrawRectangle(Blanky.hp.x, Blanky.hp.y, Blanky.hp.width *  15, Blanky.hp.height, Blanky.hp.color);
    DrawRectangle(Blanky.pos.x, Blanky.pos.y, Blanky.width, Blanky.height, Blanky.color);
    
}




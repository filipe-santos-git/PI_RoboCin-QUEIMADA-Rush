#include "raylib.h"
#include "player.h"
#include "Arena.h"
#include "raymath.h"
#include "General_Classes/Screen_Details.h"
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
    Blanky.dir = vel;
    Blanky.pos = pos;
    Blanky.height = 20;
    Blanky.width = 20;
    Blanky.pos.x -= Blanky.width; Blanky.pos.y -= Blanky.height;
    Blanky.color = BLUE;
    Blanky.ready = 1;
    Blanky.reflect = SKYBLUE;
    Blanky.dash_ready = 1;
    Blanky.dash = LoadSound("assets/audios/effects/dash.wav");
    Blanky.hp.width = 10;
    Blanky.hp.height = 30;
    Blanky.hp.x = 625;
    Blanky.hp.y = 900;
    Blanky.hp.color = LIME;
    time = GetTime();
    Blanky.vel = 300;
    Blanky.tone = WHITE;

    

}



void GreenState()
{
    Blanky.now = GetTime();
    if((IsKeyPressed(32) || IsMouseButtonPressed(0)) && Blanky.ready == 1)
    {
        Blanky.color = GREEN; 
        Blanky.time = GetTime();
        Blanky.hit = 0;
        Blanky.ready = 0;
        Blanky.texture = jogador_ataque;
    }

    else if(Blanky.hit && GetTime() > Blanky.hitted + 0.3 )
    {Blanky.color = BLUE; Blanky.hit = 0; Blanky.texture = jogador; Blanky.tone = WHITE;}
    else if(Blanky.hit != 1 && Blanky.now > Blanky.time + 0.5)
    {Blanky.color = BLUE; Blanky.texture = jogador; Blanky.tone = WHITE;}
    if(Blanky.now > Blanky.time + 0.9) {Blanky.ready = 1;}
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

    if((IsKeyPressed(340) || IsMouseButtonPressed(1)) && Blanky.dash_ready == 1)
    {
        PlaySound(Blanky.dash);
        Blanky.dash_t = GetTime();
        Blanky.vel += 400; 
        Blanky.dash_ready = 0;
    }
    if(Blanky.now > 0.3 + Blanky.dash_t){Blanky.vel = 300;}
    if(Blanky.now > 1 + Blanky.dash_t){Blanky.dash_ready = 1;}

    
    if(IsKeyDown(65)) {Blanky.dir.x = -1;}
    else if(IsKeyDown(68)) {Blanky.dir.x = 1;}
    else {Blanky.dir.x = 0;}
    if(IsKeyDown(83)) {Blanky.dir.y = 1;}
    else if(IsKeyDown(87)) {Blanky.dir.y = -1;}
    else {Blanky.dir.y = 0;}
    Blanky.dir = Vector2Normalize(Blanky.dir);
    Blanky.pos.x += Blanky.dir.x * dt * Blanky.vel;
    Blanky.pos.y += Blanky.dir.y * dt * Blanky.vel;

    ArenaColision();
    GreenState();

    if(Blanky.hp.width > 10) {Blanky.hp.width = 10;}

    
    
    
    
}

void PlayerDraw()
{
    double a;
    a = Blanky.now - Blanky.time;
    if(a> 0.9) { a = 0.9; Blanky.reflect = GOLD;} else {Blanky.reflect = SKYBLUE;}
    DrawRectangle(Blanky.hp.x, Blanky.hp.y- 30, a * 150, Blanky.hp.height, Blanky.reflect);
    DrawRectangle(Blanky.hp.x, Blanky.hp.y, Blanky.hp.width *  70, Blanky.hp.height, Blanky.hp.color);
    DrawRectangle(Blanky.pos.x, Blanky.pos.y, Blanky.width, Blanky.height, Blanky.color);
    Vector2 pos = {Blanky.pos.x - 6, Blanky.pos.y - 6};
    char buffer[20];
    sprintf(buffer, "%0.f", (Blanky.hp.width)*2);
    DrawText(buffer, S_l - 455, S_a / 7, 80, BLACK);
    DrawTextureEx(Blanky.texture, pos, 0.0f, 0.35f, Blanky.tone);
}




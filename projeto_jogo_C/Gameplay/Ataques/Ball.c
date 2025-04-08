#include "raylib.h"
#include "Gameplay/player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ball.h"
#include <math.h>





void CheckState()
{
    if(Blanky.color.r == GREEN.r &&
       Blanky.color.g == GREEN.g &&
       Blanky.color.b == GREEN.b &&
       Blanky.color.a == GREEN.a )
    {
        CreateR_ball();
    }
    else
    {
        Blanky.hp.width -= 0.5 ;
        Blanky.hitted = GetTime();
        Blanky.color = RAYWHITE;
        Blanky.hit = 1;
        Blanky.dano = 1;
    }
}




void HitPlayer()
{
    Ball *temp = ball;
    while(temp != NULL)
    {
        if(temp->pos.x > Blanky.pos.x && 
            temp->pos.x < Blanky.pos.x + Blanky.width && 
            temp->pos.y < Blanky.pos.y + Blanky.height &&
            temp->pos.y > Blanky.pos.y) 
        {
            if(temp == ball)
            {
                ball = ball->next;
                free(temp);
                temp = NULL;
            }
            else
            {
                Ball *colide;
                temp->before->next = temp->next;
                if(temp->next != NULL) {temp->next->before = temp->before;}
                colide = temp;
                temp = temp->before;
                free(colide);
                
            }
            CheckState();

        }
        if(temp != NULL) {temp = temp->next;}

        
    }
}




void DeEspawn()
{
    Ball *temp = ball;
    while(ball != NULL) 
    { 
        ball = ball->next;
        free(temp);
        temp = ball; 
    }    
}




void BallArenaColision()
{
    int S_l = GetScreenWidth(), S_a = GetScreenHeight();
    Ball *temp = ball;
    while(temp != NULL)
    {
        if(temp->pos.x < 5 || 
            temp->pos.x > S_l - 5|| 
            temp->pos.y < 5||
            temp->pos.y > S_a -5) 
        {
            if(temp == ball)
            {
                ball = ball->next;
                free(temp);
                temp = NULL;
            }
            else
            {
                Ball *colide;
                temp->before->next = temp->next;
                if(temp->next != NULL) {temp->next->before = temp->before;}
                colide = temp;
                temp = temp->before;
                free(colide);

            }
        }
        if(temp != NULL) {temp = temp->next;} else {temp = ball;}
    }
}




void CreateBall_to_player(int vel, int type)
{
    Vector2 pos;
    int qual_borda = GetRandomValue(1, 4);
    switch(qual_borda)
    {
        case 1: pos.x = arena.rec.x - arena.rec.width/2;
                pos.y = GetRandomValue(arena.rec.y - arena.rec.height/2, arena.rec.y + arena.rec.height/2); 
                break;
        case 2: pos.x = arena.rec.x + arena.rec.width/2;
                pos.y = GetRandomValue(arena.rec.y - arena.rec.height/2, arena.rec.y + arena.rec.height/2); 
                break;
        case 3: pos.y = arena.rec.y - arena.rec.height/2;
                pos.x = GetRandomValue(arena.rec.x - arena.rec.width/2, arena.rec.x + arena.rec.width/2);
                break;
        case 4: pos.y = arena.rec.y + arena.rec.height/2;
                pos.x = GetRandomValue(arena.rec.x - arena.rec.width/2, arena.rec.x + arena.rec.width/2);
                break;
        default: break;
    }
    pos.x += arena.rec.width/2;
    pos.y += arena.rec.height/2;

    Ball *temp;
    if(ball == NULL)
    {
        temp = ball;
        ball =(Ball *)malloc(sizeof(Ball));
        ball->next = temp;
    }else
    {
        temp = (Ball *)malloc(sizeof(Ball));
        temp->next = ball;
        ball->before = temp;
        ball = temp;
    }
    if(ball == NULL) {exit(1);}
    ball->pos = pos;
    ball->vel = 100 * vel;
    ball->tam = 30;
    Color color = { 255, 161, 0, 255 };
    ball->color = color;
    ball->dir = Blanky.pos;
    Vector2 player_pos = {Blanky.pos.x + Blanky.width/2, Blanky.pos.y + Blanky.height/2}; 
    Vector2 dir = Vector2Normalize(Vector2Subtract(ball->pos, player_pos));
    ball->ball = RedBall;
    dir.x = -dir.x;
    dir.y = -dir.y;
    ball->dir = dir;
}



void BallUpdate(float dt)
{
    Ball *temp = ball;
    while(temp != NULL)
    {
        temp->pos.x += temp->dir.x * dt * temp->vel;
        temp->pos.y += temp->dir.y * dt * temp->vel;
        temp = temp->next;
    }
    BallArenaColision();
    HitPlayer();
    R_BallUpdate(dt);
}

void BallDraw()
{
    Ball *temp = ball;
    while(temp != NULL)
    {
        float scale = 0.025f;
        float textureWidth = RedBall.width * scale;
        float textureHeight = RedBall.height * scale;
        Vector2 spritePosition =  {(temp->pos.x - textureWidth/2), (temp->pos.y - textureHeight/2)};
        DrawTextureEx(ball->ball, spritePosition, 0.0f, scale, WHITE);
        temp = temp->next;
        
    }
    R_BallDraw();
}
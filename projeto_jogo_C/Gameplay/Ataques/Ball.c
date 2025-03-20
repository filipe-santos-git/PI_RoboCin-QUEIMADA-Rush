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
        //
    }
    else
    {
        Blanky.hp.width--;
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
        if(temp != NULL) {temp = temp->next;}
    }
}




void CreateBall_to_player()
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
    ball->vel = 300;
    ball->tam = 10;
    Color color = { 255, 161, 0, 255 };
    ball->color = color;
    ball->dir = Blanky.pos;
    double a = 1/sqrt(1+(pow((((Blanky.pos.y + Blanky.height/2) - ball->pos.y)/((Blanky.pos.x + Blanky.width/2) - ball->pos.x)), 2)));
    ball->dir.x = a;
    ball->dir.y = a * (((Blanky.pos.y + Blanky.height/2) - ball->pos.y)/((Blanky.pos.x + Blanky.width/2) - ball->pos.x));
    if(ball->pos.x > Blanky.pos.x) {ball->dir.x = -ball->dir.x;}
    if(ball->pos.x > Blanky.pos.x) {ball->dir.y = -ball->dir.y;}




    

}



void BallUpdate(float dt)
{
    Ball *temp = ball;
    while(temp != NULL)
    {
        temp->pos.x += temp->dir.x * dt * ball->vel;
        temp->pos.y += temp->dir.y * dt * ball->vel;
        temp = temp->next;
    }
    BallArenaColision();
    HitPlayer();
}

void BallDraw()
{
    Ball *temp = ball;
    while(temp != NULL)
    {
        DrawCircle(temp->pos.x, temp->pos.y, temp->tam, temp->color);
        temp = temp->next;
    }
}
#include "raylib.h"
#include "raymath.h"
#include "Gameplay/Bosses/Bosses.h"
#include "Gameplay/player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ball.h"
#include <math.h>


void HitDummy()
{
    dummy.hp--;
    dummy.hitted = GetTime();
    dummy.color = RAYWHITE;
}

void CalcularFunc()
{
    Vector2 boss_pos = {dummy.pos.x + dummy.width/2, dummy.pos.y + dummy.height/2}; 
    Vector2 dir = Vector2Normalize(Vector2Subtract(r_ball->pos, boss_pos));
    dir.x = -dir.x;
    dir.y = -dir.y;
    r_ball->dir = dir;
}




void CreateR_ball()
{

    Ball *temp;
    if(r_ball == NULL)
    {
        temp = r_ball;
        r_ball =(Ball *)malloc(sizeof(Ball));
        r_ball->next = temp;
    }else
    {
        temp = (Ball *)malloc(sizeof(Ball));
        temp->next = r_ball;
        r_ball->before = temp;
        r_ball = temp;
    }
    if(r_ball == NULL) {exit(1);}
    r_ball->pos = Blanky.pos;
    r_ball->pos.x += Blanky.width/2;
    r_ball->pos.y += Blanky.height/2;
    r_ball->vel = 0;
    r_ball->tam = 10;
    r_ball->acel = 4;
    Color color = VIOLET;
    r_ball->color = color;
    r_ball->dir = dummy.pos;
    r_ball->C = GetTime();
    CalcularFunc();
}

void R_BallUpdate(float dt)
{
    Ball *temp = r_ball;

    while(temp != NULL)
    {
        temp->vel += temp->acel;
        temp->pos.x += temp->dir.x * dt * temp->vel;
        temp->pos.y += temp->dir.y * dt * temp->vel;

        if(CheckCollisionCircleRec(temp->pos, temp->tam, dummy.rec) || GetTime() > 7 + temp->C)
        {
            if(temp == r_ball)
            {
                r_ball = r_ball->next;
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
            HitDummy();
            

        }
        if(temp != NULL) {temp = temp->next;} else {temp = r_ball;}
    }
    
}


void R_BallDraw()
{
    Ball *temp = r_ball;
    while(temp != NULL)
    {
        DrawCircle(temp->pos.x, temp->pos.y, temp->tam, temp->color);
        temp = temp->next;
    }
}

void DeEspawnR_Ball()
{
    Ball *temp = r_ball;
    while(r_ball != NULL) 
    { 
        r_ball = r_ball->next;
        free(temp);
        temp = r_ball; 
    }    
}
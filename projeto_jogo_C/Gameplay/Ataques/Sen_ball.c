#include "raylib.h"
#include "Ball.h"
#include "Gameplay/player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define M_PI		3.14159265358979323846




void S_BallArenaColision()
{
    Ball *temp = s_ball;
    while(temp != NULL)
    {
        if(temp->pos.x < 5 || 
            temp->pos.x > S_l - 5|| 
            temp->pos.y < 5||
            temp->pos.y > S_a -5) 
        {
            if(temp == s_ball)
            {
                s_ball = s_ball->next;
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
        if(temp != NULL) {temp = temp->next;} else {temp = s_ball;}
    }
}



void DeEspawn_S()
{
    Ball *temp = s_ball;
    while(s_ball != NULL) 
    { 
        s_ball = s_ball->next;
        free(temp);
        temp = s_ball; 
    }    
}


void CalcularFunc_S(Ball *temp)
{
    /*Vector2 boss_pos = {dummy.pos.x + dummy.width/2, dummy.pos.y + dummy.height/2}; 
    Vector2 dir = Vector2Normalize(Vector2Subtract(s_ball->pos, boss_pos));
    dir.x = -dir.x;
    dir.y = -dir.y;
    s_ball->dir = dir;*/

    temp->dir.x = -1;
    temp->dir.y = M_PI *(cos(((M_PI/2) * (GetTime() - temp->C))*5)) / 5;
    temp->dir = Vector2Normalize(temp->dir);

}




void CreateS_ball()
{

    Ball *temp;
    if(s_ball == NULL)
    {
        temp = s_ball;
        s_ball =(Ball *)malloc(sizeof(Ball));
        s_ball->next = temp;
    }else
    {
        temp = (Ball *)malloc(sizeof(Ball));
        temp->next = s_ball;
        s_ball->before = temp;
        s_ball = temp;
    }
    if(s_ball == NULL) {exit(1);}
    s_ball->pos.x = 1600;
    s_ball->pos.y = S_a/2;
    s_ball->vel = 900;
    s_ball->tam = 10;
    s_ball->acel = 4;
    Color color = ORANGE;
    s_ball->color = color;
    s_ball->dir = dummy.pos;
    s_ball->C = GetTime();
    
}


void S_BallDraw()
{
    Ball *temp = s_ball;
    while(temp != NULL)
    {
        DrawCircle(temp->pos.x, temp->pos.y, temp->tam, temp->color);
        temp = temp->next;
    }
}


void S_BallUpdate(float dt)
{
    Ball *temp = s_ball;
    while(temp != NULL)
    {
        CalcularFunc_S(temp);
        temp->pos.x += temp->dir.x * dt * s_ball->vel;
        temp->pos.y += temp->dir.y * dt * s_ball->vel;
        if(CheckCollisionCircleRec(temp->pos, temp->tam, Blanky.rec))
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
    S_BallArenaColision();
    
}


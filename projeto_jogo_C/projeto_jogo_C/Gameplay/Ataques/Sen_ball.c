#include "raylib.h"
#include "Ball.h"
#include "Gameplay/player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define M_PI		3.14159265358979323846



int lado;
double tempo;
void S_BallArenaColision()
{
    Ball *temp = s_ball;
    while(temp != NULL)
    {
        if(temp->pos.x < 300 || 
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



void CalcularFunc_S(Ball *temp, int type)
{
    if(type == 1) 
    {
        temp->dir.x = -1;
        temp->dir.y = M_PI *(cos(((M_PI/2) * (GetTime() - temp->C))*(5))) / 6;
    }
    else if(type == 2)
    {
        Vector2 pos = {Blanky.pos.x +Blanky.width/2, Blanky.pos.y + Blanky.height/2}; 
        float angle = temp->i* Vector2Angle(temp->pos, pos);
        temp->dir.x = temp->i;
        temp->dir.y = M_PI *(cos(((M_PI/2) * (GetTime() - temp->C))*(temp->s_b_a))) * 6;
        temp->dir = Vector2Rotate(temp->dir, angle);
        temp->dir = Vector2Normalize(temp->dir);
    }
}



int YS = 0, k =5;
void CreateS_ball(int X, int Y, int vel, int type)
{
    if(YS > 150){k = -k;}
    if(YS < -150){k = -k;}
     
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
    s_ball->pos.x = X;
    if(s_ball->pos.x < S_l/2) {s_ball->i = 1;} else {s_ball->i = -1;}
    s_ball->pos.y = Y + YS;
    s_ball->vel = vel;
    s_ball->tam = 10;
    s_ball->acel = 4;
    s_ball->s_b_a = 3;
    s_ball->s_b_f = 5;
    Color color = ORANGE;
    ball->ball = RedBall;
    s_ball->color = color;
    s_ball->dir = dummy.pos;
    s_ball->C = GetTime();
    s_ball->type = type;
    YS += k;
    
}


void S_BallDraw()
{
    Ball *temp = s_ball;
    while(temp != NULL)
    {
        //DrawCircle(temp->pos.x, temp->pos.y, temp->tam, temp->color);
        float scale = 0.03f;
        float textureWidth = RedBall.width * scale;
        float textureHeight = RedBall.height * scale;
        Vector2 spritePosition =  {(temp->pos.x - textureWidth/2), (temp->pos.y - textureHeight/2)};
        DrawTextureEx(ball->ball, spritePosition, 0.0f, scale, WHITE);
        temp = temp->next;
    }
}


void S_BallUpdate(float dt)
{
    Ball *temp = s_ball;
    while(temp != NULL)
    {
        CalcularFunc_S(temp, temp->type);
        temp->pos.x += temp->dir.x * dt * s_ball->vel;
        temp->pos.y += temp->dir.y * dt * s_ball->vel;
        if(CheckCollisionCircleRec(temp->pos, temp->tam, Blanky.rec))
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
            CheckState();

        }
        if(temp != NULL) {temp = temp->next;}
        

    }
    S_BallArenaColision();
    
}


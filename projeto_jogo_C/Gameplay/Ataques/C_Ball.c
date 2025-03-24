#include "raylib.h"
#include "Gameplay/player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ball.h"
#include <math.h>





void DeEspawnB_Ball()
{
    Ball *temp = b_ball;
    while(b_ball != NULL) 
    { 
        b_ball = b_ball->next;
        free(temp);
        temp = b_ball; 
    }    
}




void B_BallArenaColision()
{
    Ball *temp = b_ball;
    while(temp != NULL)
    {
        if(temp->pos.x < arena.rec.x || 
            temp->pos.x > arena.rec.x + arena.rec.width|| 
            temp->pos.y < arena.rec.y ||
            temp->pos.y > arena.rec.height + arena.rec.y) 
        {
            temp->bounce--;
            temp->vel -= 70;
            if(temp->bounce <= 0)
            {
                if(temp == b_ball)
                {
                    b_ball = b_ball->next;
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
            else if(temp->pos.x <= arena.rec.x || temp->pos.x >= arena.rec.x + arena.rec.width) {temp->dir.x = -temp->dir.x;}
            else if(temp->pos.y <= arena.rec.y || temp->pos.y >= arena.rec.height + arena.rec.y) {temp->dir.y = -temp->dir.y;}
            
        }
        if(temp != NULL) {temp = temp->next;} else {temp = b_ball;}
    }
}



Vector2 posb = {1,-1};
float fxb =0, fyb =0;
void CreateB_Ball()
{
    Ball *temp;
    if(b_ball == NULL)
    {
        temp = b_ball;
        b_ball =(Ball *)malloc(sizeof(Ball));
        b_ball->next = temp;
    }else
    {
        temp = (Ball *)malloc(sizeof(Ball));
        temp->next = b_ball;
        b_ball->before = temp;
        b_ball = temp;
    }
    if(b_ball == NULL) {exit(1);}
    b_ball->pos.x = arena.rec.x + arena.rec.width/2;
    b_ball->pos.y = arena.rec.height/2 + arena.rec.y;
    b_ball->vel = 500;
    b_ball->tam = 10;
    Color color = { 255, 161, 0, 255 };
    b_ball->color = color;
    b_ball->bounce = 4;
    posb.y += fyb;
    posb.x += fxb;
    Vector2 dir = posb;
    if(posb.x >= 1 && posb.y <= -1) {fyb = 0.3; fxb = 0;}
    else if(posb.x >= 1 && posb.y >= 1) {fxb = -0.3; fyb =0;}
    else if(posb.x <= -1 && posb.y >= 1) {fyb = -0.3; fxb =0;}
    else if(posb.x <= -1 && posb.y <= -1) {fxb = 0.3; fyb =0;}
    dir = Vector2Normalize(dir);
    b_ball->dir = dir;
}



void B_BallUpdate(float dt)
{
    Ball *temp = b_ball;
    while(temp != NULL)
    {
        temp->pos.x += temp->dir.x * dt * temp->vel;
        temp->pos.y += temp->dir.y * dt * temp->vel;
        if(CheckCollisionCircleRec(temp->pos, temp->tam, Blanky.rec))
        {
            
            if(temp == b_ball)
            {
                b_ball = b_ball->next;
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
    B_BallArenaColision();
}

void B_BallDraw()
{
    Ball *temp = b_ball;
    while(temp != NULL)
    {
        DrawCircle(temp->pos.x, temp->pos.y, temp->tam, temp->color);
        temp = temp->next;
        
    }
}
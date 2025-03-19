#include "raylib.h"
#include "Gameplay/player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ball.h"


void BallArenaColision()
{
    Ball *temp = ball;
    while(temp != NULL)
    {
        if(temp->pos.x <= arena.rec.x + arena.line_thick || 
            temp->pos.x >= arena.rec.x + arena.rec.width - arena.line_thick - temp->tam || 
            temp->pos.y <= arena.rec.y + arena.line_thick ||
            temp->pos.y >= arena.rec.y + arena.rec.height - arena.line_thick - temp->tam) 
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




void CreateBall_to_player(Vector2 pos)
{
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
    ball->tam = 10;
    Color color = { 255, 161, 0, 255 };
    ball->color = color;
    ball->dir = Blanky.pos;

    ball->dir.x = 1;
    ball->dir.y = (Blanky.pos.y - ball->pos.y)/(Blanky.pos.x - ball->pos.x);
    if(ball->pos.x > Blanky.pos.x) {ball->dir.x = -ball->dir.x;}
    if(ball->pos.y > Blanky.pos.y) {ball->dir.y = -ball->dir.y;}


    

}



void BallUpdate(float dt)
{
    Ball *temp = ball;
    while(temp != NULL)
    {
        temp->pos.x += temp->dir.x * dt * 100;
        temp->pos.y += temp->dir.y * dt * 100;
        temp = temp->next;
    }
    BallArenaColision();
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
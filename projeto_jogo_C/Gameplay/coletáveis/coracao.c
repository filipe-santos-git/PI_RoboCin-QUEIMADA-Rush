#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coracao.h"
#include "Gameplay/player.h"




void DeEspawnCoracao()
{
    Coracao *temp = hearts;
    while(hearts != NULL) 
    { 
        hearts = hearts->next;
        free(temp);
        temp = hearts; 
    }   
}





void CreateCoracao()
{
    Coracao *temp;
    if(hearts == NULL)
    {
        temp = hearts;
        hearts = (Coracao *)malloc(sizeof(Coracao));
        hearts->next = temp;
    }
    else
    {
        temp = (Coracao *)malloc(sizeof(Coracao));
        temp->next = hearts;
        hearts ->before = temp;
        hearts = temp;
    }
    hearts->y = GetRandomValue(arena.rec.y + 10, arena.rec.y + arena.rec.height - 10);
    hearts->x = GetRandomValue(arena.rec.x + 10, arena.rec.x + arena.rec.width - 10);
    hearts->H = 0.5;
    hearts->som_vida = LoadSound("assets/audios/effecs/vida.wav");
    hearts->time = GetTime();
    hearts->vel = GetRandomValue(-4, 4);
    hearts->Hy = hearts->y;
    hearts->ace = -0.01;
}




void CoracaoUpdate()
{
    
    Coracao *temp = hearts;

    while(temp != NULL && hearts != NULL)
    {
        if(GetTime() >= hearts->time + 7)
        {
            DeEspawnCoracao();
        }
        else
        {
            Vector2 pos = {temp->x, temp->y};
            if(CheckCollisionCircleRec(pos, 15, Blanky.rec))
            {
                //musica
                PlaySound(hearts->som_vida);
                Blanky.hp.width += temp->H;
                if (temp == hearts)
                {
                    hearts = temp->next;
                    free(temp);
                    temp = NULL;
                }
                else
                {
                    Coracao *despawn;
                    temp->before->next = temp->next;
                    if(temp->next != NULL) {temp->next->before = temp->before;}
                    despawn = temp;
                    temp = temp->before;
                    free(despawn);
                }
            }
            if(temp != NULL) {temp = temp->next;} else {temp = hearts;}
        }
    }
}



void CoracaoDraw()
{
    Coracao *temp = hearts;
    while(temp != NULL)
    {
        //DrawCircle(temp->x, temp->y, 15, PINK);
        Vector2 pos = {temp->x - 22, temp->y - 27}; 
        temp->vel += temp->ace;
        if(temp->vel < -4) {temp->ace = -temp->ace;}
        if(temp->vel > 4) {temp->ace =-temp->ace;}
        pos.y += temp->vel;
        DrawTextureEx(heart, pos, 0.0f,  0.5f, WHITE);
        temp = temp->next;
    }
}





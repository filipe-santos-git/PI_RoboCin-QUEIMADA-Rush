#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coracao.h"
#include "Gameplay/player.h"




void DeEspawnCoracao()
{
    Coracao *temp = heart;
    while(heart != NULL) 
    { 
        heart = heart->next;
        free(temp);
        temp = heart; 
    }   
}






void CreateCoracao()
{
    Coracao *temp;
    if(heart == NULL)
    {
        temp = heart;
        heart = (Coracao *)malloc(sizeof(Coracao));
        heart->next = temp;
    }
    else
    {
        temp = (Coracao *)malloc(sizeof(Coracao));
        temp->next = heart;
        heart ->before = temp;
        heart = temp;
    }
    heart->y = GetRandomValue(arena.rec.y + 10, arena.rec.y + arena.rec.height - 10);
    heart->x = GetRandomValue(arena.rec.x + 10, arena.rec.x + arena.rec.width - 10);
    heart->H = 0.5;
    heart->time = GetTime();
}




void CoracaoUpdate()
{
    
    Coracao *temp = heart;

    while(temp != NULL && heart != NULL)
    {
        if(GetTime() >= heart->time + 7)
        {
            DeEspawnCoracao();
        }
        else
        {
            Vector2 pos = {temp->x, temp->y};
            if(CheckCollisionCircleRec(pos, 15, Blanky.rec))
            {
                Blanky.hp.width += temp->H;
                if (temp == heart)
                {
                    heart = temp->next;
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
            if(temp != NULL) {temp = temp->next;} else {temp = heart;}
        }
    }
}



void CoracaoDraw()
{
    Coracao *temp = heart;
    while(temp != NULL)
    {
        DrawCircle(heart->x, heart->y, 15, PINK);
        temp = temp->next;
    }
}





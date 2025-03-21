#include "raylib.h"
#include "Gameplay/player.h"
#include "Gameplay/Arena.c"
#include "State_Manager.h"
#include "General_Classes/Screen_Details.h"
#include "Main_menu/Main_Menu.c"
#include "Pause/Pause_Menu.c"
#include "Gameplay/Bosses/Bosses.h"
#include "Gameplay/Ataques/Ball.h"
#include "GameOver/GameOver.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char State;
int G_i = 0;


int start_game = 0;
void ScreenUpdate(float dt)
{
    State = state;
    
    switch(State)
    {
        case'M':
            SetExitKey(256);
            MenuUpdate();
            start_game = 0;

            break;
        case'G':
            if(start_game == 0) {Blanky.hp.width = 10; start_game++;}
            SetExitKey(261);
            if(IsKeyPressed(256)) {state = 'P';}
            PlayerUpdate(dt);
            if(Blanky.hp.width <= 0) {DeEspawn(); DeEspawnR_Ball(); state = 'O';}
            DummyUpdate(dt);
            break;
        case'P':
            if(IsKeyPressed(256)) {state = 'G';}
            PauseUpdate();
            break;
        case'O':
            if(IsKeyPressed(256)) {state = 'M';}
            start_game = 0;
            GameOverUpdate();
            break;
        default: break;

    }
}

void ScreenDraw()
{
    switch(State)
    {
        case'M':
            MenuDraw();
            break;
        case'G':
            ArenaDraw();
            PlayerDraw();
            DummyDraw();
            break;
        case'P':
            ArenaDraw();
            PlayerDraw();
            DummyDraw();
            PauseDraw();
            break;
        case'O':
            GameOverDraw();
            break;
        default: break;
    }
}
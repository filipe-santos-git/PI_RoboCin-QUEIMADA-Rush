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
            ShowCursor();
            SetExitKey(256);
            MenuUpdate();
            start_game = 0;

            break;
        case'G':
            HideCursor();
            SetMousePosition(S_l, 0);
            sprintf(arena.time, "%.f", GetTime() - arena.TimeGame);
            if(start_game == 0) 
            {
                dummy.hp = 100;
                health = dummy.hp;
                Blanky.hp.width = 10;
                dummy.B = 1; 
                start_game++;
                dummy.height = 110;
                dummy.width = 300;
                dummy.pos.x = S_l/2;
                dummy.pos.y = S_a/12;
                dummy.pos.x -= dummy.width/2;
            }
            SetExitKey(261);
            if(IsKeyPressed(256)) {state = 'P';}
            PlayerUpdate(dt);
            if(Blanky.hp.width <= 0) {DeEspawn(); DeEspawnR_Ball(); DeEspawn_S(); DeEspawnB_Ball(); state = 'O';}
            DummyUpdate(dt);
            break;
        case'P':
            ShowCursor();
            arena.TimeGame = GetTime();
            if(IsKeyPressed(256)) {state = 'G';}
            PauseUpdate();
            break;
        case'O':
            ShowCursor();
            if(IsKeyPressed(256)) {state = 'M';}
            start_game = 0;
            dummy.start_attack = GetTime();
            N_AT = GetRandomValue(1,2);
            GameOverUpdate();
            break;
        case'W':
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
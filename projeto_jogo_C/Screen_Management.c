#include "raylib.h"
#include "Gameplay/player.h"
#include "Gameplay/Arena.c"
#include "State_Manager.h"
#include "General_Classes/Screen_Details.h"
#include "Main_menu/Main_Menu.c"
#include "Pause/Pause_Menu.c"
#include "Gameplay/Bosses/Bosses.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char State;
int G_i = 0;



void ScreenUpdate(float dt)
{
    State = state;
    switch(State)
    {
        case'M':
            SetExitKey(256);
            MenuUpdate();

            break;
        case'G':
            SetExitKey(261);
            if(IsKeyPressed(256)) {state = 'P';}
            PlayerUpdate(dt);
            DummyUpdate(dt);
            break;
        case'P':
            if(IsKeyPressed(256)) {state = 'G';}
            PauseUpdate();
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
            
        default: break;
    }
}
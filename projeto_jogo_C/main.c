#include "raylib.h"
#include "Gameplay/player.h"
#include "Gameplay/Arena.h"
#include "State_Manager.h"
#include "General_Classes/Screen_Details.h"
#include "Gameplay/Bosses/Bosses.h"
#include "Main_menu/Main_Menu.h"
#include "Screen_Management.c"
#include "Pause/Pause_Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------



//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    S_l = GetScreenHeight();
    S_a = GetScreenWidth();

    InitWindow(S_l, S_a, "raylib_1");
    //ToggleBorderlessWindowed();
    SetTargetFPS(300);
    CreateDummy();
    CreatePause();
    CreateArena();
    CreatePlayer(); 


    
    while (!WindowShouldClose())    
    {
        float dt = GetFrameTime();

        ScreenUpdate(dt);

        BeginDrawing();
            ScreenDraw();
            DrawFPS(0, 0);
        EndDrawing();
    }


   
   
    CloseWindow();                


    return 0;
}

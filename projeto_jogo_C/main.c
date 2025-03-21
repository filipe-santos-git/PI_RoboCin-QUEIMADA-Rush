#include "raylib.h"
#include "Gameplay/player.h"
#include "Gameplay/Arena.h"
#include "State_Manager.h"
#include "General_Classes/Screen_Details.h"
#include "Gameplay/Bosses/Bosses.h"
#include "Main_menu/Main_Menu.h"
#include "Screen_Management.c"
#include "Pause/Pause_Menu.h"
#include "GameOver/GameOver.h"
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

    InitWindow(S_l, S_a, "raylib_1");
    //ToggleBorderlessWindowed();
    //SetTargetFPS(60);
    CreateGameOver();
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
            DrawFPS(10, 10);
        EndDrawing();
    }


   
   
    CloseWindow();                


    return 0;
}

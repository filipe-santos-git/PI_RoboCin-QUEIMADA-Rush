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
#include "CarregarTexturas/loadtextures.h"
#include "Vitoria_Menu/Vitoria_Menu.h"
#include "assets/audios/audios_effects.c"
#include "Historia_Menu/Historia_Menu.h"
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
    InitAudioDevice();

    //--------------------------------------------------------------------------------------
    
    InitWindow(S_l, S_a, "raylib_1");
    //ToggleBorderlessWindowed();
    //SetTargetFPS(300);
    Carregar();
    CreateGameOver();
    CreateDummy();
    CreatePause();
    CreateVitoria();
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

    // unloadaudio();
    CloseAudioDevice();
    Descarregar();
    CloseWindow();                


    return 0;
}
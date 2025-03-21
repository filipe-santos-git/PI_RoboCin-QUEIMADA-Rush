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
#include "../assets/audios/audios_effects.h"

#define NUM_AUDIOS 4
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

    //Init audio
    //------------------------------------------------------------------------------------
    InitAudioDevice();
    SetMasterVolume(1.0f);  // Define system to max volume
    const char *filenames [NUM_AUDIOS] = {"assets/audios/effects/bola.wav","assets/audios/effects/boss-entrada.wav","assets/audios/effects/soco.wav","assets/audios/effects/vida.wav"};
    Sound effects[NUM_AUDIOS];
    LoadSounds(effects, filenames, NUM_AUDIOS);

    InitWindow(S_l, S_a, "raylib_1");
    //ToggleBorderlessWindowed();
    SetTargetFPS(60);
    CreateGameOver();
    CreateDummy();
    CreatePause();
    CreateArena();
    CreatePlayer(effects[2]); 


    
    while (!WindowShouldClose())    
    {
        float dt = GetFrameTime();

        ScreenUpdate(dt);

        BeginDrawing();
            ScreenDraw();
            DrawFPS(10, 10);
        EndDrawing();
    }


   //Unload sound data
    UnloadSounds(effects, NUM_AUDIOS); 
    CloseAudioDevice();  

    CloseWindow();  
               
    return 0;
}

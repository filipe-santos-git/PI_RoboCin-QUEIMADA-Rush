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

<<<<<<< Updated upstream
#define NUM_AUDIOS 4
=======
>>>>>>> Stashed changes
//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main()
{
<<<<<<< Updated upstream
   
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
=======
    // Inicialização
    InitAudioDevice();
>>>>>>> Stashed changes

    // Inicializa a janela
    InitWindow(S_l, S_a, "raylib_1");
<<<<<<< Updated upstream
    //ToggleBorderlessWindowed();
    SetTargetFPS(60);
=======

    // Cria os componentes do jogo
>>>>>>> Stashed changes
    CreateGameOver();
    CreateDummy();
    CreatePause();
    CreateArena();
<<<<<<< Updated upstream
    CreatePlayer(effects[2]); 

=======
    CreatePlayer();
>>>>>>> Stashed changes

    // Carrega a música
    Music teste = LoadMusicStream("projeto_jogo_C/assets/audios/effects/mixkit-winning-a-coin-video-game-2069.wav");
    

    // Ajusta o volume
    SetMasterVolume(0.5f);  // Volume global para 50%
    SetMusicVolume(teste, 0.5f);  // Volume da música para 50%

    // Toca a música (não precisa chamar dentro do loop de cada frame)
    PlayMusicStream(teste);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // Atualiza a música
        UpdateMusicStream(teste);

        // Atualiza e desenha o jogo
        ScreenUpdate(dt);
        GreenState();

        BeginDrawing();
        ScreenDraw();

        // Desenha o FPS na tela
        DrawFPS(10, 10);

        EndDrawing();
    }

<<<<<<< Updated upstream

   //Unload sound data
    UnloadSounds(effects, NUM_AUDIOS); 
    CloseAudioDevice();  
=======
    // Limpeza de recursos
    unload();
    UnloadMusicStream(teste);
    CloseAudioDevice();
    CloseWindow();
>>>>>>> Stashed changes

    CloseWindow();  
               
    return 0;
}

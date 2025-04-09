#include "raylib.h"
#include "Gameplay/player.h"
#include "Gameplay/Arena.c"
#include "State_Manager.h"
#include "General_Classes/Screen_Details.h"
#include "Main_Menu/Main_Menu.c"
#include "Win1_Menu/Win1_Menu.c"
#include "Vitoria_Menu/Vitoria_Menu.c"
#include "Historia_Menu/Historia_Menu.c"
#include "Pause/Pause_Menu.c"
#include "Instruction_Menu/Instruction_Menu.c"
#include "Creditos_Menu/Creditos_Menu.c"
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
    
    if(state != 'G' && state != 'W' && state != 'P') {StopMusicStream(G_musica);}
    
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
                PlayMusicStream(G_musica);
                dummy.hp = 100;
                dummy.nivel = robocin_nivel_1;   
                health = dummy.hp;
                Blanky.hp.width = 10;
                dummy.B = 1; 
                start_game=1;
                dummy.height = 110;
                dummy.width = 300;
                dummy.pos.x = S_l/2;
                dummy.pos.y = S_a/12;
                dummy.pos.x -= dummy.width/2;
            }
            if(start_game == 2)
            {
                ResumeMusicStream(G_musica);
                norm = BROWN;
                met = DARKBROWN;
                dummy.hp = 200;
                dummy.nivel = robocin_nivel_2;     // adicionar a textura para o robocin nivel 2!!
                health = dummy.hp;
                Blanky.hp.width = 10;
                dummy.B = 2; 
                start_game=3;
                dummy.height = 110;
                dummy.width = 300;
                dummy.pos.x = S_l/2;
                dummy.pos.y = S_a/12;
                dummy.pos.x -= dummy.width/2;
            }

            UpdateMusicStream(G_musica);
            SetExitKey(261);
            if(IsKeyPressed(256)) {state = 'P';}
            PlayerUpdate(dt);
            if(Blanky.hp.width <= 0) {DeEspawn(); DeEspawnR_Ball(); DeEspawn_S(); DeEspawnB_Ball(); state = 'O'; start_game = 0;}
            CoracaoUpdate();
            DummyUpdate(dt);

            if(GetMusicTimePlayed(G_musica) == GetMusicTimeLength(G_musica)) { StopMusicStream(G_musica); PlayMusicStream(G_musica);}
            break;
        case'P':
            ShowCursor();
            arena.TimeGame = GetTime();
            if(IsKeyPressed(256)) {state = 'G';}
            PauseUpdate();
            break;
        case'O':
            StopMusicStream(musica);
            ShowCursor();
            if(IsKeyPressed(256)) {state = 'M';}
            if(start_game==1){ start_game=0;}
            if(start_game==3){ start_game=2;}
            dummy.start_attack = GetTime();
            N_AT = GetRandomValue(1,2);
            GameOverUpdate();
            break;
            //Win_1fase
        case'W':
            PauseMusicStream(G_musica);
            ShowCursor();
            SetExitKey(256);
            Win1Update();
            start_game=2;

            break;
        case'V':
            ShowCursor();
            SetExitKey(256);
            VitoriaUpdate();
            break;
        case'I':
            ShowCursor();
            SetExitKey(256);
            InstructionUpdate();
            break;
        case'C':
            ShowCursor();
            SetExitKey(256);
            CreditosUpdate();
            break;
        case'H':
            ShowCursor();
            SetExitKey(256);
            HistoriaUpdate();
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
        case'W':
            Win1Draw();
            break;
        case'V':
            VitoriaDraw();
            break;
        case'I':
            InstructionDraw();
            break;
        case'C':
            CreditosDraw();
            break;
        case'H':
            HistoriaDraw();
            break;          
        default: break;
    }
}
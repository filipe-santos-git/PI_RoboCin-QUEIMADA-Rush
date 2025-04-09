#include <stdio.h>
#include "raylib.h"
#include <stdlib.h>
#include "audios_effects.h"


void LoadAudios()
{
        dash = LoadSound("assets/audios/effects/dash.wav");
        hearty = LoadSound("assets/audios/effects/vida.wav");
        Boss_entry = LoadSound("assets/audios/effects/boss-entrada.wav");
        Boss_dmg = LoadSound("assets/audios/effects/boss-dmg.mp3");
        Crowd = LoadSound("assets/audios/effects/crowd.mp3");


        G_musica = LoadMusicStream("assets/audios/musica-main.mp3");
}



void UnloadAudios()
{
        UnloadSound(Boss_dmg);
        UnloadSound(dash);
        UnloadSound(hearty);
        UnloadSound(Boss_entry);
        UnloadSound(Crowd);

        UnloadMusicStream(G_musica);

}






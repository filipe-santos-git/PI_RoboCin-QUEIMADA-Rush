#include <stdio.h>
#include "raylib.h"
#include <stdlib.h>
#include "audios_effects.h"

void LoadSounds(Sound *effects, const char *filenames[], int num_audios) {
    for (int i = 0; i < num_audios; i++) {
        effects[i] = LoadSound(filenames[i]);  // Load sound data
        if (effects[i].frameCount == 0) {
        printf("Erro ao carregar o áudio!\n");
}

    }
}

void UnloadSounds(Sound *effects, int num_audios) {
    for (int i = 0; i < num_audios; i++) {
        UnloadSound(effects[i]);  // Unload sound data
    }
}
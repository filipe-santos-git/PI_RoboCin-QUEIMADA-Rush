#ifndef AUDIO_EFFECTS_H 
#define AUDIO_EFFECTS_H

#include "raylib.h"

void LoadSounds(Sound *effects, const char *filenames[], int num_audios);

void UnloadSounds(Sound *effects, int num_audios);

#endif
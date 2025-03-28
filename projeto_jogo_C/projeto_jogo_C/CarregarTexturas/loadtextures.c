#include "raylib.h"


void Carregar(){

    RedBall = LoadTexture("assets/sprite_RedBall.png");
    BlueBall = LoadTexture("assets/sprite_BlueBall.png");

}

void Descarregar(){

    UnloadTexture(RedBall);
    UnloadTexture(BlueBall);

}
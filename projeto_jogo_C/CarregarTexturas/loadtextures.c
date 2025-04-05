#include "raylib.h"
#include "CarregarTexturas/loadtextures.h"


void Carregar(){
    RedBall = LoadTexture("assets/sprite_RedBall.png");
    BlueBall = LoadTexture("assets/sprite_BlueBall.png");
    Inicio = LoadTexture("assets/menu.png");
}

void Descarregar(){
    UnloadTexture(RedBall);
    UnloadTexture(BlueBall);
    UnloadTexture(Inicio);
}
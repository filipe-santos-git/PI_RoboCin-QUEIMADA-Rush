#include "raylib.h"
#include "CarregarTexturas/loadtextures.h"


void Carregar(){
    RedBall = LoadTexture("assets/sprite_RedBall.png");
    BlueBall = LoadTexture("assets/sprite_BlueBall.png");
    Inicio = LoadTexture("assets/menu.png");
    quadra = LoadTexture("assets/quadra.png");
    quitGreen = LoadTexture("assets/quitGreen.png");
    quitRed = LoadTexture("assets/quitRed.png");
    resumeRed = LoadTexture("assets/resumeRed.png");
    resumeGreen = LoadTexture("assets/resumeGreen.png");
    pauseScreen = LoadTexture("assets/pauseScreen.png");
    robocin_nivel_1 = LoadTexture("assets/robocin_nivel_1.png");
    robocin_atordoado = LoadTexture ("assets/robocin_atordoado.png");
    start1 = LoadTexture("assets/start_nn_pressionado.png");
    start2 = LoadTexture("assets/start_pressionado.png");
    sair = LoadTexture("assets/sair.png");
    tente_novamente = LoadTexture("assets/tente_novamente.png");
    menu_imagem = LoadTexture("assets/menu.png");
    game_over = LoadTexture("assets/game_over.png");
}

void Descarregar(){
    UnloadTexture(RedBall);
    UnloadTexture(BlueBall);
    UnloadTexture(Inicio);
    UnloadTexture(quadra);
    UnloadTexture(quitGreen);
    UnloadTexture(quitRed);
    UnloadTexture(resumeGreen);
    UnloadTexture(resumeRed);
    UnloadTexture(pauseScreen);
    UnloadTexture(robocin_nivel_1);
    UnloadTexture(robocin_atordoado);
    UnloadTexture(start1);
    UnloadTexture(start2);
    UnloadTexture(sair);
    UnloadTexture(tente_novamente);
    UnloadTexture(menu_imagem);
    UnloadTexture(game_over);
}
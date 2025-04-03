#include "raylib.h"


void Carregar(){

    RedBall = LoadTexture("assets/sprite_RedBall.png");
    BlueBall = LoadTexture("assets/sprite_BlueBall.png");
    robocin_nivel_1= LoadTexture("assets/robocin_nivel_1.png");
    robocin_atordoado = LoadTexture ("assets/robocin_atordoado.png");
    robocin_nivel_2= LoadTexture("assets/robocin_nivel_2.png");
    robocin_morto= LoadTexture("assets/robocin_morto.png");


}

void Descarregar(){

    UnloadTexture(RedBall);
    UnloadTexture(BlueBall);
    UnloadTexture(robocin_nivel_1);
    UnloadTexture(robocin_atordoado);
    UnloadTexture(robocin_nivel_2);
    UnloadTexture(robocin_morto);

}

#include "raylib.h"
#include "CarregarTexturas/loadtextures.h"
#include "assets/audios/audios_effects.c"


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
    robocin_nivel_2 = LoadTexture("assets/robocin_nivel_2.png");
    robocin_atordoado = LoadTexture ("assets/robocin_atordoado.png");
    start1 = LoadTexture("assets/start_nn_pressionado.png");
    start2 = LoadTexture("assets/start_pressionado.png");
    sair = LoadTexture("assets/sair.png");
    tente_novamente = LoadTexture("assets/tente_novamente.png");
    menu_imagem = LoadTexture("assets/menu.png");
    game_over = LoadTexture("assets/game_over.png");
    proxima_fase = LoadTexture("assets/proxima_fase.png");
    tela_vitoria = LoadTexture("assets/tela_vitoria.png");
    tela_win = LoadTexture("assets/robocin_help.png");
    fundo= LoadTexture("assets/fundo.png");
    heart = LoadTexture("assets/coracao.png");
    next_stage = LoadTexture("assets/next_stage.png");
    next_stage_pressionado = LoadTexture("assets/next_stage_pressionado.png");
    jogador_ataque = LoadTexture("assets/jogador_ataque.png");
    jogador = LoadTexture("assets/jogador.png");
    botao_menu = LoadTexture("assets/botao_menu.png");
    botao_menu_pressionando = LoadTexture("assets/botao_menu_pressionado.png");
    tela_instrucoes = LoadTexture("assets/tela_instrucoes.png");
    instrucoes = LoadTexture("assets/instrucoes.png");
    instrucoes_pressionado = LoadTexture("assets/instrucoes_pressionado.png");
    creditos = LoadTexture("assets/creditos.png");
    creditos_pressionado = LoadTexture("assets/creditos_pressionado.png");
    historia = LoadTexture("assets/historia.png");
    historia_pressionado = LoadTexture("assets/historia_pressionado.png");
    tela_creditos = LoadTexture("assets/tela_creditos.png");
    historia_1 = LoadTexture("assets/historia_1.png");
    historia_2 = LoadTexture("assets/historia_2.png");
    historia_3 = LoadTexture("assets/historia_3.png");
    historia_4 = LoadTexture("assets/historia_4.png");
    seta = LoadTexture("assets/seta.png");
    seta_pressionada = LoadTexture("assets/seta_pressionada.png");
    //musica = LoadMusicStream("assets/audios/musica-main.mp3");




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
    UnloadTexture(robocin_nivel_2);
    UnloadTexture(robocin_atordoado);
    UnloadTexture(start1);
    UnloadTexture(start2);
    UnloadTexture(sair);
    UnloadTexture(tente_novamente);
    UnloadTexture(menu_imagem);
    UnloadTexture(game_over);
    UnloadTexture(proxima_fase);
    UnloadTexture(tela_vitoria);
    UnloadTexture(fundo);
    UnloadTexture(heart);
    UnloadTexture(next_stage);
    UnloadTexture(next_stage_pressionado);
    UnloadTexture(jogador);
    UnloadTexture(jogador_ataque);
    UnloadTexture(tela_win);
    UnloadTexture(botao_menu);
    UnloadTexture(botao_menu_pressionando);
    UnloadTexture(tela_instrucoes);
    UnloadTexture(instrucoes);
    UnloadTexture(instrucoes_pressionado);
    UnloadTexture(creditos);
    UnloadTexture(creditos_pressionado);
    UnloadTexture(historia);
    UnloadTexture(historia_pressionado);
    UnloadTexture(tela_creditos);
    UnloadTexture(historia_1);
    UnloadTexture(historia_2);
    UnloadTexture(historia_3);
    UnloadTexture(historia_4);
    UnloadTexture(seta);
    UnloadTexture(seta_pressionada);



   // UnloadMusicStream(musica);
    
}
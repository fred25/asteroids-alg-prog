// incluindo módulos
#include "raylib.h"
#include "game.h"

/**
 * Função "motor" do jogo, roda todas as funcionalidades do jogo.
 */
void game(){

    
    // cria variaveis - depois vamos ter que trocar isso pela leitura do arquivo lá
    // variavel do player
    PLAYER player = {
        10, // posição x
        10, // posição y
        0, // agulo
        0, // velocidade
        3 // vidas
    };
    
    // variavel dos asteroides (aqui eu recomendo fazer uma lista da estrutura q tu criar pro asteroide)
    // TODO

    // variavel das balas
    //TODO

    // Configurações iniciais da janela 
    InitWindow(LARGURA, ALTURA, "Asteroids - AlgProg");
    SetTargetFPS(60);
    
    Texture2D player_sprite = LoadTexture("assets/sprites/player_beta.png");
    // Game loop
    while (!WindowShouldClose()){

        /*
        Depois vamos ter que add a verificação do gamestate como cada valor sendo um estado do jogo
        pode ser tipo
        0 = menu
        1 = jogo
        2 = pause
        3 = tela de game over

        mas por enquanto to deixando assim só pra focar na parte do jogo q é a mais complexa
        */

        // roda o "passo lógico do jogo" e atualiza as estruturas la em cima
        game_logic(&player);

        // desenha o frame do jogo
        draw_game(&player, &player_sprite);

    }

}

/**
 * Funçao que roda a lógica do jogo chamando de seus módulos específicos
 * Esta função recebe por referência (ponteiros) das entidades presentes no jogo e as atualiza
 * a partir da sua própria lógica.
*/
void game_logic(PLAYER* player){

    // lógica do player
    player_logic(player);

}

/**
 * Função que desenha cada frame do jogo
 */
void draw_game(PLAYER* player, Texture2D* player_sprite){

    BeginDrawing();
    ClearBackground(RAYWHITE);

    draw_sprite(player->position, *player_sprite, player->angle);

    EndDrawing();

}
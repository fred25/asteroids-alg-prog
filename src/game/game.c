// incluindo módulos
#include "raylib.h"
#include "game.h"

/**
 * Função "motor" do jogo, roda todas as funcionalidades do jogo.
 */
void game(){
    
    // Configurações iniciais da janela 
    InitWindow(LARGURA, ALTURA, "Asteroids - AlgProg");
    SetTargetFPS(60);
    
    // cria variaveis - depois vamos ter que trocar isso pela leitura do arquivo lá
    GAME game;
    // popula o objeto do game
    game.player = (PLAYER) {(POSITION){10, 10}, 0, 0, 3};
    game.player_sprite = LoadTexture(PLAYER_SPRITE_PATH);

    game.n_bullets = 0;
    game.bullet_sprite = LoadTexture(BULLET_SPRITE_PATH);
    
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
        game_logic(&game);

        // desenha o frame do jogo
        draw_game(&game);

    }

}

/**
 * Funçao que roda a lógica do jogo chamando de seus módulos específicos
 * Esta função recebe por referência (ponteiros) das entidades presentes no jogo e as atualiza
 * a partir da sua própria lógica.
*/
void game_logic(GAME* game){

    // lógica do player
    player_logic(&game->player);
    shoot(game->bullets, &game->n_bullets, game->player);

    // logica das balas
    bullet_logic(game->bullets, &game->n_bullets);

}

/**
 * Função que desenha cada frame do jogo
 */
void draw_game(GAME* game){

    BeginDrawing();
    ClearBackground(RAYWHITE);

    // draw player
    draw_sprite(game->player.position, game->player_sprite, game->player.angle);

    //draw bullets
    draw_bullets(game->bullets, game->n_bullets, game->bullet_sprite);

    EndDrawing();

}
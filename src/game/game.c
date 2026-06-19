// incluindo módulos
#include "raylib.h"
#include "game.h"
#include <stdio.h>

/**
 * Função "motor" do jogo, roda todas as funcionalidades do jogo.
 */
void game(){
    
    // Configurações iniciais da janela 
    InitWindow(LARGURA, ALTURA, "Asteroids - AlgProg");
    SetTargetFPS(60);
    
    SetExitKey(KEY_NULL);


    // cria variaveis - depois vamos ter que trocar isso pela leitura do arquivo lá
    GAME game;

    game.state = GAME_STATE_MENU;
    game.points = 0;
    game.current_level = 1;
    game.should_close = false;


    // popula o objeto do game
    game.player = (PLAYER) {(POSITION){10, 10}, 0, 0, 0, 3};
    game.player_sprite = LoadTexture(PLAYER_SPRITE_PATH);

    game.n_bullets = 0;
    game.bullet_sprite = LoadTexture(BULLET_SPRITE_PATH);
    
    // Game loop
    while (!WindowShouldClose() && !game.should_close){
        
        update_game_state(&game);
        
        // desenha as frames do jogo de acordo com o estado
        draw_game_state(&game);

    }

}


// funcao que vai checar e trocar as telas/estados do jogo
void update_game_state(GAME* game) {
    switch (game->state) {
        case GAME_STATE_MENU:
            update_menu(game);
            break;

        case GAME_STATE_PLAYING:
            game_logic(game);
            break;

        case GAME_STATE_PAUSED:
            update_pause(game);
            break;

        case GAME_STATE_GAMEOVER:
            update_game_over(game);
            break;
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

    // checa se eh game over
    if(game->player.vida <= 0) {
        game->state = GAME_STATE_GAMEOVER;
    }

    if (IsKeyPressed(KEY_P)) {
        game->state = GAME_STATE_PAUSED;
    }

    if(IsKeyPressed(KEY_ESCAPE)){
        game->state = GAME_STATE_MENU;
    }

    if(IsKeyPressed(KEY_Q)){
        quit_game(game);
    }

}

// funcao que vai desenhar as frames do jogo de acordo com qual estado o jogo esta
void draw_game_state(GAME* game) {
    BeginDrawing();
    ClearBackground(BLACK);

    switch (game->state) {
        case GAME_STATE_MENU:
            draw_menu();
            break;

        case GAME_STATE_PLAYING:
            draw_game(game);
            break;

        case GAME_STATE_PAUSED:
            draw_game(game);
            draw_pause();
            break;

        case GAME_STATE_GAMEOVER:
            draw_game_over(game);
            break;
    }


    EndDrawing();
}



// funcao que desenha o menu do jogo
void draw_menu(){
    DrawText("ASTEROIDS", 450, 180, 50, WHITE);

    DrawText("Novo Jogo - N", 480, 300, 30, GRAY);
    DrawText("Carregar Jogo - C", 480, 350, 30, GRAY);
    DrawText("Sair - Q", 480, 400, 30, GRAY);
}

// funcao que desenha o menu que aparece quando se pausa o jogo
void draw_pause() {
    DrawRectangle(350, 180, 500, 350, DARKGRAY);

    DrawText("PAUSADO", 510, 220, 40, WHITE);

    DrawText("Voltar ao jogo - V", 430, 310, 30, RAYWHITE);
    DrawText("Salvar jogo - S", 430, 360, 30, RAYWHITE);
    DrawText("Menu principal - M", 430, 410, 30, RAYWHITE);
    DrawText("Sair - Q", 430, 460, 30, RAYWHITE);
}

// funcao que desenha a tela de game over
void draw_game_over(GAME* game) {
    DrawText("GAME OVER", 440, 180, 50, RED);

    DrawText(TextFormat("Pontuacao final: %d", game->points), 450, 280, 30, WHITE);

    DrawText("Tentar Novamente - R", 470, 360, 30, RAYWHITE);
    DrawText("Menu Principal - M", 470, 410, 30, RAYWHITE);
    DrawText("Sair - Q", 470, 460, 30, RAYWHITE);
}


/**
 * Função que desenha cada frame do jogo
 */
void draw_game(GAME* game){

    // draw player
    draw_sprite(game->player.position, game->player_sprite, game->player.angle);

    //draw bullets
    draw_bullets(game->bullets, game->n_bullets, game->bullet_sprite);

    // mostra as estatisticas na parte de baixo da tela
    DrawText(TextFormat("Vidas: %d", game->player.vida), 20, 750, 30, WHITE);
    DrawText(TextFormat("Pontos: %d", game->points), 250, 750, 30, WHITE);
    DrawText(TextFormat("Nivel: %d", game->current_level), 500, 750, 30, WHITE);

}

void deal_with_file(char* filename, PLAYER* player){

    char id;
    int x, y;
    float dx, dy;

    FILE *f = fopen(filename, "r");

    if (f == NULL) {
        return;
    }

    while (fscanf(f, "%c,%d,%d,%f,%f", &id, &x, &y, &dx, &dy) == 5){

        if (id == 'N'){
            *player = (PLAYER) {
                .position = (POSITION) {.x = x, .y = y},
                .angle = 0,
                .speedx = 0.0,
                .speedy = 0.0,
                .vida = 3 
            };
        }

    }

    fclose(f);

}

// funcao que cria/comeca um novo jogo
void start_new_game(GAME* game){
    game->state = GAME_STATE_PLAYING;
    game->points = 0;
    game->current_level = 1;
    game->n_bullets = 0;

    deal_with_file("files/niveis/nivel_1.txt", &game->player);

};

// funcao q checa se alguma das teclas de acao do menu foram pressionadas
void update_menu(GAME* game) {
    if (IsKeyPressed(KEY_N)) {

        start_new_game(game);

    }

    if (IsKeyPressed(KEY_C)) {
        load_save(game);
    }

    if (IsKeyPressed(KEY_Q)) {
       quit_game(game);
    }
};

/**
 * Função que carrega o jogo salvo
 */
void load_save(GAME* game){

    FILE *f = fopen("files/save.bin", "rb");

    if (f == NULL){
        fclose(f);
        return;
    }

    fread(game, sizeof(*game), 1, f);

    fclose(f);

}

// funcao que checa se alguma das teclas de acao do menu de pausa foram pressionadas
void update_pause(GAME* game) {
    if (IsKeyPressed(KEY_V)) {
        game->state = GAME_STATE_PLAYING;
    }

    if (IsKeyPressed(KEY_S)) {
        save_game(*game);
    }

    if (IsKeyPressed(KEY_M)) {
        game->state = GAME_STATE_MENU;
    }

    if (IsKeyPressed(KEY_Q)) {
        quit_game(game);
    }
};

/**
 * Função que salva o jogo em um arquivo binário
 */
void save_game(GAME game){

    FILE *f = fopen("files/save.bin", "wb");

    if (f == NULL) {
        fclose(f);
        return;
    }

    game.state = GAME_STATE_PLAYING;

    fwrite(&game, sizeof(game), 1, f);

    fclose(f);

}

// funcao que checa se alguma das teclas de acao da tela de game over foram pressionadas
void update_game_over(GAME* game) {
    if (IsKeyPressed(KEY_R)) {
        start_new_game(game);
    }

    if (IsKeyPressed(KEY_M)) {
        game->state = GAME_STATE_MENU;
    }

    if (IsKeyPressed(KEY_ESCAPE)){
        game->state - GAME_STATE_MENU;
    }

    if (IsKeyPressed(KEY_Q)) {
        // jogo deve fechar
    }
};

void quit_game(GAME* game){
    game->should_close = true;

}

// fazer com que de pra fechar o jogo apertando Q 
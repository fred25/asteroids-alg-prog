#include "collision.h"
#include "raylib.h"


// logica da colisao
void collision_logic(GAME* game){
    if(game->hit_cooldown > 0){
        game->hit_cooldown--;
        return;
    }

    for(int i = 0; i < game->n_asteroids; i++){
        if(game->asteroids[i].active){
            if(check_player_collision(game->player,game->asteroids[i])){
                damage_player(game);
                return;
            }
        }
    }

}

// checa se houve colisao entre o player e o asteroide
bool check_player_collision(PLAYER player, ASTEROID asteroid){
    Rectangle player_rect = {
        player.position.x - PLAYER_SIZE / 2.0f,
        player.position.y - PLAYER_SIZE / 2.0f,
        PLAYER_SIZE,
        PLAYER_SIZE
    };

    Rectangle asteroid_rect = {
        asteroid.position.x,
        asteroid.position.y,
        ASTEROID_SIZE,
        ASTEROID_SIZE
    };

    return CheckCollisionRecs(player_rect, asteroid_rect);
}

// funcao que faz o player perder a vida e voltar a posicao inicial se houver colisao
void damage_player(GAME* game){
    game->player.vida--;

    game->player.position = game->player_start_position;
    game->player.speedx = 0.0f;
    game->player.speedy = 0.0f;
    game->n_bullets = 0;
    game->hit_cooldown = 60;

}



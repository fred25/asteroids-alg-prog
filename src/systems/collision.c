#include "collision.h"
#include "raylib.h"

// verifica colisão entre uma bala e um asteroide usando distância circular
static int check_bullet_collision(BULLET bullet, ASTEROID asteroid){
    float dx = bullet.position.x - asteroid.position.x;
    float dy = bullet.position.y - asteroid.position.y;
    float radius = ASTEROID_SIZE / 2.0f + 8.0f;

    return dx * dx + dy * dy <= radius * radius;
}

// lógica principal de colisão do jogo
void collision_logic(GAME* game){
    // colisão bala x asteroide
    for(int ai = 0; ai < game->n_asteroids; ai++){
        if(!game->asteroids[ai].active) continue;

        for(int bi = 0; bi < game->n_bullets; bi++){
            if(check_bullet_collision(game->bullets[bi], game->asteroids[ai])){
                game->points += 100;

                game->asteroids[ai] = game->asteroids[game->n_asteroids - 1];
                game->n_asteroids--;

                game->bullets[bi] = game->bullets[game->n_bullets - 1];
                game->n_bullets--;

                ai--;
                break;
            }
        }
    }

    // temporizador de invencibilidade após o jogador ser atingido
    if(game->hit_cooldown > 0){
        game->hit_cooldown--;
        return;
    }

    // verifica colisão jogador x asteroide
    for(int i = 0; i < game->n_asteroids; i++){
        if(game->asteroids[i].active){
            if(check_player_collision(game->player,game->asteroids[i])){
                damage_player(game);
                return;
            }
        }
    }

}

// checa se houve colisão entre o player e um asteroide
int check_player_collision(PLAYER player, ASTEROID asteroid){
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

// aplica dano ao jogador quando houver colisão com asteroide
void damage_player(GAME* game){
    const int HIT_PENALTY = 50;

    game->player.vida--;
    game->points -= HIT_PENALTY;
    if (game->points < 0) {
        game->points = 0;
    }

    game->player.position = game->player_start_position;
    game->player.speedx = 0.0f;
    game->player.speedy = 0.0f;
    game->n_bullets = 0;
    game->hit_cooldown = 60;

}



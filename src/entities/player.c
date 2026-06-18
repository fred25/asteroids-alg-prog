// inclusão de bibliotecas
#include "player.h"
#include "raylib.h"
#include <math.h>
#include <stdio.h>

/**
 * Função com a lógica do player
 * recebe um objeto player e atualiza para o próximo frame
 */
void player_logic(PLAYER *player)
{
    player->angle = new_angle(player->angle);

    new_speed(&player->speedx, &player->speedy, player->angle);

    float speed_sq =
        player->speedx * player->speedx +
        player->speedy * player->speedy;

    float speed = sqrtf(speed_sq);

    float movement_angle =
        atan2f(player->speedx, player->speedy) * 180.0f / PI;

    player->position =
        new_position(player->position,
                     speed,
                     movement_angle);
}
/**
 * Função que le as entradas do teclado e retorna o novo valor do ângulo do jogador
 */
float new_angle(float angle){
    
    // verifica se A ou seta pra esquerda está apertado
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
        // se sim, subtrai a velocidade angular do angulo
        angle -= PLAYER_ANGULAR_SPEED;
    } 
    
    // verifica se D ou seta para direita está apertado
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        // se sim, subtrai a velocidade angular do angulo
        angle += PLAYER_ANGULAR_SPEED;
    }

    // mantem os valores entre 0 e 360
    if (angle >= 360) angle -= 360;
    if (angle < 0) angle += 360;

    return angle;

}

/**
 * função que calcula a velocidade do player no próximo frame
 * se W ou seta pra cima estiver pressionado aumenta a velocidade
 * se não diminui com o "atrito"
 */
void new_speed(float *speedx, float *speedy, float angle){

    // verifica se o "pra frente" está sendo apertado;
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)){
        *speedx += PLAYER_ACCELERATION * sin(angle * PI / 180);
        *speedy += PLAYER_ACCELERATION * cos(angle * PI / 180);
    } else {
        *speedx *= PLAYER_FRICTION;
        *speedy *= PLAYER_FRICTION;
    } 
    
    if (*speedx < -PLAYER_MAX_SPEED) *speedx = -PLAYER_MAX_SPEED;
    if (*speedy < -PLAYER_MAX_SPEED) *speedy = -PLAYER_MAX_SPEED;
    if (*speedx > PLAYER_MAX_SPEED) *speedx = PLAYER_MAX_SPEED;
    if (*speedy > PLAYER_MAX_SPEED) *speedy = PLAYER_MAX_SPEED;
}

/**
 * Função que faz a nave do jogador criar um objeto "bala"
 */
void shoot(BULLET* bullets, int* n_bullets, PLAYER player){ 

    if (IsKeyPressed(KEY_SPACE)){
        bullets[*n_bullets] = (BULLET) {player.position, player.angle, BULLET_LIFE};
        (*n_bullets)++;
    
    }
}
// inclusão de bibliotecas
#include "player.h"
#include "raylib.h"
#include <math.h>

/**
 * Função com a lógica do player
 * recebe um objeto player e atualiza para o próximo frame
 */
void player_logic(PLAYER* player){
    // update angle
    player->angle = new_angle(player->angle);

    player->speed = new_speed(player->speed);

    player->position = new_position(*player);

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
float new_speed(float speed){

    // verifica se o "pra frente" está sendo apertado;
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)){
        speed += PLAYER_ACCELERATION;
    } else {
        speed -= PLAYER_ACCELERATION;
    } 

    if (speed < 0) speed = 0;
    if (speed > PLAYER_MAX_SPEED) speed = PLAYER_MAX_SPEED;

    return speed;
}

/**
 * função que atualiza a posição do player
 */
POSITION new_position(PLAYER player){

    POSITION pos;

    pos.x = player.position.x - player.speed * cos(player.angle * PI / 180);
    pos.y = player.position.y - player.speed * sin(player.angle * PI / 180);

    if (pos.x > LARGURA) pos.x = 0;
    if (pos.x < 0) pos.x = 1000;
    if (pos.y > ALTURA) pos.y = 0;
    if (pos.y < 0) pos.y = 1000;

    return pos;

}

/**
 * Função que dada um kobjeto player e um sprite desenha o player na tela
 */
void draw_player(PLAYER player, Texture2D sprite){

    DrawTexturePro(
        sprite,
        (Rectangle) { 0.0f, 0.0f, (float)sprite.width, (float)sprite.height },
        (Rectangle) { player.position.x, player.position.y, (float)sprite.width, (float)sprite.height },
        (Vector2) {(float)sprite.width/2.0f, (float)sprite.height/2.0f },
        player.angle - 90,
        WHITE
    );

}
// inclusão de bibliotecas
#include "player.h"
#include "raylib.h"

// definir constantes 
#define ANGULAR_SPEED 1

/**
 * Função com a lógica do player
 * recebe um objeto player e atualiza para o próximo frame
 */
void player_logic(PLAYER* player){
    // update angle
    player->angle = new_angle(player->angle);

}

/**
 * Função que le as entradas do teclado e retorna o novo valor do ângulo do jogador
 */
float new_angle(float angle){
    
    // verifica se A ou seta pra esquerda está apertado
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
        // se sim, subtrai a velocidade angular do angulo
        angle += ANGULAR_SPEED;
    } 
    
    // verifica se D ou seta para direita está apertado
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        // se sim, subtrai a velocidade angular do angulo
        angle -= ANGULAR_SPEED;
    }

    // mantem os valores entre 0 e 360
    if (angle > 360) angle -= 360;
    if (angle < 0) angle += 360;

    return angle;

}

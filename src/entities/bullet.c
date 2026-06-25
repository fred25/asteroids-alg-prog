#include "bullet.h"

/**
 * Atualiza a lista de balas em cada frame.
 * Move cada bala e reduz seu tempo de vida.
 * Remove a bala quando sua vida chegar a zero.
 */
void bullet_logic(BULLET* bullets, int* len){

    int i;

    // atualiza cada bala viva
    for (i = 0; i < *len; i++){

        bullets[i].position = new_position(bullets[i].position, BULLET_ACCELERATION, bullets[i].angle);
        bullets[i].life--;

        // se a bala expirou, remove-a da lista
        if (bullets[i].life <= 0) {
            (*len)--;
            bullets[i] = bullets[*len];
            i--;
        }
    }
}

/**
 * Desenha todas as balas ativas na tela.
 */
void draw_bullets(BULLET* bullets, int len, Texture2D sprite){

    int i;
    for (i = 0; i < len; i++){
        draw_sprite(bullets[i].position, sprite, bullets[i].angle);
    }

}
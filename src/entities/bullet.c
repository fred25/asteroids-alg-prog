#include "bullet.h"

/**
 * Function responsible for updating a list of bulllets
 */
void bullet_logic(BULLET* bullets, int len){

    int i;

    // update a list of bullets
    for (i = 0; i < len; i ++){

        bullets[i].position = new_position(bullets[i].position, BULLET_ACCELERATION, bullets[i].angle);
    }
}

void draw_bullets(BULLET* bullets, int len, Texture2D sprite){

    int i;
    for (i=0; i<len; i++){
        draw_sprite(bullets[i].position, sprite, bullets[i].angle);
    }

}
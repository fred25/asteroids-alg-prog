#include "bullet.h"

/**
 * Function responsible for updating a list of bulllets
 */
void bullet_logic(BULLET* bullets, int len){

    int i;

    // update a list of bullets
    for (i = 0; i < len; i ++){

        single_bullet_logic(&bullets[i]);
    }
}

/**
 * Function responsible for updating a single bullet
 */
void single_bullet_logic(BULLET* bullet){

    bullet->position = new_position(*bullet);

}

/**
 * Funcition that updates bullet position
 */
POSITION new_position(BULLET bullet){

    POSITION pos;

    pos.x = bullet.position.x + BULLET_ACCELERATION * cos((bullet.angle + 90) * PI / 180);
    pos.y = bullet.position.y - BULLET_ACCELERATION * sin((bullet.angle + 90) * PI / 180);

    if (pos.x > LARGURA) pos.x = 0;
    if (pos.x < 0) pos.x = LARGURA;
    if (pos.y > ALTURA) pos.y = 0;
    if (pos.y < 0) pos.y = ALTURA;

    return pos;

}

/**
 * Função que dada um objeto bullet e um sprite desenha o bullet na tela
 */
void draw_bullet(BULLET* bullet, Texture2D sprite){

    DrawTexturePro(
        sprite,
        (Rectangle) { 0.0f, 0.0f, (float)sprite.width, (float)sprite.height },
        (Rectangle) { bullet->position.x, bullet->position.y, (float)sprite.width, (float)sprite.height },
        (Vector2) {(float)sprite.width/2.0f, (float)sprite.height/2.0f },
        bullet->angle + 90,
        WHITE
    );

}
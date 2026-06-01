#include "definitions.h"
#include <math.h>
#include "raylib.h"

/**
 * Função que dada uma posição, uma velocidade e um ângulo define
 * uma nova posição para o frame seguinte
 */
POSITION new_position(POSITION position, int speed, float angle){

    POSITION pos;

    pos.x = position.x + speed * sin(angle * PI / 180);
    pos.y = position.y - speed * cos(angle * PI / 180);

    if (pos.x > LARGURA) pos.x = 0;
    if (pos.x < 0) pos.x = LARGURA;
    if (pos.y > ALTURA) pos.y = 0;
    if (pos.y < 0) pos.y = ALTURA;

    return pos;

}


/**
 * Função que dada uma posição e um sprite desenha o sprite na posição na tela
 * e um ângulo
 */
void draw_sprite(POSITION position, Texture2D sprite, float angle){

    DrawTexturePro(
        sprite,
        (Rectangle) { 0.0f, 0.0f, (float)sprite.width, (float)sprite.height },
        (Rectangle) {position.x,position.y, (float)sprite.width, (float)sprite.height },
        (Vector2) {(float)sprite.width/2.0f, (float)sprite.height/2.0f },
        angle,
        WHITE
    );

}
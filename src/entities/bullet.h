#ifndef BULLET_H
#define BULLET_H
#include "../game/definitions.h"
#include <math.h>
#include "raylib.h"

// estrutura da bala
typedef struct{
    POSITION position; // posição atual da bala
    float angle;       // ângulo de disparo
    int life;          // tempo de vida restante
} BULLET;

// funções das balas
void bullet_logic(BULLET*, int*);
void draw_bullets(BULLET*, int, Texture2D);
#endif
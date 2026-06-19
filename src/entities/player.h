#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "../game/definitions.h"
#include "bullet.h"

// estruturas
typedef struct {
    POSITION position;
    float speedx;
    float speedy;
    float angle;
    int vida;
} PLAYER;

// funcoes
void player_logic(PLAYER*);
float new_angle(float);
void new_speed(float *speedx, float *speedy, float angle);
void shoot(BULLET* bullets, int* n_bullets, PLAYER player);
#endif
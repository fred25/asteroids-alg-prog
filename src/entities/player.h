#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "../game/definitions.h"
#include "bullet.h"

// estruturas
typedef struct {
    POSITION position;
    float angle;
    float speed;
    int vida;
} PLAYER;

// funcoes
void player_logic(PLAYER*);
float new_angle(float);
float new_speed(float);
void shoot(BULLET* bullets, int* n_bullets, PLAYER player);
#endif
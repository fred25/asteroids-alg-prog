#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "../game/definitions.h"
#include "bullet.h"

// informações do jogador
typedef struct {
    POSITION position; // posição 2D do jogador
    float speedx;      // velocidade em x
    float speedy;      // velocidade em y
    float angle;       // ângulo de rotação da nave
    int vida;          // quantidade de vidas restantes
} PLAYER;

// funções do comportamento do jogador
void player_logic(PLAYER*);
float new_angle(float);
void new_speed(float *speedx, float *speedy, float angle);
void shoot(BULLET* bullets, int* n_bullets, PLAYER player);
#endif
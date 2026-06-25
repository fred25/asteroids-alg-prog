#ifndef ASTEROID_H
#define ASTEROID_H
#include "raylib.h"
#include "../game/definitions.h"

// velocidade do asteroide
typedef struct{
    float vx;
    float vy;
} VELOCITY;

// estrutura de asteroide
typedef struct{
    POSITION position; // posição atual
    VELOCITY velocity; // direção e velocidade
    int active;       // indica se está em jogo (0 ou 1)
} ASTEROID;

// funções dos asteroides
void asteroid_logic(ASTEROID asteroids[], int n_asteroids);
void draw_asteroid(ASTEROID asteroids[], int n_asteroids, Texture2D asteroid_sprite);
void move_asteroid(ASTEROID* asteroid);
void wrap_asteroid(ASTEROID* asteroid);

#endif
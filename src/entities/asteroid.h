#ifndef ASTEROID_H
#define ASTEROID_H
#include <stdbool.h>
#include "raylib.h"
#include "../game/definitions.h"

// estruturas
typedef struct{
    float vx;
    float vy;
} VELOCITY;

typedef struct{
    POSITION position;
    VELOCITY velocity;
    bool active;
} ASTEROID;


// funcoes
void asteroid_logic(ASTEROID asteroids[], int n_asteroids);
void draw_asteroid(ASTEROID asteroids[], int n_asteroids, Texture2D asteroid_sprite);
void move_asteroid(ASTEROID* asteroid);
void wrap_asteroid(ASTEROID* asteroid);

#endif
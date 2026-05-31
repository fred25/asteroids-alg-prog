#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "definitions.h"

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
#endif
#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include "raylib.h"

// definindo estruturas globais
typedef struct {
    float x;
    float y;
} POSITION;

// definindo funções globais
POSITION new_position(POSITION, float, float);
void draw_sprite(POSITION position, Texture2D sprite, float angle);

// definindo valores para o desenho dos objetos
#define LARGURA 1200
#define ALTURA 800

// definindo tamanho dos objetos
#define PLAYER_SIZE 64
#define ASTEROID_SIZE 96

// definindo valor máximo para balas
#define MAX_BALAS 100

//player constansts
// definir constantes 
#define PLAYER_ANGULAR_SPEED 6
#define PLAYER_ACCELERATION 0.05
#define PLAYER_MAX_SPEED 10.0
#define PLAYER_FRICTION 0.999

// bullet constants
#define BULLET_ACCELERATION 15
#define BULLET_LIFE 60

// asteroids constants
#define MAX_ASTEROIDES 15


#endif
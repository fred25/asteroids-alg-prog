#include "raylib.h"

// estruturas
typedef struct {
    int x;
    int y;
    float angle;
    float speed;
    int vida;
} PLAYER;

// funcoes
void player_logic(PLAYER*);
float new_angle(float);
float new_speed(float);

void draw_player(PLAYER, Texture2D);
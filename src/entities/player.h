#include "raylib.h"

// estruturas
typedef struct {
    int x;
    int y;
} POSITION;

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
POSITION new_position(PLAYER);
void draw_player(PLAYER, Texture2D);
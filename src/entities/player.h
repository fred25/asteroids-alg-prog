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
POSITION new_position(PLAYER);
void draw_player(PLAYER, Texture2D);
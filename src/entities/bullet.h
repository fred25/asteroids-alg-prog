#include "definitions.h"
#include <math.h>
#include "raylib.h"

// define bullet struct
typedef struct{
    POSITION position;
    float angle;
} BULLET;

// define funcitons
void bullet_logic(BULLET*, int);
void single_bullet_logic(BULLET*);
POSITION new_position(BULLET);
void draw_bullet(BULLET*, Texture2D sprite);
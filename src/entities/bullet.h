#ifndef BULLET_H
#define BULLET_H
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
#endif
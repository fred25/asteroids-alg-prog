#ifndef COLLISION_H
#define COLLISION_H
#include <stdbool.h>
#include "../game/game.h"

void collision_logic(GAME* game);
bool check_player_collision(PLAYER player, ASTEROID asteroid);
void damage_player(GAME* game);


#endif
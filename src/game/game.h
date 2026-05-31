#include "raylib.h"
#include "definitions.h"
#include "player.h"
#include "bullet.h"

#define PLAYER_SPRITE_PATH "assets/sprites/player_beta.png"
#define BULLET_SPRITE_PATH "assets/sprites/bullet_beta.png"

// define GAME structure
typedef struct {
    // player related
    PLAYER player;
    Texture2D player_sprite;

    // bullet related
    BULLET bullets[MAX_BALAS];
    int n_bullets;
    Texture2D bullet_sprite;

    // game related
    int points;

} GAME;

void game();
void game_logic(GAME*);
void draw_game(GAME*);
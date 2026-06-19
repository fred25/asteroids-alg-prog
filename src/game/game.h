#include "raylib.h"
#include <stdbool.h>
#include "definitions.h"
#include "../entities/player.h"
#include "bullet.h"
#include "../entities/asteroid.h"

#define PLAYER_SPRITE_PATH "assets/sprites/player_beta.png"
#define BULLET_SPRITE_PATH "assets/sprites/bullet_beta.png"
#define ASTEROID_SPRITE_PATH "assets/sprites/asteroid_beta.png"

// define game states 
typedef enum {
    GAME_STATE_MENU,
    GAME_STATE_PLAYING,
    GAME_STATE_PAUSED,
    GAME_STATE_GAMEOVER
} GAME_STATE;

// define GAME structure
typedef struct {
    // player related
    PLAYER player;
    Texture2D player_sprite;

    // bullet related
    BULLET bullets[MAX_BALAS];
    int n_bullets;
    Texture2D bullet_sprite;

    // asteroid related
    ASTEROID asteroids[MAX_ASTEROIDES];
    int n_asteroids;
    Texture2D asteroid_sprite;


    // game related
    int points;
    int current_level;
    GAME_STATE state;
    bool should_close;

} GAME;


void game();
void game_logic(GAME*);
void draw_game(GAME*);
void deal_with_file(char* filename, GAME* game);
void update_game_state(GAME*);
void draw_game_state(GAME*);
void draw_menu();
void draw_pause();
void save_game(GAME);
void load_save(GAME*);
void draw_game_over(GAME*);
void start_new_game(GAME* game);
void update_menu(GAME*);
void update_pause(GAME*);
void update_game_over(GAME*);
void quit_game(GAME* game);

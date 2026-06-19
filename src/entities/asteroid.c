# include "asteroid.h"

#define ASTEROID_SPEED_MULTIPLIER 100.0f
#define ASTEROID_SIZE 96

// funcao com a logica do asteroide
void asteroid_logic(ASTEROID asteroids[], int n_asteroids){
    for (int i = 0; i < n_asteroids; i++) {
        if (asteroids[i].active) {
            move_asteroid(&asteroids[i]);
            wrap_asteroid(&asteroids[i]);
        }
    }
}

// funcao que controla o movimento do asteroide
void move_asteroid(ASTEROID* asteroid){
    float delta_time = GetFrameTime();

    asteroid->position.x += asteroid->velocity.vx * ASTEROID_SPEED_MULTIPLIER * delta_time;
    asteroid->position.y += asteroid->velocity.vy * ASTEROID_SPEED_MULTIPLIER * delta_time;

}

// funcao -> se o asteroide ir pra fora da tela de um lado, faz ele aparecer do outro
void wrap_asteroid(ASTEROID* asteroid) {
    if (asteroid->position.x > LARGURA) {
        asteroid->position.x = 0;
    }

    if (asteroid->position.x < 0) {
        asteroid->position.x = LARGURA;
    }

    if (asteroid->position.y > ALTURA) {
        asteroid->position.y = 0;
    }

    if (asteroid->position.y < 0) {
        asteroid->position.y = ALTURA;
    }
}

// funcao que desenha o asteroide 
void draw_asteroid(ASTEROID asteroids[], int n_asteroids, Texture2D asteroid_sprite){ 
    for (int i = 0; i < n_asteroids; i++) {
        if (asteroids[i].active) {
            Vector2 position = {
                asteroids[i].position.x,
                asteroids[i].position.y
            };

            float scale = ASTEROID_SIZE / (float)asteroid_sprite.width;

            DrawTextureEx(
                asteroid_sprite,
                position,
                0.0f,
                scale,
                WHITE
            );
        }
    }
}
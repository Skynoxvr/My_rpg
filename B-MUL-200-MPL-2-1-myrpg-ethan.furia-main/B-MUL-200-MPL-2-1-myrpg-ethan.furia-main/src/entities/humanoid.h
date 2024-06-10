/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-ethan.furia [WSL: Ubuntu-24.04]
** File description:
** humanoid
*/

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/Network.h>

enum e_animations {
    IDLE,
    WALK,
    ATTACK,
};

enum e_sides {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

typedef struct stat_s {
    int health;
    int damage;
    int defense;
    float speed;
} humanoid_stats_t;

typedef struct state_s {
    sfBool is_alive;
    sfBool is_attacking;
    sfBool can_move;
    sfBool can_attack;
} humanoid_state_t;

typedef struct humanoid_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfClock *clock;
    sfClock *move_clock;
    sfTime time;
    float seconds;
    sfVector2f move_direction;
    float move_seconds;
    humanoid_stats_t *stats;
    humanoid_state_t *state;
    enum e_animations animation;
    enum e_sides side;
    int magnitude;
} humanoid_t;

humanoid_t *create_entity(char *texture_path, sfVector2f pos, sfVector2f scale,
    sfIntRect rect);
void destroy_entity(humanoid_t *humanoid);

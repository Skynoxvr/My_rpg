/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-ethan.furia [WSL: Ubuntu-24.04]
** File description:
** entities
*/

#include "../game.h"
#include "humanoid.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

static void init_humanoid_stats(humanoid_t **humanoid)
{
    (*humanoid)->stats = malloc(sizeof(humanoid_stats_t));
    (*humanoid)->stats->health = 100;
    (*humanoid)->stats->damage = 10;
    (*humanoid)->stats->defense = 10;
    (*humanoid)->stats->speed = 10;
    (*humanoid)->state = malloc(sizeof(humanoid_state_t));
    (*humanoid)->state->is_alive = sfTrue;
    (*humanoid)->state->is_attacking = sfFalse;
    (*humanoid)->state->can_move = sfTrue;
    (*humanoid)->state->can_attack = sfTrue;
}

static sfTexture *check_idle_side(humanoid_t *humanoid)
{
    sfTexture *texture = NULL;

    if (humanoid->side == UP) {
        texture = sfTexture_createFromFile("src/assets/player/_up idle.png",
            NULL);
    }
    if (humanoid->side == DOWN) {
        texture = sfTexture_createFromFile("src/assets/player/_down idle.png",
            NULL);
    }
    if (humanoid->side == LEFT) {
        texture = sfTexture_createFromFile("src/assets/player/_side idle.png",
            NULL);
    }
    if (humanoid->side == RIGHT) {
        texture = sfTexture_createFromFile("src/assets/player/_side idle.png",
            NULL);
    }
    return (texture);
}

static sfTexture *check_walk_side(humanoid_t *humanoid)
{
    sfTexture *texture = NULL;

    if (humanoid->side == UP) {
        texture = sfTexture_createFromFile("src/assets/player/_up walk.png",
            NULL);
        sfSprite_setScale(get_window()->player->humanoid->sprite, (sfVector2f) {.5, .5});
    }
    if (humanoid->side == DOWN) {
        texture = sfTexture_createFromFile("src/assets/player/_down walk.png",
            NULL);
        sfSprite_setScale(get_window()->player->humanoid->sprite, (sfVector2f) {.5, .5});
    }
    if (humanoid->side == LEFT) {
        texture = sfTexture_createFromFile("src/assets/player/_side walk.png",
            NULL);
        sfSprite_setScale(get_window()->player->humanoid->sprite, (sfVector2f) {.5, .5});
    }
    if (humanoid->side == RIGHT) {
        texture = sfTexture_createFromFile("src/assets/player/_side walk.png",
            NULL);
        sfSprite_setScale(get_window()->player->humanoid->sprite, (sfVector2f) {-.5, .5});
    }
    return (texture);
}

void check_animation_state(humanoid_t *humanoid)
{
    sfTexture *texture = NULL;

    if (humanoid->animation == IDLE) {
        texture = check_idle_side(humanoid);
        sfSprite_setTexture(humanoid->sprite, texture, sfTrue);
        sfSprite_setTextureRect(humanoid->sprite, (sfIntRect) {0, 0, 64, 64});
    }
    if (humanoid->animation == WALK) {
        texture = check_walk_side(humanoid);
        sfSprite_setTexture(humanoid->sprite, texture, sfTrue);
        sfSprite_setTextureRect(humanoid->sprite, (sfIntRect) {0, 0, 64, 64});
    }
}

void animate_entity(humanoid_t *humanoid, int offset, int top_offset,
    int max_value)
{
    check_animation_state(humanoid);
    humanoid->time = sfClock_getElapsedTime(humanoid->clock);
    humanoid->seconds = humanoid->time.microseconds / 1000000.0;
    if (humanoid->seconds > .3) {
        if (humanoid->rect.left >= max_value) {
            humanoid->rect.left = 0;
            humanoid->rect.top = 0;
        }
        else {
            humanoid->rect.left += offset;
            humanoid->rect.top += top_offset;
        }
        sfSprite_setTextureRect(humanoid->sprite, humanoid->rect);
        sfClock_restart(humanoid->clock);
    }
}

humanoid_t *create_entity(char *texture_path, sfVector2f pos, sfVector2f scale,
    sfIntRect rect)
{
    humanoid_t *humanoid = malloc(sizeof(*humanoid));

    humanoid->sprite = sfSprite_create();
    humanoid->texture = sfTexture_createFromFile(texture_path, NULL);
    humanoid->rect = rect;
    humanoid->clock = sfClock_create();
    humanoid->move_direction = (sfVector2f){0, 0};
    humanoid->move_seconds = 0.0;
    humanoid->move_clock = sfClock_create();
    sfSprite_setTexture(humanoid->sprite, humanoid->texture, sfTrue);
    sfSprite_setTextureRect(humanoid->sprite, rect);
    sfSprite_setPosition(humanoid->sprite, pos);
    sfSprite_setScale(humanoid->sprite, scale);
    sfSprite_setOrigin(humanoid->sprite, (sfVector2f) {32, 0});
    init_humanoid_stats(&humanoid);
    return (humanoid);
}

void destroy_entity(humanoid_t *humanoid)
{
    sfSprite_destroy(humanoid->sprite);
    sfTexture_destroy(humanoid->texture);
    sfClock_destroy(humanoid->clock);
    free(humanoid->stats);
    free(humanoid->state);
    free(humanoid);
}

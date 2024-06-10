/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-ethan.furia [WSL: Ubuntu-24.04]
** File description:
** entities
*/

#pragma once

#include "humanoid.h"

typedef struct entities_s {
    humanoid_t *entities;
    int nb_entities;
    struct entities_s *next;
} entities_t;

humanoid_t *create_entity(char *texture_path, sfVector2f pos, sfVector2f scale,
    sfIntRect texture_rect);
void destroy_entity(humanoid_t *humanoid);
void animate_entity(humanoid_t *humanoid, int offset, int top_offset,
    int max_value);

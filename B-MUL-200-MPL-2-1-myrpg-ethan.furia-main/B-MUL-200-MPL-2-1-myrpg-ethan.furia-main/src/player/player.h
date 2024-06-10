/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-ethan.furia [WSL: Ubuntu-24.04]
** File description:
** player
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

#include "../entities/humanoid.h"

typedef struct player_s {
    humanoid_t *humanoid;
    sfView *view;
    // inventory
    // player stats
} player_t;

player_t *create_player(void);
void set_view (void);
void change_sprite(humanoid_t *humanoid, char *texture_path);

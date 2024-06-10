/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-ethan.furia [WSL: Ubuntu-22.04]
** File description:
** window
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/Network.h>
#include "../player/player.h"

enum window_states {
    RUNNING,
    PAUSED,
    CINEMATIC
};

enum window_scenes {
    MAIN_MENU,
    GAME,
    SETTINGS,
    PAUSE,
    GAME_OVER,
    CITY,
    VILLAGE
};

typedef struct window_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    sfClock *clock;
    sfTime time;
    player_t *player;
    sfSprite *map_bg;
    sfSprite *map_top;
    float seconds;
    enum window_states state;
    enum window_scenes scene;
} window_t;

window_t *get_window(void);
void set_state(enum window_states state);

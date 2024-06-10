/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-ethan.furia [WSL: Ubuntu-22.04]
** File description:
** window
*/

#include "../game.h"

window_t *get_window(void)
{
    static window_t window;

    if (window.window)
        return (&window);
    window.mode = (sfVideoMode){1920, 1080, 32};
    window.window = sfRenderWindow_create(window.mode,
    "Zeldo: Link's Journey to the bed", sfClose | sfResize, NULL);
    window.clock = sfClock_create();
    window.state = RUNNING;
    return (&window);
}

void set_state(enum window_states state)
{
    get_window()->state = state;
}

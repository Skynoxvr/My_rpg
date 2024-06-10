/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-ethan.furia [WSL: Ubuntu-22.04]
** File description:
** event
*/

#include "../game.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <math.h>

void handle_pause(void)
{
    if (get_window()->state == RUNNING) {
        set_state(PAUSED);
        return;
    }
    set_state(RUNNING);
}

static void handle_player_inputs(void)
{
    sfVector2f position = sfSprite_getPosition(get_window()->player->humanoid->sprite);
    sfVector2f move = {0, 0};
    sfVector2f result = {0, 0};
    int magnitude = 0;
    int dir_x = 0;
    int dir_y = 0;

    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        move.y = -1;
        get_window()->player->humanoid->side = UP;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        move.x = -1;
        get_window()->player->humanoid->side = LEFT;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        move.y = 1;
        get_window()->player->humanoid->side = DOWN;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        move.x = 1;
        get_window()->player->humanoid->side = RIGHT;
    }
    magnitude = sqrt(pow(move.x, 2) + pow(move.y, 2));
    if (magnitude != 0) {
        dir_x = move.x / magnitude;
        dir_y = move.y / magnitude;
        move.x = dir_x * get_window()->player->humanoid->stats->speed;
        move.y = dir_y * get_window()->player->humanoid->stats->speed;
        get_window()->player->humanoid->animation = WALK;
        result = (sfVector2f) {position.x + move.x, position.y + move.y};
        sfSprite_setPosition(get_window()->player->humanoid->sprite, result);
    }
    get_window()->player->humanoid->magnitude = magnitude;
}

void is_button_clicked(button_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(get_window()->window);
    sfFloatRect button_rect = sfSprite_getGlobalBounds(button->button_sprite);

    if (!button->visible)
        return;
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    sfFloatRect_contains(&button_rect, mouse_pos.x, mouse_pos.y)) {
        button->button_state = PRESSED;
    }
    else
        button->button_state = RELEASED;
}

static void check_all_buttons()
{
    button_list_t *button_list = get_button_list();
    button_list_t *tmp = button_list;

    tmp = button_list;
    for (; tmp != NULL; tmp = tmp->next)
        is_button_clicked(tmp->button);
}

static void handle_window_inputs(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        handle_pause();
}

static void handle_player_inputs_stop(void)
{
    if (get_window()->player->humanoid->magnitude == 1)
        get_window()->player->humanoid->animation = IDLE;
}

void window_event_handler(void)
{
    if (get_window()->state == RUNNING)
        handle_player_inputs();
    while (sfRenderWindow_pollEvent(get_window()->window,
    &get_window()->event)) {
        if (get_window()->event.type == sfEvtClosed)
            sfRenderWindow_close(get_window()->window);
        if (get_window()->event.type == sfEvtKeyPressed)
            handle_window_inputs();
        if (get_window()->event.type == sfEvtKeyReleased)
            handle_player_inputs_stop();
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            check_all_buttons();
        }
    }
}

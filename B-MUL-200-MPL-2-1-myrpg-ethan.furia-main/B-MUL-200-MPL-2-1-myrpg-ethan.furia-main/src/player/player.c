/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-ethan.furia [WSL: Ubuntu-24.04]
** File description:
** player
*/

#include "../game.h"

void change_sprite(humanoid_t *humanoid, char *texture_path)
{
    sfTexture *texture = sfTexture_createFromFile(texture_path, NULL);

    sfSprite_setTexture(humanoid->sprite, texture, sfTrue);
}

void set_view (void)
{
    sfView_setCenter(get_window()->player->view,
    sfSprite_getPosition(get_window()->player->humanoid->sprite));
    sfRenderWindow_setView(get_window()->window, get_window()->player->view);
}

sfView *create_view(void)
{
    sfView *view = sfView_create();

    sfView_setCenter(view, (sfVector2f){0, 0});
    sfView_setSize(view, (sfVector2f){400, 300});
    return (view);
}

player_t *create_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->humanoid = create_entity("src/assets/player/_down idle.png", 
    (sfVector2f){0, 0}, (sfVector2f){.5, .5}, (sfIntRect){0, 0, 64, 64});
    player->humanoid->clock = sfClock_create();
    player->humanoid->seconds = 0;
    player->humanoid->stats->speed = .35;
    player->humanoid->move_direction = (sfVector2f){0, 0};
    player->humanoid->state->is_alive = sfTrue;
    player->humanoid->state->is_attacking = sfFalse;
    player->humanoid->state->can_move = sfFalse;
    player->humanoid->state->can_attack = sfFalse;
    player->view = create_view();
    return (player);
}

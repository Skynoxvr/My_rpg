/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** parsing.c
*/

#include <stddef.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "parsing.h"
#include "../game.h"


sfRectangleShape* create_rectangle_shape(sfVector2f size,
    sfVector2f position)
{
    sfRectangleShape* shape = sfRectangleShape_create();

    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setPosition(shape, position);
    return shape;
}

int check_collision(sfFloatRect playerBounds, sfVector2f collPos)
{
    sfRectangleShape* collisionArea =
        create_rectangle_shape((sfVector2f){48.0f, 48.0f}, collPos);
    sfFloatRect collisionBounds =
        sfRectangleShape_getGlobalBounds(collisionArea);
    int result = sfFloatRect_intersects(&playerBounds, &collisionBounds, NULL);

    sfRectangleShape_destroy(collisionArea);
    return result;
}

int is_within_collision_radius(float dx, float dy,
    sfFloatRect playerBounds, sfVector2f collPos)
{
    if (dx <= 25 && dy <= 25)
        return check_collision(playerBounds, collPos);
    return 0;
}

int manage_collisions(parsing_t *parsing)
{
    sfVector2f playerPos = sfSprite_getPosition(get_window()->player->humanoid->sprite);
    sfRectangleShape* playerPoint =
        create_rectangle_shape((sfVector2f){40, 40},
        (sfVector2f){playerPos.x + 13, playerPos.y + 30});
    sfFloatRect playerBounds = sfRectangleShape_getGlobalBounds(playerPoint);
    float dx;
    float dy;

    for (int i = 0; parsing->collision_file[i] != NULL; i++) {
        dx = fabs(parsing->collision_file[i][0] - playerPos.x);
        dy = fabs(parsing->collision_file[i][1] - playerPos.y);
        if (is_within_collision_radius(dx, dy, playerBounds,
            (sfVector2f){parsing->collision_file[i][0],
            parsing->collision_file[i][1]})) {
            return 1;
        }
    }
    return 0;
}

/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-ethan.furia [WSL: Ubuntu-22.04]
** File description:
** render
*/

#include "../game.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

static void animate_planet(button_t *planet)
{
    float seconds = 0.0;

    planet->button_time = sfClock_getElapsedTime(planet->button_clock);
    seconds = planet->button_time.microseconds / 1000000.0;
    if (seconds > .17) {
        if (planet->button_rect.left > 4800)
            planet->button_rect.left = 0;
        else
            planet->button_rect.left += 100;
        sfSprite_setTextureRect(planet->button_sprite, planet->button_rect);
        sfClock_restart(planet->button_clock);
    }
}

static void display_city(void)
{
    sfRenderWindow_clear(get_window()->window, sfBlack);
    animate_entity(get_window()->player->humanoid, 64, 0, 192);
    sfRenderWindow_drawSprite(get_window()->window, get_window()->map_bg, NULL);
    sfRenderWindow_drawSprite(get_window()->window, get_window()->player->humanoid->sprite, NULL);
    sfRenderWindow_drawSprite(get_window()->window, get_window()->map_top, NULL);
    set_view();
}

static void display_main_menu(image_t *background, button_t *planet)
{
    // sfVector2f pos = {0, 0};
    // sfFloatRect planet_size = sfSprite_getGlobalBounds(planet->button_sprite);

    // pos.x = (float) sfRenderWindow_getSize(get_window()->window).x / 2 -
    // (planet_size.width / 2);
    // pos.y = (float) sfRenderWindow_getSize(get_window()->window).y / 2 -
    // (planet_size.height / 2);
    // sfRenderWindow_clear(get_window()->window, sfBlack);
    // sfSprite_setPosition(planet->button_sprite, (sfVector2f) {
    //     pos.x, pos.y
    // });
    // animate_planet(planet);
    // sfRenderWindow_drawSprite(get_window()->window, background->button_sprite,
    // NULL);
    // sfRenderWindow_drawSprite(get_window()->window, planet->button_sprite,
    // NULL);
}

static void display_game(void)
{
    sfRenderWindow_clear(get_window()->window, sfBlue);
}

static void display_scene(void)
{
    if (get_window()->scene == CITY)
        display_city();
}

void render_window(image_t *background, button_t *planet)
{
    display_scene();
    sfRenderWindow_display(get_window()->window);
}

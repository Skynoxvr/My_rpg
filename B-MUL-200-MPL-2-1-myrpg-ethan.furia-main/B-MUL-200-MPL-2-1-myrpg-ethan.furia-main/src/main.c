/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-ethan.furia [WSL: Ubuntu-22.04]
** File description:
** main
*/

#include "game.h"
#include "user_interface/ui.h"
#include "window/window.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

int update(void)
{
    image_t *background = create_image("src/assets/star_background.png",
    (sfVector2f){0, 0}, (sfVector2f){.6, .6}, (sfIntRect){0, 0, 4096, 4096});
    button_t *planet = create_button("src/assets/menu_planet.png", (sfVector2f)
    {0, 0}, (sfVector2f){4, 4}, (sfIntRect){0, 0, 100, 100});
    button_list_t *button_list = get_button_list();

    add_button(&button_list, planet);
    while (sfRenderWindow_isOpen(get_window()->window)) {
        window_event_handler();
        render_window(background, planet);
    }
    return (0);
}

int main(int ac, __attribute((unused)) char **av)
{
    sfTexture *top = sfTexture_createFromFile("src/assets/map/city/City_haut.png",
    NULL);
    sfTexture *bg = sfTexture_createFromFile("src/assets/map/city/City_sol.png",
    NULL);

    if (ac != 1)
        return (84);
    get_window()->scene = CITY;
    get_window()->player = create_player();
    get_window()->map_bg = sfSprite_create();
    get_window()->map_top = sfSprite_create();
    sfSprite_setTexture(get_window()->map_bg, bg, sfTrue);
    sfSprite_setTexture(get_window()->map_top, top, sfTrue);
    update();
    return (0);
}

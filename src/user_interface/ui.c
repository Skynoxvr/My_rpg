/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-ethan.furia [WSL: Ubuntu-24.04]
** File description:
** ui
*/

#include "ui.h"
#include "../game.h"

button_t *create_button(char *texture_path, sfVector2f pos, sfVector2f scale,
    sfIntRect texture_rect)
{
    button_t *button = malloc(sizeof(*button));

    button->button_sprite = sfSprite_create();
    button->button_texture = sfTexture_createFromFile(texture_path, NULL);
    button->button_rect = texture_rect;
    button->button_clock = sfClock_create();
    button->button_seconds = 0.0;
    button->is_animated = sfFalse;
    button->visible = sfTrue;
    button->button_state = RELEASED;
    button->button_time = sfClock_getElapsedTime(button->button_clock);
    sfSprite_setTexture(button->button_sprite, button->button_texture, sfTrue);
    sfSprite_setTextureRect(button->button_sprite, texture_rect);
    sfSprite_setPosition(button->button_sprite, pos);
    sfSprite_setScale(button->button_sprite, scale);
    return (button);
}

image_t *create_image(char *texture_path, sfVector2f pos, sfVector2f scale,
    sfIntRect texture_rect)
{
    image_t *image = malloc(sizeof(*image));

    image->button_sprite = sfSprite_create();
    image->button_texture = sfTexture_createFromFile(texture_path, NULL);
    image->button_rect = texture_rect;
    image->button_clock = sfClock_create();
    image->button_time = sfClock_getElapsedTime(image->button_clock);
    image->button_seconds = 0;
    image->visible = sfTrue;
    image->is_animated = sfFalse;
    sfSprite_setTexture(image->button_sprite, image->button_texture, sfTrue);
    sfSprite_setTextureRect(image->button_sprite, texture_rect);
    sfSprite_setPosition(image->button_sprite, pos);
    sfSprite_setScale(image->button_sprite, scale);
    return (image);
}

text_label_t *create_text(char *text, sfVector2f pos, sfVector2f scale)
{
    text_label_t *text_label = malloc(sizeof(*text_label));

    text_label->text = sfText_create();
    text_label->font = sfFont_createFromFile("assets/title_font.ttf");
    text_label->color = sfBlack;
    text_label->background = sfRectangleShape_create();
    text_label->background_color = sfColor_fromRGB(255, 255, 255);
    text_label->visible = sfTrue;
    sfText_setString(text_label->text, text);
    sfText_setFont(text_label->text, text_label->font);
    sfText_setCharacterSize(text_label->text, 35);
    sfText_setColor(text_label->text, text_label->color);
    sfText_setPosition(text_label->text, pos);
    sfText_setScale(text_label->text, scale);
    return (text_label);
}

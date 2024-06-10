/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-ethan.furia [WSL: Ubuntu-24.04]
** File description:
** ui
*/

#pragma once

#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Time.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/Network.h>

enum button_states_e {
    HOVER,
    PRESSED,
    RELEASED
};

typedef struct button_s {
    sfSprite *button_sprite;
    sfTexture *button_texture;
    sfIntRect button_rect;
    sfClock *button_clock;
    sfTime button_time;
    float button_seconds;
    sfBool is_animated;
    sfBool visible;
    enum button_states_e button_state;
} button_t;

typedef struct image_s {
    sfSprite *button_sprite;
    sfTexture *button_texture;
    sfIntRect button_rect;
    sfClock *button_clock;
    sfTime button_time;
    float button_seconds;
    sfBool visible;
    sfBool is_animated;
} image_t;

typedef struct text_label_s {
    sfText *text;
    sfFont *font;
    sfColor color;
    sfRectangleShape *background;
    sfColor background_color;
    sfBool visible;
} text_label_t;

typedef struct button_list_s {
    button_t *button;
    struct button_list_s *next;
} button_list_t;

typedef struct image_list_s {
    image_t *image;
    struct image_list_s *next;
} image_list_t;

typedef struct text_label_list_s {
    text_label_t *text_label;
    struct text_label_list_s *next;
} text_label_list_t;

image_t *create_image(char *texture_path, sfVector2f pos, sfVector2f scale,
    sfIntRect texture_rect);
button_t *create_button(char *texture_path, sfVector2f pos, sfVector2f scale,
    sfIntRect texture_rect);
text_label_t *create_text(char *text, sfVector2f pos, sfVector2f scale);
button_list_t *get_button_list(void);
void add_button(button_list_t **button_list, button_t *button);

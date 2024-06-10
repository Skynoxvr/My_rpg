/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-myrpg-ethan.furia [WSL: Ubuntu-24.04]
** File description:
** buttons
*/

#include "ui.h"

button_list_t *get_button_list(void)
{
    static button_list_t *button_list = NULL;

    if (button_list == NULL) {
        button_list = malloc(sizeof(button_list_t));
        button_list->button = NULL;
        button_list->next = NULL;
    }
    return (button_list);
}

void add_button(button_list_t **button_list, button_t *button)
{
    button_list_t *tmp;

    if ((*button_list)->button == NULL) {
        (*button_list)->button = button;
        (*button_list)->next = NULL;
    } else {
        tmp = *button_list;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = malloc(sizeof(button_list_t));
        tmp->next->button = button;
        tmp->next->next = NULL;
    }
}

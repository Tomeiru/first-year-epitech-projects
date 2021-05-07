/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** slot button
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "graphics/texture.h"
#include "elements/entities/slot_button.h"

void slot_button_move(element_t *element, sfVector2f pos)
{
    slot_button_t *button = (slot_button_t*) element;
    sfVector2f icon_pos = {pos.x + 8, pos.y + 8};

    default_element_move(element, pos);
    sfSprite_setPosition(button->icon, icon_pos);
}

void slot_button_draw(element_t *element, sfRenderWindow *window)
{
    slot_button_t *button = (slot_button_t*) element;

    sfRenderWindow_drawSprite(window, button->sprite, 0);
    sfRenderWindow_drawSprite(window, button->icon, 0);
}

void slot_button_destroy(element_t *element)
{
    slot_button_t *button = (slot_button_t*) element;

    sfSprite_destroy(button->sprite);
    sfText_destroy(button->text);
    sfSprite_destroy(button->icon);
    free(button);
}
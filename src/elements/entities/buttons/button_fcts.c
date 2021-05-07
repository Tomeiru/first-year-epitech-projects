/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button default fcts
*/

#include <stdlib.h>
#include "actions.h"
#include "elements/entities/button.h"

void button_move(element_t *element, sfVector2f pos)
{
    button_t *button = (button_t*) element;
    sfFloatRect rect = sfSprite_getGlobalBounds(element->sprite);
    sfFloatRect text_rect = sfText_getGlobalBounds(button->text);
    sfVector2f text_pos = {pos.x + rect.width / 2 - text_rect.width / 2,
    pos.y + text_rect.height / 4};

    button->pos = pos;
    button->hitbox.left = pos.x;
    button->hitbox.top = pos.y;
    button->hitbox.width = (int) rect.width;
    button->hitbox.height = (int) rect.height;
    sfSprite_setPosition(button->sprite, pos);
    sfText_setPosition(button->text, text_pos);
}

void button_update(entity_t *entity, infos_t *infos, float elapsed)
{
    button_t *button = (button_t*) entity;

    if (button->press_time > -1) {
        button->press_time += elapsed;
        if (button->press_time >= PRESS_TIME) {
            button_set_clicked(button, 0, infos);
            button->press_time = -1;
        }
    }
}

int button_close_game(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;

    if (button_type == sfMouseLeft) {
        button_set_clicked(button, 1, infos);
        return (QUIT_GAME_ACTION);
    }
    return (0);
}
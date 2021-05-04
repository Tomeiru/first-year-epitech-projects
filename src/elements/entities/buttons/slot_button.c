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

slot_button_t *slot_button_create(infos_t *infos, sfVector2f pos)
{
    slot_button_t *button = (slot_button_t*)
    button_create_default(sizeof(slot_button_t), infos, "", pos);

    if (!button || slot_button_setup_icon(button, infos, pos))
        return (NULL);
    button->move = &slot_button_move;
    button->draw = &slot_button_draw;
    button->destroy = &slot_button_destroy;
    button->width = 35;
    button->height = 34;
    button->item = 0;
    sfSprite_setTexture(button->sprite, get_texture(infos, INV_SLOT_TEXT), 0);
    button_set_texture_rect((button_t*) button);
    element_set_hitbox((element_t*) button,
    sfSprite_getGlobalBounds(button->sprite));
    return (button);
}

int slot_button_setup_icon(slot_button_t *button,
infos_t *infos, sfVector2f pos)
{
    sfSprite *icon = sfSprite_create();

    if (!icon)
        return (1);
    button->icon = icon;
    sfSprite_setTexture(icon, get_texture(infos, ITEMS_TEXT), 0);
    sfSprite_setTextureRect(icon, (sfIntRect) {0, 0, 32, 32});
    sfSprite_setPosition(icon, pos);
    return (0);
}

void slot_button_set_item(slot_button_t *button, unsigned char item)
{
    button->item = item;
    sfSprite_setTextureRect(button->icon, (sfIntRect) {32 * item, 0, 32, 32});
}
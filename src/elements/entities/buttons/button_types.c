/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button types
*/

#include "graphics/texture.h"
#include "elements/entities/button.h"

button_t *inv_slot_create(infos_t *infos, char *text_str,
sfVector2f pos, int texture_height_offset)
{
    button_t *button = button_create_default(sizeof(button_t),
    infos, text_str, pos);

    button->width = 35;
    button->height = 34;
    button->texture_height_offset = texture_height_offset;
    sfSprite_setTexture(button->sprite,
    get_texture(infos, INV_SLOT_TEXT), 0);
    button_set_texture_rect(button);
    button_move((element_t*) button, pos);
    return (button);
}

button_t *text_button_create(infos_t *infos, char *text_str,
sfVector2f pos, int texture_height_offset)
{
    button_t *button = button_create_default(sizeof(button_t),
    infos, text_str, pos);

    button->width = 192;
    button->height = 50;
    button->texture_height_offset = texture_height_offset;
    sfSprite_setTexture(button->sprite,
    get_texture(infos, BUTTONS_TEXT), 0);
    button_set_texture_rect(button);
    button_move((element_t*) button, pos);
    return (button);
}

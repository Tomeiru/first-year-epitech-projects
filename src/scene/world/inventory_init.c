/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** inventory
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "inventory.h"
#include "scene/world_scene.h"
#include "elements/entities/button.h"

//faire un button rajouter un autre button
//button type créer un texte vide

int button_inv_slot_click(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;

    if (button_type == sfMouseLeft)
        printf("LEFT\n");
    if (button_type == sfMouseRight)
        printf("RIGHT\n");
    button_set_clicked(button, 1, infos);
    return (0);
}

static int inv_items_init(inventory_t *inv, infos_t *infos)
{
    element_t *element;
    int x_pos = 0;
    int y_pos = 0;

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        element = inv_slot_create(infos, "", (sfVector2f) {x_pos, y_pos}, 0);
        x_pos += SHIFT_VALUE;
        element->on_click = &button_inv_slot_click;
        if (i == 2 || i == 11) {
            x_pos = 0;
            y_pos += SHIFT_VALUE;
        }if (!element)
            return (1);
        subwindow_add_element((subwindow_t*) inv, element, 0);
    }
    return (0);
}

static int inv_keybind_init(inventory_t *inv, infos_t *infos)
{
    sfSprite *sprite;
    element_t *element;
    int x_pos = 0;
    int y_pos = 300;

    for (int i = 0; i < INV_KEYB_NB; i++) {
        element = element_create_default(sizeof(element_t), INV_KEYB,
        (sfVector2f) {x_pos, y_pos});
        x_pos += SHIFT_VALUE;
        sprite = sfSprite_create();
        if (!element || !sprite)
            return (1);
        sfSprite_setTexture(sprite, get_texture(infos, INV_SLOT_TEXT), 0);
        element->sprite = sprite;
        subwindow_add_element((subwindow_t*) inv, element, 0);
    }
    return (0);
}

int inventory_init(inventory_t *inv, infos_t *infos)
{
    if (inv_items_init(inv, infos) || inv_keybind_init(inv, infos))
        return (1);
}
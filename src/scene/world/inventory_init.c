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
#include <unistd.h>
int add_item_to_inventory(inventory_t *inv, list_t **elements, unsigned char item_id);
int remove_item_from_inventory(inventory_t *inv, list_t **elements,
int slot);


int button_inv_slot_click(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;

    if (button_type == sfMouseLeft)
        write(1, "LEFT\n", 5);
    if (button_type == sfMouseRight)
        write(1, "RIGHT\n", 6);
    button_set_clicked(button, 1, infos);
    return (0);
}

static int inv_slots_init(inventory_t *inv, infos_t *infos)
{
    button_t *element;
    int x_pos = 14;
    int y_pos = 63;

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        element = inv_slot_create(infos, "", (sfVector2f) {x_pos, y_pos}, 0);
        (i < 18) ? (x_pos += SHIFT_VALUE) : (x_pos += SHIFT_VALUE * 2);
        element->on_click = &button_inv_slot_click;
        (i == 8) ? ((x_pos = 14) && (y_pos += SHIFT_VALUE)) : (x_pos = x_pos);
        (i == 17) ? ((x_pos = 86) && (y_pos = 15)) : (x_pos = x_pos);
        if (!element)
            return (1);
        subwindow_add_element((subwindow_t*) inv, (element_t*)element, 0);
    }
    return (0);
}

static int inv_items_init(inventory_t *inv, infos_t *infos)
{
    sfSprite *sprite;
    element_t *element;
    int x_pos = 15;
    int y_pos = 64;

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        element = element_create_default(sizeof(element_t), INV_ITEM,
        (sfVector2f) {x_pos, y_pos});
        (i < 18) ? (x_pos += SHIFT_VALUE) : (x_pos += SHIFT_VALUE * 2);
        sprite = sfSprite_create();
        (i == 8) ? ((x_pos = 15) && (y_pos += SHIFT_VALUE)) : (x_pos = x_pos);
        (i == 17) ? ((x_pos = 87) && (y_pos = 16)) : (x_pos = x_pos);
        if (!element || !sprite)
            return (1);
        sfSprite_setTexture(sprite, get_texture(infos, ITEMS_TEXT), 0);
        sfSprite_setTextureRect(sprite, (sfIntRect) {inv->items[i] * 32, 0, 32, 32});
        element->sprite = sprite;
        subwindow_add_element((subwindow_t*) inv, (element_t*)element, 0);
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
    if (inv_items_init(inv, infos) || inv_slots_init(inv, infos)
    || inv_keybind_init(inv, infos))
        return (1);
    add_item_to_inventory(inv, &inv->elements, 1);
    remove_item_from_inventory(inv, &inv->elements, 0);
    return (0);
}
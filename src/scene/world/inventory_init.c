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

int add_item_to_inventory(inventory_t *inv, unsigned char item_id);
int remove_item_from_inventory(inventory_t *inv, int slot);

int button_inv_slot_click(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;

    UNUSED(button_type);
    button_set_clicked(button, 1, infos);
    return (0);
}

static int inventory_create_slots(inventory_t *inv, infos_t *infos)
{
    slot_button_t *button;
    sfVector2f pos;

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (i < 3)
            pos = (sfVector2f) {63 + i * SHIFT_VALUE * 3, 10};
        else
            pos = (sfVector2f) {9 + ((i - 3) % 9) * SHIFT_VALUE,
            60 + (i - 3) / 9 * 36};
        button = slot_button_create(infos, pos);
        if (!button)
            return (1);
        button->on_click = &button_inv_slot_click;
        inv->slots[i] = button;
        subwindow_add_element((subwindow_t*) inv, (element_t*) button, 1);
    }
    return (0);
}

int inventory_init(inventory_t *inv, infos_t *infos)
{
    if (inventory_create_slots(inv, infos))
        return (1);
    return (0);
}
/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** inventory_utils
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "inventory.h"
#include "elements/entities/slot_button.h"
#include "scene/world_scene.h"

int inventory_create_slots(inventory_t *inv, infos_t *infos)
{
    slot_button_t *button;
    sfVector2f pos;

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (i < 2)
            pos = (sfVector2f) {160 + i * SHIFT_VALUE * 4, 0};
        else
            pos = (sfVector2f) {SHIFT_VALUE * ((i - 2) % 9),
            SHIFT_VALUE * ((i - 2) / 9 + 1.5)};
        button = slot_button_create(infos, pos);
        if (!button)
            return (1);
        button->on_click = &button_inv_slot_click;
        inv->slots[i] = button;
        subwindow_add_element((subwindow_t*) inv, (element_t*) button, 1);
    }
    return (0);
}

int add_item_to_inventory(inventory_t *inv, unsigned char item_id)
{
    int i;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        if (inv->slots[i]->item == item_id) {
            slot_button_set_quantity(inv->slots[i],
            inv->slots[i]->quantity + 1);
            return (0);
        }
    }
    for (i = 2; i < INVENTORY_SIZE && inv->slots[i]->item != 0; i++);
    if (i == INVENTORY_SIZE)
        return (1);
    slot_button_set_item(inv->slots[i], item_id);
    return (0);
}

void remove_item_from_inventory(inventory_t *inv, unsigned char item_id)
{
    int i;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        if (inv->slots[i]->item == item_id) {
            slot_button_set_quantity(inv->slots[i],
            inv->slots[i]->quantity - 1);
            return;
        }
    }
    for (i = 0; i < INVENTORY_SIZE && inv->slots[i]->item != item_id; i++);
    if (i == INVENTORY_SIZE)
        return;
    slot_button_set_item(inv->slots[i], 0);
}

void set_item_to_inventory(inventory_t *inv, unsigned int item_id, int slot)
{
    slot_button_set_item(inv->slots[slot], item_id);
    slot_button_set_quantity(inv->slots[slot], 1);
}

int button_inv_slot_click(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    inventory_t *inv = ((world_scene_t*) infos->scene)->inventory;
    slot_button_t *button = (slot_button_t*) element;
    unsigned char it_temp;
    unsigned int quant_temp;

    UNUSED(button_type);
    button_set_clicked((button_t *)button, 1, infos);
    if (inv->slot_ptr == NULL)
        inv->slot_ptr = button;
    else {
        it_temp = inv->slot_ptr->item;
        quant_temp = inv->slot_ptr->quantity;
        slot_button_set_item(inv->slot_ptr, button->item);
        slot_button_set_quantity(inv->slot_ptr, button->quantity);
        slot_button_set_item(button, it_temp);
        slot_button_set_quantity(button, quant_temp);
        inv->slot_ptr = NULL;
    }
    return (0);
}
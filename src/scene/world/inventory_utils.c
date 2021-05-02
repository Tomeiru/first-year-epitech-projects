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

int add_item_to_inventory(inventory_t *inv, unsigned char item_id)
{
    int i = 0;

    for ( ;  i < INVENTORY_SIZE && inv->slots[i]->item != 0; i++);
    if (i == INVENTORY_SIZE)
        return (1);
    inv->slots[i]->item = item_id;
    sfSprite_setTextureRect(inv->slots[i]->icon, (sfIntRect)
    {32 * item_id, 0, 32, 32});
    return (0);
}

int remove_item_from_inventory(inventory_t *inv, int slot)
{
    inv->slots[slot]->item = 0;
    sfSprite_setTextureRect(inv->slots[slot]->icon, (sfIntRect)
    {0, 0, 32, 32});
    return (0);
}
/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** inventory_utils
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "inventory.h"
#include "scene/world_scene.h"

int add_item_to_inventory(inventory_t *inv, list_t **elements,
unsigned char item_id)
{
    int i = 0;
    int value = INVENTORY_SIZE * 2 + 2;
    list_t *backup = *elements;
    element_t *element;

    for ( ;  i < INVENTORY_SIZE && inv->items[i] != 0; i++);
    if (i == INVENTORY_SIZE)
        return (1);
    inv->items[i] = item_id;
    value -= i;
    for (int i = 0; i < value; i++)
        backup = backup->next;
    element = (element_t*) backup->data;
    sfSprite_setTextureRect(element->sprite, (sfIntRect)
    {32 * item_id, 0, 32, 32});
    return (0);
}

int remove_item_from_inventory(inventory_t *inv, list_t **elements,
int slot)
{
    int value = INVENTORY_SIZE * 2 + 2 - slot;
    list_t *backup = *elements;
    element_t *element;

    inv->items[slot] = 0;
    for (int i = 0; i < value; i++)
        backup = backup->next;
    element = (element_t*) backup->data;
    sfSprite_setTextureRect(element->sprite, (sfIntRect)
    {0, 0, 32, 32});
    return (0);
}
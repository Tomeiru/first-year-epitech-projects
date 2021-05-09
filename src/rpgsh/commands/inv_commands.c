/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** inv_commands
*/

#include "my_rpg.h"
#include "rpgsh/rpgsh.h"
#include "inventory.h"
#include "scene/world_scene.h"

void add_item_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    inventory_t *inv = ((world_scene_t*) infos->scene)->inventory;

    UNUSED(line);
    UNUSED(element);
    if (args[1] == NULL)
        return;
    add_item_to_inventory(inv, str_to_int(args[1]),
    args[2] ? str_to_int(args[2]) : 1);
}

void remove_item_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    inventory_t *inv = ((world_scene_t*) infos->scene)->inventory;

    UNUSED(line);
    UNUSED(element);
    if (args[1] == NULL)
        return;
    remove_item_from_inventory(inv,
    str_to_int(args[1]), args[2] ? str_to_int(args[2]) : -1);
}
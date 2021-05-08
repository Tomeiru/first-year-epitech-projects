/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** RPGSH conditions
*/

#include "my_rpg.h"
#include "scene/world_scene.h"
#include "elements/entities/player.h"

int item_rpgsh_condition(char ***line,
char **args, infos_t *infos, element_t *element)
{
    inventory_t *inv = ((world_scene_t*) infos->scene)->inventory;
    unsigned char item;

    UNUSED(line);
    UNUSED(element);
    if (!args[1])
        return (0);
    item = (unsigned char) (str_to_int(args[1]));
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inv->slots[i]->item == item)
            return (1);
    }
    return (0);
}

int player_in_range_condition(char ***line,
char **args, infos_t *infos, element_t *element)
{
    player_t *player;
    float dist;
    float elem_dist;

    UNUSED(line);
    if (!element || infos->state != WORLD || !args[2])
        return (0);
    dist = str_to_int(args[2]);
    player = ((world_scene_t*) infos->scene)->player;
    elem_dist = get_distance(player->pos, element->pos);
    return (elem_dist <= dist);
}

int player_is_moving_condition(char ***line,
char **args, infos_t *infos, element_t *element)
{
    player_t *player = ((world_scene_t*) infos->scene)->player;

    UNUSED(line);
    UNUSED(args);
    UNUSED(element);
    return ((player->mov_target.x != -1 && player->mov_target.y != -1));
}
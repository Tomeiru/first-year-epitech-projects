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
    UNUSED(line);
    UNUSED(args);
    UNUSED(infos);
    UNUSED(element);
    return (1);
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
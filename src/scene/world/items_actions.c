/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** items actions
*/

#include "my_rpg.h"
#include "scene/world_scene.h"

void item_action(unsigned char item, infos_t *infos)
{
    switch (item) {
        case 1:
            player_attack(((world_scene_t*) infos->scene)->player, infos);
            return;
        default:
            return;
    }
}
/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** items actions
*/

#include "my_rpg.h"
#include "inventory.h"
#include "audio/sound.h"
#include "scene/world_scene.h"

void item_action(unsigned char item, infos_t *infos)
{
    switch (item) {
        case SWORD:
            player_attack(((world_scene_t*) infos->scene)->player, infos);
            return;
        case HEALTH_POTION:
            potion_drink(infos);
            return;
        default:
            return;
    }
}

void potion_drink(infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    player_t *player = world_scene->player;

    if (player->health < player->max_health) {
        player_regen(world_scene->player, infos);
        remove_item_from_inventory(world_scene->inventory, HEALTH_POTION, 1);
        play_sound(infos, DRINKNG);
    }
}
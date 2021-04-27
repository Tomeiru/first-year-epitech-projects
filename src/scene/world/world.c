/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** world
*/

#include "my_rpg.h"
#include "maps.h"
#include "scene/world_scene.h"
#include "graphics/texture.h"
#include "rpgsh/rpgsh.h"

int world_load(world_scene_t *world_scene,
int map_id, int spawn_id, infos_t *infos)
{
    char *path = MAPS_PATH[map_id];
    const sfVector2f spawn = MAPS_SPAWN[map_id][spawn_id];
    map_t *map = map_create(path);

    if (!map)
        return (1);
    if (world_scene->map)
        map_destroy(world_scene->map);
    world_scene->map = map;
    sfSprite_setTexture(world_scene->background, map->map_texture, 0);
    world_scene->player->move((element_t*) world_scene->player, spawn);
    execute_rpgsh(world_scene->map->script, infos, NULL);
    return (0);
}

int check_world_load(world_scene_t *world_scene, infos_t *infos)
{
    player_t *player = world_scene->player;
    sfColor color = map_check_mask(world_scene->map,
    player->hitbox, CHANGE_ZONE_MASK_VALUE);

    if (!color.r)
        return (0);
    return (world_load(world_scene, color.g, color.b, infos));
}
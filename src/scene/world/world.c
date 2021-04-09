/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** world
*/

#include "my_rpg.h"
#include "scene/world_scene.h"
#include "graphics/texture.h"

int world_load(world_scene_t *world_scene, char *path)
{
    map_t *map = map_create(path);

    if (!map)
        return (1);
    if (world_scene->map)
        map_destroy(world_scene->map);
    world_scene->map = map;
    world_scene->player->move((element_t*) world_scene->player, (sfVector2f)
    {map->map_size.x / 2, map->map_size.y / 2});
    sfSprite_setTexture(world_scene->background, map->map_texture, 0);
    return (0);
}

/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** map
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "map.h"

map_t *map_create(char *path)
{
    map_t *map = malloc(sizeof(map_t));
    char *bkgd_path = my_strmerge(path, "background.png");
    sfTexture *map_texture = NULL;

    if (!bkgd_path || !(map_texture =
    sfTexture_createFromFile(bkgd_path, NULL)))
        return (NULL);
    map->map_texture = map_texture;
    map->map_size = sfTexture_getSize(map_texture);
    free(bkgd_path);
    return (map);
}

void map_destroy(map_t *map)
{
    sfTexture_destroy(map->map_texture);
    free(map);
}
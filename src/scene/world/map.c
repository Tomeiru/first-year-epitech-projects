/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** map
*/

#include <stdlib.h>
#include <math.h>
#include "my_rpg.h"
#include "map.h"

map_t *map_create(char *path)
{
    map_t *map = malloc(sizeof(map_t));
    char *bkgd_path = my_strmerge(path, "background.png");
    char *mask_path = my_strmerge(path, "mask.png");

    if (!map || !bkgd_path || !mask_path)
        return (NULL);
    map->map_texture = sfTexture_createFromFile(bkgd_path, NULL);
    map->mask_img = sfImage_createFromFile(mask_path);
    if (!map->map_texture || !map->mask_img)
        return (NULL);
    map->map_size = sfTexture_getSize(map->map_texture);
    free(bkgd_path);
    return (map);
}

char map_collision(map_t *map, sfIntRect hb)
{
    sfImage *mask = map->mask_img;

    for (int y = hb.top; y < hb.top + hb.height; y++) {
        for (int x = hb.left; x < hb.left + hb.width; x++) {
            if (sfImage_getPixel(mask, x, y).r == 255)
                return (1);
        }
    }

    return (0);
}

void map_destroy(map_t *map)
{
    sfTexture_destroy(map->map_texture);
    sfImage_destroy(map->mask_img);
    free(map);
}
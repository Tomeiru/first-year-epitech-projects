/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include <SFML/Graphics.h>

#define WALL_MASK_VALUE 250
#define BEHIND_WALL_MASK_VALUE 200
#define CHANGE_ZONE_MASK_VALUE 100

typedef struct world_scene_s world_scene_t;

typedef struct map_s {
    sfTexture *map_texture;
    sfImage *mask_img;
    sfVector2u map_size;
    char **script;
    int map_id;
    int spawn_id;
} map_t;

map_t *map_create(char *path);
char map_collision(map_t *map, sfIntRect hb);
void map_destroy(map_t *map, world_scene_t *world_scene);

sfColor map_check_mask(map_t *map, sfIntRect hb, unsigned char r_value);
void prior_map_collision(sfVector2f *move, sfIntRect hb, map_t *map);

void element_behind_wall(element_t *element, map_t *map);

#endif /* !MAP_H_ */

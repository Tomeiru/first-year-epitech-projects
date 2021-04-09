/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

typedef struct map_s {
    sfTexture *map_texture;
    sfImage *map_img;
    sfVector2u map_size;
} map_t;

map_t *map_create(char *path);
void map_destroy(map_t *map);

#endif /* !MAP_H_ */

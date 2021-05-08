/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** save system
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_rpg.h"
#include "scene/world_scene.h"

int does_savefile_exists(void)
{
    int fd = open("./savefile", O_RDONLY);

    if (fd == -1)
        return (0);
    close(fd);
    return (1);
}

void save_game(world_scene_t *world_scene)
{
    int fd = open("./savefile", O_WRONLY | O_CREAT, 0644);

    if (fd == -1)
        return;
    write(fd, &(world_scene->map->map_id), sizeof(int));
    write(fd, &(world_scene->map->spawn_id), sizeof(int));
    write(fd, &(world_scene->player->max_health), sizeof(float));
    write(fd, &(world_scene->player->health), sizeof(float));
    write(fd, &(world_scene->inventory->exp_bar->max), sizeof(float));
    write(fd, &(world_scene->inventory->exp_bar->value), sizeof(float));
    for (int i = 0; i < INVENTORY_SIZE; i++)
        write(fd, &(world_scene->inventory->slots[i]->item), sizeof(char));
    close(fd);
}

int load_save(world_scene_t *world_scene, infos_t *infos)
{
    int fd = open("./savefile", O_RDONLY, 0644);
    int map_id;
    int spawn_id;

    if (fd == -1)
        return (1);
    map_id = read_int(fd);
    spawn_id = read_int(fd);
    world_scene->player->max_health = read_float(fd);
    world_scene->player->health = read_float(fd);
    health_bar_update_values(world_scene->hud->health_bar,
    world_scene->player);
    world_scene->inventory->exp_bar->max = read_float(fd);
    bar_set_value(world_scene->inventory->exp_bar, read_float(fd));
    for (int i = 0; i < INVENTORY_SIZE; i++)
        set_item_to_inventory(world_scene->inventory, read_uchar(fd), i);
    close(fd);
    return (world_load(world_scene, map_id, spawn_id, infos));
}

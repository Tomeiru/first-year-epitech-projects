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
    write(fd, &(world_scene->player->health), sizeof(float));
    write(fd, &(world_scene->player->max_health), sizeof(float));
    close(fd);
}

void load_save(world_scene_t *world_scene, infos_t *infos)
{
    int fd = open("./savefile", O_RDONLY | O_CREAT, 0644);
    int map_id;
    int spawn_id;

    if (fd == -1)
        return;
    map_id = read_int(fd);
    spawn_id = read_int(fd);
    world_load(world_scene, map_id, spawn_id, infos);
    world_scene->player->health = read_float(fd);
    world_scene->player->max_health = read_float(fd);
    health_bar_update_values(world_scene->hud->health_bar,
    world_scene->player);
    close(fd);
}

int read_int(int fd)
{
    char int_buffer[sizeof(int)];
    int value = 0;

    read(fd, int_buffer, sizeof(int));
    value = *((int*) int_buffer);
    return (value);
}

float read_float(int fd)
{
    char float_buffer[sizeof(float)];
    float value = 0;

    read(fd, float_buffer, sizeof(float));
    value = *((float*) float_buffer);
    return (value);
}
/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** world rpgsh command
*/

#include "my_rpg.h"
#include "rpgsh/rpgsh.h"
#include "rpgsh/world_type_list.h"
#include "rpgsh/musics_list.h"

void world_type_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;

    UNUSED(line);
    UNUSED(element);
    if (!args[1])
        return;
    for (int i = 0; i < WORLD_TYPE_NB; i++) {
        if (!my_strcmp(args[1], WORLD_TYPE_NAME[i])) {
            world_scene->world_type = WORLD_TYPE[i];
            break;
        }
    }
}

void play_music_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    UNUSED(line);
    UNUSED(element);
    if (!args[1])
        return;
    for (int i = 0; i < MUSICS_NB; i++) {
        if (!my_strcmp(args[1], MUSICS_NAME[i])) {
            play_music(infos, MUSICS_ID[i]);
            break;
        }
    }
}

void player_move_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    player_t *player = world_scene->player;

    UNUSED(line);
    UNUSED(element);
    if (!args[1] || !args[2])
        return;
    player->mov_target.x = str_to_int(args[1]);
    player->mov_target.y = str_to_int(args[2]);
}

void victory_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;

    UNUSED(line);
    UNUSED(args);
    UNUSED(element);
    world_scene->victory = 1;
}
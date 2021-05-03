/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** RPGSH commands
*/

#include "my_rpg.h"
#include "rpgsh/rpgsh.h"
#include "elements/entities/npc.h"
#include "scene/world_scene.h"

void cam_target_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;

    UNUSED(line);
    if (infos->state != WORLD)
        return;
    if (!args[1])
        world_scene->cam_target = element;
    else if (!my_strcmp(args[1], "PLAYER"))
        world_scene->cam_target = (element_t*) world_scene->player;
}

void set_player_move_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;

    UNUSED(line);
    UNUSED(element);
    if (infos->state != WORLD || !args[1])
        return;
    world_scene->player->can_move = str_to_int(args[1]);
}

void destroy_element_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    UNUSED(line);
    UNUSED(args);
    scene_remove_element(infos->scene, element, 1);
}

void dialogue_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;

    UNUSED(line);
    UNUSED(args);
    UNUSED(element);
    dialogue_set_str(world_scene->hud->dialogue, infos,
    my_strdup("Ceci est un dialogue de test.\nCeci est un dialogue " \
    "de test.\nCeci est un dialogue de test."));
}
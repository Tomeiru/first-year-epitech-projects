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

void add_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    npc_t *npc;
    sfVector2f pos;

    UNUSED(element);
    if (!args[1] || !args[2])
        return;
    pos = (sfVector2f) {str_to_int(args[1]), str_to_int(args[2])};
    if (!(npc = npc_create(pos, get_texture(infos, PLAYER_TEXT))))
        return;
    rpgsh_attach_script((interactable_t*) npc, line);
    scene_add_element(infos->scene, (element_t*) npc, 1);
}

void move_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    npc_t *npc = (npc_t*) element;
    sfVector2f pos;

    UNUSED(line);
    UNUSED(infos);
    if (!args[1] || !args[2] || !npc)
        return;
    pos = (sfVector2f) {str_to_int(args[1]), str_to_int(args[2])};
    npc->mov_target = pos;
}

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
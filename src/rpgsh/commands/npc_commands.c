/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** add rpgsh commands
*/

#include "my_rpg.h"
#include "rpgsh/rpgsh.h"
#include "elements/entities/npc.h"

void add_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    npc_t *npc = NULL;
    sfVector2f pos = {0, 0};

    UNUSED(element);
    if (!args[1] || !args[2] || !args[3])
        return;
    pos = (sfVector2f) {str_to_int(args[2]), str_to_int(args[3])};
    if (!my_strcmp(args[1], "NPC"))
        npc = npc_create(pos, get_texture(infos, PLAYER_TEXT), args[4]);
    else if (!my_strcmp(args[1], "TRIGGER"))
        npc = trigger_create(pos, args[4]);
    if (!npc)
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
    if (args[3])
        npc->speed = str_to_float(args[3]);
    npc->mov_target = pos;
}

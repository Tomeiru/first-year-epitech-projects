/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** bonus commands
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "rpgsh/rpgsh.h"
#include "elements/entities/npc.h"
#include "scene/world_scene.h"

void open_url_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    char *cmd = NULL;

    UNUSED(line);
    UNUSED(element);
    UNUSED(infos);
    if (!args[1])
        return;
    cmd = my_strmerge("xdg-open ", args[1]);
    system(cmd);
    free(cmd);
}
/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** RPGSH commands
*/

#include "my_rpg.h"
#include "elements/entities/text.h"

void add_rpgsh_command(char **args, infos_t *infos, element_t *element)
{
    scene_t *scene = infos->scene;
    sfVector2f pos = {str_to_int(args[1]), str_to_int(args[2])};
    element_t *new_elem = (element_t*)
    text_create("TEST", infos->font, pos, 100);

    UNUSED(element);
    if (!new_elem)
        return;
    scene_add_element(scene, new_elem, 0);
}
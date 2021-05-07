/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** add rpgsh commands
*/

#include "my_rpg.h"
#include "rpgsh/rpgsh.h"
#include "elements/entities/npc.h"
#include "elements/entities/enemy.h"
#include "rpgsh/npc_textures.h"

void add_npc_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    npc_t *npc = NULL;
    sfVector2f pos = {0, 0};
    texture_t texture = GUARD_TEXT;

    UNUSED(element);
    if (!args[1] || !args[2] || !args[3] || !args[4])
        return;
    for (int i = 0; i < NPC_NB; i++) {
        if (!my_strcmp(NPC_NAME[i], args[1])) {
            texture = NPC_TEXTURE[i];
            break;
        }
    }
    pos = (sfVector2f) {str_to_int(args[2]), str_to_int(args[3])};
    npc = npc_create(pos, get_texture(infos, texture), args[4]);
    if (!npc)
        return;
    rpgsh_attach_script((interactable_t*) npc, line);
    scene_add_element(infos->scene, (element_t*) npc, 1);
}

void add_trigger_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    npc_t *npc = NULL;
    sfVector2f pos = {0, 0};

    UNUSED(element);
    if (!args[1] || !args[2] || !args[3])
        return;
    pos = (sfVector2f) {str_to_int(args[1]), str_to_int(args[2])};
    npc = trigger_create(pos, args[3]);
    if (!npc)
        return;
    rpgsh_attach_script((interactable_t*) npc, line);
    scene_add_element(infos->scene, (element_t*) npc, 1);
}

void add_enemy_rpgsh_command(char ***line,
char **args, infos_t *infos, element_t *element)
{
    enemy_t *enemy;
    sfVector2f pos = {0, 0};
    texture_t texture;

    UNUSED(line);
    UNUSED(element);
    if (!args[1] || !args[2] || !args[3] || !args[4] || !args[5])
        return;
    pos = (sfVector2f) {str_to_int(args[4]), str_to_int(args[5])};
    texture = !my_strcmp(args[1], "CLOSE") ? LEEVER_TEXT : OCTOROK_TEXT;
    enemy = enemy_create(sizeof(enemy_t), infos, pos, texture);
    enemy->attack = !my_strcmp(args[1], "CLOSE") ?
    &enemy_close_attack : enemy_ranged_attack;
    enemy->pattern = !my_strcmp(args[2], "VERTICAL") ?
    &enemy_vertical_pattern : enemy_horizonthal_pattern;
    enemy->dist = str_to_int(args[3]);
    if (!enemy)
        return;
    scene_add_element(infos->scene, (element_t*) enemy, 1);
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

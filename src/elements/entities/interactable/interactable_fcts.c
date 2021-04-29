/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** interactable
*/

#include "my_rpg.h"
#include "elements/entities/interactable.h"
#include "rpgsh/rpgsh.h"

void interactable_show_closest(infos_t *infos, hud_t *hud, player_t *player)
{
    interactable_t *interactable = (interactable_t*)
    element_get_closest(infos, player->pos, INTERACTABLE);
    float dist = 0;

    if (!interactable) {
        sfText_setString(hud->action_text->text, "");
        return;
    }
    dist = get_distance(player->pos, interactable->pos);
    if (dist <= PLAYER_ACTION_RANGE)
        sfText_setString(hud->action_text->text, interactable->action_name);
    else
        sfText_setString(hud->action_text->text, "");
}

void interactable_execute_closest(infos_t *infos, player_t *player)
{
    interactable_t *interactable = (interactable_t*)
    element_get_closest(infos, player->pos, INTERACTABLE);
    float dist = 0;

    if (!interactable)
        return;
    dist = get_distance(player->pos, interactable->pos);
    if (dist <= PLAYER_ACTION_RANGE)
        interactable->action(interactable, infos);
}

void interactable_default_action(interactable_t *interactable, infos_t *infos)
{
    char **action_script = interactable->action_script;

    if (action_script)
        execute_rpgsh_single_instruction(action_script,
        &(interactable->action_instruction), infos, (element_t*) interactable);
}
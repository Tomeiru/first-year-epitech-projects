/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions for NPCs
*/

#include "my_rpg.h"
#include "graphics/texture.h"
#include "elements/entities/interactable.h"
#include "rpgsh/rpgsh.h"

interactable_t *interactable_create(size_t size,
sfVector2f pos, sfTexture *texture)
{
    interactable_t *interactable = (interactable_t*)
    element_create_default(size, INTERACTABLE, pos);
    sfSprite *sprite = texture != NULL ? sfSprite_create() : NULL;

    if (!interactable || (texture != NULL && !sprite))
        return (NULL);
    interactable_create_sprite(interactable, sprite, texture, pos);
    interactable->hitbox = (sfIntRect) {pos.x, pos.y, 64, 64};
    interactable->update = &interactable_update;
    interactable->get_infos = &interactable_get_infos;
    interactable->action = &interactable_default_action;
    interactable->action_script = NULL;
    interactable->action_instruction = 0;
    interactable->update_script = NULL;
    interactable->update_instruction = 0;
    return (interactable);
}

void interactable_create_sprite(interactable_t *interactable,
sfSprite *sprite, sfTexture *texture, sfVector2f pos)
{
    if (!texture)
        return;
    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, 64, 64});
    sfSprite_setPosition(sprite, pos);
    interactable->sprite = sprite;
}

void interactable_update(entity_t *entity, infos_t *infos, float elapsed)
{
    interactable_t *interactable = (interactable_t*) entity;
    char **action_script = interactable->action_script;
    char **update_script = interactable->update_script;

    UNUSED(elapsed);
    if (action_script && interactable->action_instruction)
        execute_rpgsh_single_instruction(action_script,
        &(interactable->action_instruction), infos, (element_t*) interactable);
    else if (update_script)
        execute_rpgsh_single_instruction(update_script,
        &(interactable->update_instruction), infos, (element_t*) interactable);
}

void interactable_default_action(interactable_t *interactable, infos_t *infos)
{
    char **action_script = interactable->action_script;

    if (action_script)
        execute_rpgsh_single_instruction(action_script,
        &(interactable->action_instruction), infos, (element_t*) interactable);
}

void interactable_get_infos(element_t *element, char *str, int size)
{
    interactable_t *interactable = (interactable_t*) element;

    if (size < 16)
        return;
    my_strcpy(str, interactable->action_name);
}
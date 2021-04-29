/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions for NPCs
*/

#include "my_rpg.h"
#include "graphics/texture.h"
#include "scene/world_scene.h"
#include "elements/entities/interactable.h"

interactable_t *interactable_create(sfVector2f pos, sfTexture *texture,
interactable_action_fct_t action, char *action_name)
{
    interactable_t *interactable = (interactable_t*)
    element_create_default(sizeof(interactable_t), INTERACTABLE, pos);
    sfSprite *sprite = sfSprite_create();

    if (!interactable || !sprite)
        return (NULL);
    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, 64, 64});
    sfSprite_setPosition(sprite, pos);
    interactable->hitbox = (sfIntRect) {pos.x, pos.y, 64, 64};
    interactable->sprite = sprite;
    interactable->update = &interactable_update;
    interactable->get_infos = &interactable_get_infos;
    interactable->action = action;
    my_strcpy(interactable->action_name, action_name);
    return (interactable);
}

void interactable_update(entity_t *entity, infos_t *infos, float elapsed)
{
    UNUSED(entity);
    UNUSED(infos);
    UNUSED(elapsed);
}

void interactable_get_infos(element_t *element, char *str, int size)
{
    interactable_t *interactable = (interactable_t*) element;

    if (size < 16)
        return;
    my_strcpy(str, interactable->action_name);
}

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
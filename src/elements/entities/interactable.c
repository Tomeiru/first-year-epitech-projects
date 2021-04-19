/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions for NPCs
*/

#include "my_rpg.h"
#include "graphics/texture.h"
#include "elements/entities/interactable.h"

interactable_t *interactable_create(sfVector2f pos,
sfTexture *texture, char *action)
{
    interactable_t *interactable = (interactable_t*)
    element_create_default(sizeof(interactable_t), INTERACTABLE, pos);
    sfSprite *sprite = sfSprite_create();

    if (!interactable || !sprite)
        return (NULL);
    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, 64, 64});
    sfSprite_setPosition(sprite, pos);
    interactable->sprite = sprite;
    interactable->update = &interactable_update;
    my_strcpy(interactable->action, action);
    element_set_hitbox((element_t*) particle,
    sfSprite_getGlobalBounds(sprite));
    return (interactable);
}

void interactable_update(element_t *element, infos_t *infos, float elapsed)
{

}
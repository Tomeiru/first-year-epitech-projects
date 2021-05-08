/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** dialogue
*/

#include <stdlib.h>
#include "my.h"
#include "my_rpg.h"
#include "graphics/texture.h"
#include "elements/entities/dialogue.h"
#include "scene/world_scene.h"

void dialogue_move(element_t *element, sfVector2f pos)
{
    dialogue_t *dialogue = (dialogue_t*) element;

    dialogue->pos = pos;
    dialogue->hitbox.left = pos.x;
    dialogue->hitbox.top = pos.y;
    sfSprite_setPosition(dialogue->sprite, pos);
    sfText_setPosition(dialogue->text, (sfVector2f) {pos.x + 15, pos.y + 5});
}

void dialogue_draw(element_t *element, sfRenderWindow *window)
{
    dialogue_t *dialogue = (dialogue_t*) element;

    if (!dialogue->str)
        return;
    sfRenderWindow_drawSprite(window, dialogue->sprite, 0);
    sfRenderWindow_drawText(window, dialogue->text, 0);
}

void dialogue_update(entity_t *entity, infos_t *infos, float elapsed)
{
    dialogue_t *dialogue = (dialogue_t*) entity;
    char temp;

    UNUSED(infos);
    if (!dialogue->str || dialogue->end)
        return;
    else if (dialogue->cursor == dialogue->len) {
        dialogue->end = 1;
        return;
    }
    temp = dialogue->str[dialogue->cursor];
    dialogue->str[dialogue->cursor] = '\0';
    sfText_setString(dialogue->text, dialogue->str);
    dialogue->str[dialogue->cursor] = temp;
    dialogue->cursor += (int) 2 * elapsed;
    if (dialogue->cursor > dialogue->len) {
        dialogue->cursor = dialogue->len;
        sfText_setString(dialogue->text, dialogue->str);
    }
}

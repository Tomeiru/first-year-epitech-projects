/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** dialogue.c
*/

#include <stdlib.h>
#include "my.h"
#include "my_rpg.h"
#include "graphics/texture.h"
#include "elements/entities/dialogue.h"
#include "scene/world_scene.h"

dialogue_t *dialogue_create(infos_t *infos, sfVector2f pos)
{
    dialogue_t *dialogue = (dialogue_t*)
    element_create_default(sizeof(dialogue_t), TEXT, (sfVector2f) {0, 0});

    if (!dialogue || dialogue_init(dialogue, infos, pos))
        return (NULL);
    dialogue->move = &text_move;
    dialogue->rotate = &text_rotate;
    dialogue->draw = &dialogue_draw;
    dialogue->destroy = &text_destroy;
    dialogue->update = &dialogue_update;
    dialogue->time = 0;
    dialogue->cursor = 1;
    dialogue->str = NULL;
    dialogue->len = 0;
    return (dialogue);
}

int dialogue_init(dialogue_t *dialogue, infos_t *infos, sfVector2f pos)
{
    sfSprite *sprite = sfSprite_create();
    sfText *text_sfml = sfText_create();

    if (!text_sfml || !sprite)
        return (1);
    dialogue->sprite = sprite;
    dialogue->text = text_sfml;
    sfText_setString(text_sfml, "");
    sfText_setFont(text_sfml, infos->font);
    sfText_setCharacterSize(text_sfml, 40);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(dialogue->sprite, get_texture(infos, TEXTBOX_TEXT), 0);
    text_move((element_t*) dialogue, pos);
    element_set_hitbox((element_t*) dialogue, sfText_getGlobalBounds(text_sfml));
    return (0);
}

void dialogue_update(entity_t *entity, infos_t *infos, float elapsed)
{
    dialogue_t *dialogue = (dialogue_t*) entity;
    char temp;

    UNUSED(infos);
    if (!dialogue->str)
        return;
    else if (dialogue->cursor == dialogue->len) {
        ((world_scene_t*) infos->scene)->world_pause = 0;
        dialogue->str = NULL;
        return;
    }
    temp = dialogue->str[dialogue->cursor];
    dialogue->str[dialogue->cursor] = '\0';
    sfText_setString(dialogue->text, dialogue->str);
    dialogue->str[dialogue->cursor] = temp;
    dialogue->cursor += (int) 2 * elapsed;
    if (dialogue->cursor > dialogue->len)
        dialogue->cursor = dialogue->len;
}

void dialogue_draw(element_t *element, sfRenderWindow *window)
{
    dialogue_t *dialogue = (dialogue_t*) element;

    if (!dialogue->str)
        return;
    sfRenderWindow_drawSprite(window, dialogue->sprite, 0);
    sfRenderWindow_drawText(window, dialogue->text, 0);
}

void dialogue_set_str(dialogue_t *dialogue, infos_t *infos, char *new_str)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;

    dialogue->cursor = 1;
    dialogue->str = new_str;
    dialogue->len = my_strlen(new_str);
    world_scene->world_pause = 1;
}
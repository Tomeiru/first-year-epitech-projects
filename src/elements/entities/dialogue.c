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

dialogue_t *dialogue_create(infos_t *infos, sfVector2f pos)
{
<<<<<<< HEAD
    char temp;

    if (dialogue->str == NULL)
        return;
    temp = dialogue->str[dialogue->pos]
    dialogue->str[dialogue->pos] = '\0';
    sfText_setString(dialogue->text, dialogue->str);
    sfSprite_draw()
    text_draw(dialogue, infos->window);
    dialogue->str[dialogue->pos] = temp;
    if (dialogue->pos != dialogue->len){
        dialogue->pos += (int) 2 * elapsed;
        if (dialogue.pos > dialogue->len)
            dialogue->pos = dialogue->len;
    }
}

void dialogue_set_str(dialogue_t *dialogue, char *new_str)
{
    dialogue->pos = 1;
    dialogue->str = new_str;
    dialogue->len = my_strlen(new_str);
}
=======
    dialogue_t *dialogue = (dialogue_t*)
    element_create_default(sizeof(dialogue_t), TEXT, (sfVector2f) {0, 0});
>>>>>>> 49bd2b6d92861f132bf1e729b284d8c7d099d977

    if (!dialogue || dialogue_init(dialogue, infos, pos))
        return (NULL);
    dialogue->move = &text_move;
    dialogue->rotate = &text_rotate;
    dialogue->draw = &text_draw;
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

<<<<<<< HEAD
dialogue_t *dialogue_create(sfFont *font, sfVector2f pos, int size)
{
    dialogue_t *dialogue = (dialogue_t*)
    element_create_default(sizeof(dialogue_t), TEXT, (sfVector2f) {0, 0});
    sfText *text_sfml = sfText_create();

    if (!dialogue || !text_sfml)
        return (NULL);
    sfText_setString(text_sfml, "");
    sfText_setFont(text_sfml, font);
    sfText_setCharacterSize(text_sfml, size);
    dialogue->sprite = dialogue_set_sprite(TEXTURES_PATH[10], pos);
    dialogue->text = text_sfml;
    dialogue_set_fcts(dialogue);
    dialogue->time = 0;
    dialogue->pos = 1;
    dialogue->str = NULL;
    dialogue->len = 0;
    element_set_hitbox((element_t*) dialogue, sfText_getGlobalBounds(text_sfml));
    text_move((element_t*) dialogue, pos);
    return (dialogue);
=======
void dialogue_update(entity_t *entity, infos_t *infos, float elapsed)
{
    dialogue_t *dialogue = (dialogue_t*) entity;
    char temp;

    UNUSED(infos);
    if (!dialogue->str)
        return;
    temp = dialogue->str[dialogue->cursor];
    dialogue->str[dialogue->cursor] = '\0';
    sfText_setString(dialogue->text, dialogue->str);
    dialogue->str[dialogue->cursor] = temp;
    if (dialogue->cursor != dialogue->len){
        dialogue->cursor += (int) 2 * elapsed;
        if (dialogue->cursor > dialogue->len)
            dialogue->cursor = dialogue->len;
    }
}

void dialogue_set_str(dialogue_t *dialogue, char *new_str)
{
    dialogue->cursor = 1;
    dialogue->str = new_str;
    dialogue->len = my_strlen(new_str);
>>>>>>> 49bd2b6d92861f132bf1e729b284d8c7d099d977
}
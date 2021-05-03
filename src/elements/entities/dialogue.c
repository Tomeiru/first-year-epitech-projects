/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** dialogue.c
*/

#include <stdlib.h>
#include "my.h"
#include "elements/entities/dialogue.h"
#include "graphics/texture_list.h"

void dialogue_update(dialogue_t *dialogue, infos_t *infos, float elapsed)
{
    char temp = dialogue->str[dialogue->pos];

    dialogue->str[dialogue->pos] = '\0';
    sfText_setString(dialogue->text, dialogue->str);
    text_draw(dialogue, infos->window);
    dialogue->str[dialogue->pos] = temp;
    if (dialogue->pos != dialogue->len){
        dialogue->pos += (int) 2 * elapsed;
        if (dialogue.pos > dialogue->len)
            dialogue->pos = dialogue->len;
    }
}

void dialogue_set_fcts(dialogue_t *dialogue)
{
    dialogue->move = &text_move;
    dialogue->rotate = &text_rotate;
    dialogue->draw = &text_draw;
    dialogue->destroy = &text_destroy;
    dialogue->update = &dialogue_update;
}

sfSprite *dialogue_set_sprite(char *path, sfVector2f pos)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}

dialogue_t *dialogue_create(char *text_str, sfFont *font, sfVector2f pos,
int size)
{
    dialogue_t *dialogue = (dialogue_t*)
    element_create_default(sizeof(dialogue_t), TEXT, (sfVector2f) {0, 0});
    sfText *text_sfml = sfText_create();
    sfTexture *texture = sfTexture_createFromFile("assets/textures/textbox.png", NULL);

    if (!dialogue || !text_sfml)
        return (NULL);
    sfText_setString(text_sfml, text_str);
    sfText_setFont(text_sfml, font);
    sfText_setCharacterSize(text_sfml, size);
    dialogue->sprite = dialogue_set_sprite(TEXTURES_PATH[10], pos);
    dialogue->text = text_sfml;
    dialogue_set_fcts(dialogue);
    dialogue->time = 0;
    dialogue->pos = 1;
    dialogue->str = my_strdup(text_str);
    dialogue->len = my_strlen(text_str);
    element_set_hitbox((element_t*) dialogue, sfText_getGlobalBounds(text_sfml));
    text_move((element_t*) dialogue, pos);
    return (dialogue);
}
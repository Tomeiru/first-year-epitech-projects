/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** dialogue.c
*/

#include <stdlib.h>
#include "my.h"
#include "elements/entities/dialogue.h"

void dialogue_draw(dialogue_t *dialogue, sfRenderWindow *window)
{
    char temp = dialogue->str[dialogue->pos];

    dialogue->str[dialogue->pos] = '\0';
    sfText_setString(dialogue->text, dialogue->str);
    text_draw(dialogue, window);
    dialogue->str[dialogue->pos] = temp;
    if (dialogue->pos != dialogue->len){
        dialogue.pos += 2;
        if (dialogue.pos > dialogue->len)
            dialogue->pos = dialogue->len;
    }
}

dialogue_t *dialogue_create(char *text_str, sfFont *font, sfVector2f pos,
int size)
{
    dialogue_t *dialogue = (dialogue_t*)
    element_create_default(sizeof(dialogue_t), TEXT, (sfVector2f) {0, 0});
    sfText *text_sfml = sfText_create();

    if (!dialogue || !text_sfml)
        return (NULL);
    sfText_setString(text_sfml, text_str);
    sfText_setFont(text_sfml, font);
    sfText_setCharacterSize(text_sfml, size);
    dialogue->sprite = NULL;
    dialogue->text = text_sfml;
    dialogue->move = &text_move;
    dialogue->rotate = &text_rotate;
    dialogue->draw = &text_draw;
    dialogue->destroy = &text_destroy;
    dialogue->time = 0;
    dialogue->pos = 1;
    dialogue->str = my_strdup(text_str);
    dialogue->len = my_strlen(text_str);
    element_set_hitbox((element_t*) dialogue, sfText_getGlobalBounds(text_sfml));
    text_move((element_t*) dialogue, pos);
    return (text);
}
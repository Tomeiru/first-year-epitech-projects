/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** text
*/

#include <stdlib.h>
#include "my.h"
#include "elements/entities/text.h"

text_t *text_create(char *text_str, sfFont *font, sfVector2f pos, int size)
{
    text_t *text = (text_t*)
    element_create_default(sizeof(text_t), TEXT, (sfVector2f) {0, 0});
    sfText *text_sfml = sfText_create();

    if (!text || !text_sfml)
        return (NULL);
    sfText_setString(text_sfml, text_str);
    sfText_setFont(text_sfml, font);
    sfText_setCharacterSize(text_sfml, size);
    text->sprite = NULL;
    text->text = text_sfml;
    text->move = &text_move;
    text->rotate = &text_rotate;
    text->draw = &text_draw;
    text->destroy = &text_destroy;
    text->time = 0;
    element_set_hitbox((element_t*) text, sfText_getGlobalBounds(text_sfml));
    text_move((element_t*) text, pos);
    return (text);
}

void text_move(element_t *element, sfVector2f pos)
{
    text_t *text = (text_t*) element;

    text->pos = pos;
    text->hitbox.left = pos.x;
    text->hitbox.top = pos.y;
    if (text->sprite)
        sfSprite_setPosition(text->sprite, pos);
    sfText_setPosition(text->text, pos);
}

void text_rotate(element_t *element, float rot)
{
    text_t *text = (text_t*) element;
    sfIntRect hb = text->hitbox;
    sfVector2f top_left = {0, 0};
    sfVector2f center = {hb.left + hb.width / 2, hb.top + hb.height / 2};

    text->rot = rot;
    if (text->sprite) {
        sfSprite_setOrigin(text->sprite, center);
        sfSprite_setRotation(text->sprite, rot);
        sfSprite_setOrigin(text->sprite, top_left);
    }
    sfText_setOrigin(text->text, center);
    sfText_setRotation(text->text, rot);
    sfText_setOrigin(text->text, top_left);
}

void text_draw(element_t *element, sfRenderWindow *window)
{
    text_t *text = (text_t*) element;

    if (text->sprite)
        sfRenderWindow_drawSprite(window, text->sprite, 0);
    sfRenderWindow_drawText(window, text->text, 0);
}

void text_destroy(element_t *element)
{
    text_t *text = (text_t*) element;

    if (text->sprite)
        sfSprite_destroy(text->sprite);
    sfText_destroy(text->text);
    free(text);
}
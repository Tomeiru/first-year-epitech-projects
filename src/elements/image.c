/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** image
*/

#include <stdlib.h>
#include "elements/image.h"

image_t *image_create(infos_t *infos, texture_t texture,
sfVector2f pos, sfVector2i size)
{
    element_t *element = element_create_default(sizeof(image_t), IMAGE, pos);
    image_t *image = (image_t*) element;
    sfSprite *sprite = sfSprite_create();

    if (!element || !sprite)
        return (NULL);
    sfSprite_setTexture(sprite, get_texture(infos, texture), 0);
    sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, size.x, size.y});
    sfSprite_setPosition(sprite, pos);
    image->sprite = sprite;
    image->size = size;
    image->texture_pos = (sfVector2i) {0, 0};
    return (image);
}

void image_add_texture_pos(image_t *image, int x, int y)
{
    sfVector2i size = image->size;
    sfVector2i texture_pos =
    {image->texture_pos.x + x * size.x, image->texture_pos.y + y * size.y};
    sfIntRect rect = {texture_pos.x, texture_pos.y, size.x, size.y};

    image->texture_pos = texture_pos;
    sfSprite_setTextureRect(image->sprite, rect);
}

void image_set_texture_pos(image_t *image, int x, int y)
{
    sfVector2i size = image->size;
    sfVector2i texture_pos = {size.x * x, size.y * y};
    sfIntRect rect = {texture_pos.x, texture_pos.y, size.x, size.y};

    image->texture_pos = texture_pos;
    sfSprite_setTextureRect(image->sprite, rect);
}
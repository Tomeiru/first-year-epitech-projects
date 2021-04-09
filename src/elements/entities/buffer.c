/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** buffer
*/

#include <stdlib.h>
#include <string.h>
#include "elements/entities/buffer.h"

buffer_t *buffer_create(sfVector2f pos, sfVector2u size)
{
    buffer_t *buffer = (buffer_t*)
    element_create_default(sizeof(buffer_t), BUFFER, pos);
    sfUint8 *pixels = malloc(sizeof(sfUint8) * (size.x * size.y + 1));
    sfTexture *texture = sfTexture_create(size.x, size.y);
    sfSprite *sprite = sfSprite_create();

    if (!buffer || !pixels || !texture || !sprite)
        return (NULL);
    sfSprite_setTexture(sprite, texture, 0);
    buffer->draw = &buffer_draw;
    buffer->size = size;
    buffer->pixels = pixels;
    buffer->texture = texture;
    buffer->sprite = sprite;
    buffer->edited = 0;
    buffer_clear(buffer);
    return (buffer);
}

void buffer_put_pixel(buffer_t *buffer, sfColor color, sfVector2u pos)
{
    int index = (pos.x + buffer->size.x * pos.y) * 4;

    if (index >= (buffer->size.x * buffer->size.y * 4 - 4))
        return;
    buffer->pixels[index] = color.r;
    buffer->pixels[index + 1] = color.g;
    buffer->pixels[index + 2] = color.b;
    buffer->pixels[index + 3] = color.a;
    buffer->edited = 1;
}

void buffer_clear(buffer_t *buffer)
{
    memset(buffer->pixels, 0,
    buffer->size.x * buffer->size.y * sizeof(sfUint8));
    buffer->edited = 1;
}

void buffer_draw(element_t *element, sfRenderWindow *window)
{
    buffer_t *buffer = (buffer_t*) element;

    if (buffer->edited) {
        sfTexture_updateFromPixels(buffer->texture, buffer->pixels,
        buffer->size.x, buffer->size.y, 0, 0);
        buffer->edited = 0;
    }
    sfRenderWindow_drawSprite(window, buffer->sprite, 0);
}

void buffer_destroy(element_t *element)
{
    buffer_t *buffer = (buffer_t*) element;

    sfTexture_destroy(buffer->texture);
    sfSprite_destroy(buffer->sprite);
    free(buffer->pixels);
    free(buffer);
}
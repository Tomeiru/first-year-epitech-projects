/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** meteo effects
*/

#include <math.h>
#include "my_rpg.h"
#include "elements/entities/particles/meteo.h"
#include "scene/world_scene.h"

void rain_effect(buffer_t *buffer, float time)
{
    int x_pos = 0;
    int y_pos = 0;
    int size = 0;
    int speed = 0;
    int y_offset = 0;

    for (int i = 0; i < RAIN_DROPLET; i++) {
        size = RAIN_SIZE_BASE + RAIN_SIZE_BONUS * cos(i) * cos(i);
        speed = RAIN_SPEED_BASE + RAIN_SPEED_BONUS * sin(i) * sin(i);
        y_offset = sin(i) * sin(i) * 648;
        x_pos = buffer->size.x * cos(i * i);
        y_pos = (((int) time) * speed + y_offset) % buffer->size.y;
        draw_rain_drop(buffer, x_pos, y_pos, size);
    }
}

void draw_rain_drop(buffer_t *buffer, int x, int y, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++) {
        if (y + i < buffer->size.y)
            buffer_put_pixel(buffer, RAIN_COLOR, (sfVector2u) {x, y + i});
    }
}

void snow_effect(buffer_t *buffer, float time)
{
    int x_pos = 0;
    int y_pos = 0;
    float speed = 0;
    int y_offset = 0;

    for (int i = 0; i < SNOW_DROPLET; i++) {
        speed = SNOW_SPEED_BASE + SNOW_SPEED_BONUS * sin(i) * sin(i);
        y_offset = sin(i) * sin(i) * 648;
        x_pos = buffer->size.x * cos(i * i) + cos((time + i) * 0.087) * 5 - 2;
        y_pos = ((int) (time * speed + y_offset)) % buffer->size.y;
        draw_snow(buffer, x_pos, y_pos);
    }
}

void draw_snow(buffer_t *buffer, int x, int y)
{
    for (int y_off = -1; y_off < 2; y_off++) {
        for (int x_off = -1; x_off < 2; x_off++) {
            buffer_put_pixel(buffer, SNOW_COLOR,
            (sfVector2u) {x + x_off , y + y_off});
        }
    }
}
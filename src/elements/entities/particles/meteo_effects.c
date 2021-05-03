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

void night_effect(buffer_t *buffer, infos_t *infos, float darkness)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    const sfView *view = sfRenderWindow_getView(infos->window);
    sfVector2f center = sfView_getCenter(view);
    sfVector2f top_left = {center.x - WINDOW_WIDTH / 2,
    center.y - WINDOW_HEIGHT / 2};
    sfVector2f player_pos = world_scene->player->pos;
    sfColor color = {0, 0, 0, darkness * 140};

    for (unsigned int y = 0; y < buffer->size.y; y++) {
        for (unsigned int x = 0; x < buffer->size.x; x++)
            buffer_put_pixel(buffer, color, (sfVector2u) {x, y});
    }
    night_effect_player_view(buffer, top_left, player_pos, darkness);
}

void night_effect_player_view(buffer_t *buffer,
sfVector2f top_left, sfVector2f player_pos, float darkness)
{
    sfColor light = {0, 0, 0, darkness * 80};
    sfVector2f player_screen_pos = {player_pos.x - top_left.x,
    player_pos.y - top_left.y};
    sfVector2u buffer_pos;

    if (darkness < 0.25)
        return;
    for (int y = -NIGHT_VIEW; y <= NIGHT_VIEW; y += BUFFER_SCALE) {
        for (int x = -NIGHT_VIEW; x <= NIGHT_VIEW; x += BUFFER_SCALE) {
            if (x * x + y * y > NIGHT_VIEW * NIGHT_VIEW)
                continue;
            buffer_pos = (sfVector2u) {
                (player_screen_pos.x + x) / BUFFER_SCALE,
                (player_screen_pos.y + y) / BUFFER_SCALE};
            if (buffer_pos.x >= buffer->size.x ||
            buffer_pos.y >= buffer->size.y)
                continue;
            buffer_put_pixel(buffer, light, buffer_pos);
        }
    }
}

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

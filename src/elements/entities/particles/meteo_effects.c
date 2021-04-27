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

void night_effect(buffer_t *buffer, infos_t *infos)
{
    sfColor dark = {0, 0, 0, 140};
    const sfView *view = sfRenderWindow_getView(infos->window);
    sfVector2f center = sfView_getCenter(view);
    sfVector2f top_left = {center.x - WINDOW_WIDTH / 2,
    center.y - WINDOW_HEIGHT / 2};
    sfVector2f player_pos = ((world_scene_t*) infos->scene)->player->pos;

    for (int y = 0; y < WINDOW_HEIGHT; y++) {
        for (int x = 0; x < WINDOW_WIDTH; x++)
            buffer_put_pixel(buffer, dark, (sfVector2u) {x, y});
    }
    night_effect_player_view(buffer, top_left, player_pos);
}

void night_effect_player_view(buffer_t *buffer,
sfVector2f top_left, sfVector2f player_pos)
{
    sfColor light = {0, 0, 0, 10};
    sfVector2u pos;

    for (int y = -NIGHT_VIEW; y <= NIGHT_VIEW; y++) {
        for (int x = -NIGHT_VIEW; x <= NIGHT_VIEW; x++) {
            if (x * x + y * y <= NIGHT_VIEW * NIGHT_VIEW) {
                pos = (sfVector2u) {player_pos.x - top_left.x + x,
                player_pos.y - top_left.y + y};
                if (pos.x >= WINDOW_WIDTH || pos.y >= WINDOW_HEIGHT)
                    continue;
                buffer_put_pixel(buffer, light, pos);
            }
        }
    }
}

void rain_effect(buffer_t *buffer, float time)
{
    int offset = 0;
    int x_offset = 0;
    int y_offset = 0;

    offset = ceil(time) * 10;
    x_offset = offset % (RAIN_LENGTH * 2);
    y_offset = offset % RAIN_LENGTH;
    for (int y = y_offset; y < WINDOW_HEIGHT; y += RAIN_SPACE) {
        for (int x = x_offset; x < WINDOW_WIDTH; x += RAIN_SPACE * 2)
            draw_rain_drop(buffer, x, y);
    }
}

void draw_rain_drop(buffer_t *buffer, int x, int y)
{
    for (int i = 0; i < RAIN_LENGTH; i++)
        buffer_put_pixel(buffer, RAIN_COLOR, (sfVector2u) {x + i, y + i});
}

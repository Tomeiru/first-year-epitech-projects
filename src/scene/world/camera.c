/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** camera
*/

#include <math.h>
#include "my_rpg.h"
#include "scene/world_scene.h"
#include "graphics/texture.h"

void camera_move(world_scene_t *world_scene, infos_t *infos, float elapsed)
{
    const sfView *view = sfRenderWindow_getView(infos->window);
    sfVector2f player_pos = world_scene->player->pos;
    sfVector2f center = sfView_getCenter(view);
    float dist = get_distance(center, player_pos);
    float angle = atan2(player_pos.y - center.y, player_pos.x - center.x);
    float speed = dist / 10 * elapsed;
    sfVector2f move;
    subwindow_t *subwindow;

    if (dist < 0.01)
        return;
    move = (sfVector2f) {cos(angle) * speed, sin(angle) * speed};
    camera_move_limits(&move, view, world_scene);
    sfView_move(view, move);
    for (list_t *list = world_scene->subwindows; list; list = list->next) {
        subwindow = (subwindow_t*) list->data;
        subwindow->move(subwindow, (sfVector2f)
        {subwindow->pos.x + move.x, subwindow->pos.y + move.y});
    }
    sfRenderWindow_setView(infos->window, view);
}

void camera_move_limits(sfVector2f *move, const sfView *view,
world_scene_t *world_scene)
{
    sfVector2u size = world_scene->map->map_size;
    sfVector2f pos = sfView_getCenter(view);

    if (pos.x - WINDOW_WIDTH / 2 + move->x < 0)
        move->x = -pos.x + WINDOW_WIDTH / 2;
    else if (pos.x + WINDOW_WIDTH / 2 + move->x > size.x)
        move->x = size.x - pos.x - WINDOW_WIDTH / 2;
    if (pos.y - WINDOW_HEIGHT / 2 + move->y < 0)
        move->y = -pos.y + WINDOW_HEIGHT / 2;
    else if (pos.y + WINDOW_HEIGHT / 2 + move->y > size.y)
        move->y = size.y - pos.y - WINDOW_HEIGHT / 2;
}
/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** world
*/

#include <SFML/Window/Keyboard.h>
#include "my_rpg.h"
#include "scene/world_scene.h"
#include "graphics/texture.h"

void world_load(world_scene_t *world_scene, infos_t *infos)
{
    sfSprite_setTexture(world_scene->background,
    get_texture(infos, WORLD_BACKGROUND_TEXT), 0);
}

void world_move(world_scene_t *world_scene, infos_t *infos, float elapsed)
{
    subwindow_t *subwindow;
    sfView *view = sfRenderWindow_getView(infos->window);
    sfVector2f move = {0, 0};
    float speed = 5 * elapsed;

    if (!world_scene->can_move)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyZ) ^ sfKeyboard_isKeyPressed(sfKeyS))
        move.y = sfKeyboard_isKeyPressed(sfKeyZ) ? -speed : speed;
    if (sfKeyboard_isKeyPressed(sfKeyQ) ^ sfKeyboard_isKeyPressed(sfKeyD))
        move.x = sfKeyboard_isKeyPressed(sfKeyQ) ? -speed : speed;
    sfView_move(view, move);
    for (list_t *list = world_scene->subwindows; list; list = list->next) {
        subwindow = (subwindow_t*) list->data;
        subwindow->move(subwindow, (sfVector2f)
        {subwindow->pos.x + move.x, subwindow->pos.y + move.y});
    }
    sfRenderWindow_setView(infos->window, view);
}
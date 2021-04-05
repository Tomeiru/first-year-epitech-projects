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
    sfView *view = sfRenderWindow_getView(infos->window);
    sfVector2f pos = sfView_getCenter(view);
    float speed = 5 * elapsed;

    if (!world_scene->can_move)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyZ) ^ sfKeyboard_isKeyPressed(sfKeyS))
        pos.y += sfKeyboard_isKeyPressed(sfKeyZ) ? -speed : speed;
    if (sfKeyboard_isKeyPressed(sfKeyQ) ^ sfKeyboard_isKeyPressed(sfKeyD))
        pos.x += sfKeyboard_isKeyPressed(sfKeyQ) ? -speed : speed;
    sfView_setCenter(view, pos);
    sfRenderWindow_setView(infos->window, view);
}
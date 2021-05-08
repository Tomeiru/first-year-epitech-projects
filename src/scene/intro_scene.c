/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** intro scene
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "actions.h"
#include "audio/music.h"
#include "graphics/texture.h"
#include "scene/intro_scene.h"

scene_t *intro_scene_create(infos_t *infos)
{
    scene_t *scene = scene_create_default (sizeof(intro_scene_t),
    &intro_scene_update, &intro_scene_destroy);
    intro_scene_t *intro_scene = (intro_scene_t*) scene;
    sfSprite *background = sfSprite_create();

    if (!scene || !background)
        return (NULL);
    sfSprite_setTexture(background,
    get_texture(infos, INTRO_TEXT), 0);
    sfSprite_setTextureRect(background, (sfIntRect)
    {0, 0, 1920 / 4, 1080 / 4});
    sfSprite_setScale(background, (sfVector2f) {4, 4});
    sfSprite_setPosition(background, (sfVector2f) {0, 0});
    scene->background = background;
    scene->event = &intro_scene_event;
    intro_scene->x_offest = 0;
    play_music(infos, INTRO_MUSIC);
    return (scene);
}

int intro_scene_update(scene_t *scene, infos_t *infos, float elapsed)
{
    intro_scene_t *intro_scene = (intro_scene_t*) scene;

    UNUSED(infos);
    intro_scene->x_offest += elapsed * 0.3783;
    if (intro_scene->x_offest + 1920 / 4 >= 3300)
        return (LOAD_MENU_SCENE_ACTION);
    sfSprite_setTextureRect(scene->background,
    (sfIntRect) {intro_scene->x_offest, 0, 1920 / 4, 1080 / 4});
    return (0);
}

int intro_scene_event(scene_t *scene, infos_t *infos, sfEvent *event)
{
    UNUSED(scene);
    UNUSED(infos);
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
        return (LOAD_MENU_SCENE_ACTION);
    return (0);
}

void intro_scene_destroy(scene_t *scene)
{
    sfSprite_destroy(scene->background);
    free(scene);
}
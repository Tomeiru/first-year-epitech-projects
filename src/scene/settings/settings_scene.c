/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** settings scene
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "audio/music.h"
#include "graphics/texture.h"
#include "graphics/subwindow.h"
#include "scene/settings_scene.h"
#include "elements/entities/button.h"

int settings_scene_init(scene_t *scene, infos_t *infos)
{
    subwindow_t *sound_subwindow = sound_subwindow_create(infos);
    subwindow_t *fps_subwindow = fps_subwindow_create(infos);
    subwindow_t *res_subwindow = res_subwindow_create(infos);
    button_t *validate = text_button_create(infos, "Validate",
    (sfVector2f) {856, 950}, GREEN_BUTTON);

    if (!sound_subwindow || !fps_subwindow || !res_subwindow || !validate)
        return (1);
    validate->on_click = &button_load_menu_scene;
    scene_add_element(scene, (element_t*) validate, 0);
    create_list(&(scene->subwindows), sound_subwindow);
    create_list(&(scene->subwindows), fps_subwindow);
    create_list(&(scene->subwindows), res_subwindow);
    return (0);
}

scene_t *settings_scene_create(infos_t *infos)
{
    scene_t *scene = scene_create_default(sizeof(settings_scene_t),
    &settings_scene_update, &settings_scene_destroy);
    sfSprite *background = sfSprite_create();

    if (!scene || !background || settings_scene_init(scene, infos))
        return (NULL);
    sfSprite_setTexture(background,
    get_texture(infos, SETTINGS_BACKGROUND_TEXT), 0);
    scene->background = background;
    play_music(infos, MENU_MUSIC);
    return (scene);
}

int settings_scene_update(scene_t *scene, infos_t *infos, float elapsed)
{
    entity_t *entity;
    subwindow_t *subwindow;

    update_hover(infos);
    for (list_t *list = scene->entities; list; list = list->next) {
        entity = (entity_t*) list->data;
        entity->update(entity, infos, elapsed);
    }
    for (list_t *list = scene->subwindows; list; list = list->next) {
        subwindow = (subwindow_t*) list->data;
        subwindow->update(subwindow, infos, elapsed);
    }
    return (0);
}

void settings_scene_destroy(scene_t *scene)
{
    list_t *next;

    for (list_t *list = scene->subwindows; list; list = next) {
        next = list->next;
        ((subwindow_t*) list->data)->destroy((subwindow_t*) list->data);
        free(list);
    }
    scene_destroy_all_elements(scene);
    free(scene);
}
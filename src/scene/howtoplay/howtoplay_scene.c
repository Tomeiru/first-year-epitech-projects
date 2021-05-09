/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** howtoplay scene
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "audio/music.h"
#include "scene/howtoplay_scene.h"
#include "elements/image.h"
#include "elements/entities/button.h"

static int init_scene_buttons(howtoplay_scene_t *htp_scene, infos_t *infos)
{
    button_t *prev =
    text_button_create(infos, "Previous", (sfVector2f) {200, 540}, 0);
    image_t *img = image_create(infos, HOWTOPLAY_IMG_TEXT,
    (sfVector2f) {640, 108}, (sfVector2i) {640, 864});
    button_t *next =
    text_button_create(infos, "Next", (sfVector2f) {1470, 540}, 0);
    button_t *menu =
    text_button_create(infos, "Menu", (sfVector2f) {1530, 990}, 2);

    if (!prev || !next || !img || !menu)
        return (1);
    prev->on_click = &button_htp_prev;
    next->on_click = &button_htp_next;
    menu->on_click = &button_load_menu_scene;
    scene_add_element((scene_t*) htp_scene, (element_t*) prev, 1);
    scene_add_element((scene_t*) htp_scene, (element_t*) img, 0);
    scene_add_element((scene_t*) htp_scene, (element_t*) next, 1);
    scene_add_element((scene_t*) htp_scene, (element_t*) menu, 0);
    return (0);
}

scene_t *howtoplay_scene_create(infos_t *infos)
{
    scene_t *scene = scene_create_default(sizeof(howtoplay_scene_t),
    &howtoplay_scene_update, &howtoplay_scene_destroy);
    howtoplay_scene_t *htp_scene = (howtoplay_scene_t*) scene;
    sfSprite *background = sfSprite_create();

    if (!scene || !background || init_scene_buttons(htp_scene, infos))
        return (NULL);
    sfSprite_setTexture(background,
    get_texture(infos, HOWTOPLAY_BACKGROUND_TEXT), 0);
    htp_scene->background = background;
    play_music(infos, MENU_MUSIC);
    return (scene);
}

int howtoplay_scene_update(scene_t *scene, infos_t *infos, float elapsed)
{
    entity_t *entity;

    update_hover(infos);
    for (list_t *list = scene->entities; list; list = list->next) {
        entity = (entity_t*) list->data;
        entity->update(entity, infos, elapsed);
    }
    return (0);
}

void howtoplay_scene_destroy(scene_t *scene)
{
    howtoplay_scene_t *menu_scene = (howtoplay_scene_t*) scene;

    scene_destroy_all_elements(scene);
    free(menu_scene);
}
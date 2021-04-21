/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** menu scene
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "scene/menu_scene.h"
#include "elements/entities/button.h"
#include "graphics/texture.h"

static int init_menu_scene_buttons(menu_scene_t *menu_scene, infos_t *infos)
{
    button_t *game =
    text_button_create(infos, "Jeu", (sfVector2f) {864, 500}, GREEN_BUTTON);
    button_t *settings =
    text_button_create(infos, "Parametres", (sfVector2f) {864, 600}, 0);
    button_t *howtoplay =
    text_button_create(infos, "Explications", (sfVector2f) {864, 700}, 3);
    button_t *leave =
    text_button_create(infos, "Quitter", (sfVector2f) {864, 800}, RED_BUTTON);

    if (!game || !settings || !leave)
        return (1);
    game->on_click = &button_load_world_scene;
    settings->on_click = &button_load_settings_scene;
    howtoplay->on_click = &button_load_howtoplay_scene;
    leave->on_click = &button_close_game;
    scene_add_element((scene_t*) menu_scene, (element_t*) game, 0);
    scene_add_element((scene_t*) menu_scene, (element_t*) settings, 0);
    scene_add_element((scene_t*) menu_scene, (element_t*) howtoplay, 0);
    scene_add_element((scene_t*) menu_scene, (element_t*) leave, 0);
    return (0);
}

scene_t *menu_scene_create(infos_t *infos)
{
    scene_t *scene = scene_create_default(sizeof(menu_scene_t),
    &menu_scene_update, &menu_scene_destroy);
    sfSprite *background = sfSprite_create();
    menu_scene_t *menu_scene = (menu_scene_t*) scene;

    if (!scene || !background || init_menu_scene_buttons(menu_scene, infos))
        return (NULL);
    sfSprite_setTexture(background,
    get_texture(infos, MENU_BACKGROUND_TEXT), 0);
    menu_scene->background = background;
    return (scene);
}

void menu_scene_destroy(scene_t *scene)
{
    menu_scene_t *menu_scene = (menu_scene_t*) scene;

    scene_destroy_all_elements(scene);
    free(menu_scene);
}

int menu_scene_update(scene_t *scene, infos_t *infos, float elapsed)
{
    UNUSED(scene);
    UNUSED(elapsed);
    update_hover(infos);
    return (0);
}
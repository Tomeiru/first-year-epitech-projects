/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** victory
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "audio/music.h"
#include "graphics/texture.h"
#include "scene/victory_scene.h"
#include "elements/entities/button.h"

static int init_victory_scene_buttons(victory_scene_t *victory_scene,
infos_t *infos)
{
    button_t *menu = text_button_create(infos,
    "Menu", (sfVector2f) {864, 750}, YELLOW_BUTTON);
    button_t *leave = text_button_create(infos,
    "Quit", (sfVector2f) {864, 850}, RED_BUTTON);

    if (!menu || !leave)
        return (1);
    menu->on_click = &button_load_menu_scene;
    leave->on_click = &button_close_game;
    scene_add_element((scene_t*) victory_scene, (element_t*) menu, 0);
    scene_add_element((scene_t*) victory_scene, (element_t*) leave, 0);
    return (0);
}

scene_t *victory_scene_create(infos_t *infos)
{
    scene_t *scene = scene_create_default(sizeof(victory_scene_t),
    &victory_scene_update, &victory_scene_destroy);
    sfSprite *background = sfSprite_create();
    victory_scene_t *victory_scene = (victory_scene_t*) scene;

    if (!scene || !background ||
    init_victory_scene_buttons(victory_scene, infos))
        return (NULL);
    sfSprite_setTexture(background,
    get_texture(infos, VICTORY_BACKGROUND_TEXT), 0);
    victory_scene->background = background;
    play_music(infos, VICTORY_MUSIC);
    return (scene);
}

int victory_scene_update(scene_t *scene, infos_t *infos, float elapsed)
{
    UNUSED(scene);
    UNUSED(elapsed);
    update_hover(infos);
    return (0);
}

void victory_scene_destroy(scene_t *scene)
{
    victory_scene_t *victory_scene = (victory_scene_t*) scene;

    scene_destroy_all_elements(scene);
    free(victory_scene);
}
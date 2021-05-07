/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** gameover
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "audio/music.h"
#include "graphics/texture.h"
#include "scene/gameover_scene.h"
#include "elements/entities/button.h"

static int init_gameover_scene_buttons(gameover_scene_t *gameover_scene, infos_t *infos)
{
    button_t *save = text_button_create(infos, "Continuer",
    (sfVector2f) {864, 550}, GREEN_BUTTON);
    button_t *menu = text_button_create(infos,
    "Menu", (sfVector2f) {864, 750}, YELLOW_BUTTON);
    button_t *leave = text_button_create(infos,
    "Quitter", (sfVector2f) {864, 850}, RED_BUTTON);

    if (!save || !menu || !leave)
        return (1);
    save->on_click = &button_load_world_scene_save;
    menu->on_click = &button_load_menu_scene;
    leave->on_click = &button_close_game;
    scene_add_element((scene_t*) gameover_scene, (element_t*) save, 0);
    scene_add_element((scene_t*) gameover_scene, (element_t*) menu, 0);
    scene_add_element((scene_t*) gameover_scene, (element_t*) leave, 0);
    return (0);
}

scene_t *gameover_scene_create(infos_t *infos)
{
    scene_t *scene = scene_create_default(sizeof(gameover_scene_t),
    &gameover_scene_update, &gameover_scene_destroy);
    sfSprite *background = sfSprite_create();
    gameover_scene_t *gameover_scene = (gameover_scene_t*) scene;

    if (!scene || !background ||
    init_gameover_scene_buttons(gameover_scene, infos))
        return (NULL);
    sfSprite_setTexture(background,
    get_texture(infos, GAMEOVER_BACKGROUND_TEXT), 0);
    gameover_scene->background = background;
    play_music(infos, GAMEOVER_MUSIC);
    return (scene);
}

int gameover_scene_update(scene_t *scene, infos_t *infos, float elapsed)
{
    UNUSED(scene);
    UNUSED(elapsed);
    update_hover(infos);
    return (0);
}

void gameover_scene_destroy(scene_t *scene)
{
    gameover_scene_t *gameover_scene = (gameover_scene_t*) scene;

    scene_destroy_all_elements(scene);
    free(gameover_scene);
}
/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** infos
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "sound.h"
#include "graphics/texture.h"
#include "scene/menu_scene.h"

int setup_infos(infos_t *infos, sfRenderWindow *window)
{
    infos->window = window;
    infos->settings = (settings_t) {100, 60};
    if (!(infos->textures = load_textures()) ||
    !(infos->sounds = load_sounds()) ||
    !(infos->font = sfFont_createFromFile("./assets/fonts/1st-sortie.ttf")) ||
    !(infos->music = sfMusic_createFromFile("./assets/sounds/music.ogg")) ||
    !(infos->scene = menu_scene_create(infos)))
        return (1);
    sfMusic_setLoop(infos->music, 1);
    return (0);
}

void delete_infos(infos_t *infos)
{
    destroy_textures(infos->textures);
    sfFont_destroy(infos->font);
    if (infos->scene)
        infos->scene->destroy(infos->scene);
    sfRenderWindow_destroy(infos->window);
}
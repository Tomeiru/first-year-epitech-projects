/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** infos
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "graphics/texture.h"
#include "audio/sound.h"
#include "audio/music.h"
#include "scene/intro_scene.h"

int setup_infos(infos_t *infos, sfRenderWindow *window)
{
    infos->window = window;
    infos->settings = (settings_t) {100, 60};
    if (!(infos->textures = load_textures()) ||
    !(infos->sounds = load_sounds()) ||
    !(infos->music = load_musics()) ||
    !(infos->font = sfFont_createFromFile("./assets/fonts/1st-sortie.ttf")) ||
    !(infos->scene = intro_scene_create(infos)))
        return (1);
    return (0);
}

void delete_infos(infos_t *infos)
{
    destroy_textures(infos->textures);
    destroy_sounds(infos->sounds);
    destroy_musics(infos->music);
    sfFont_destroy(infos->font);
    if (infos->scene)
        infos->scene->destroy(infos->scene);
    sfRenderWindow_destroy(infos->window);
}
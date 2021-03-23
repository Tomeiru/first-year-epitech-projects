/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** build buttons
*/

#include "my_rpg.h"
#include "sound.h"
#include "elements/entities/button.h"

int button_fps_minus(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;

    if (infos->fps > 30)
        infos->fps -= 5;
    sfRenderWindow_setFramerateLimit(infos->window, infos->fps);
    button_set_clicked(button, 1, infos);
    return (0);
}

int button_fps_plus(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;

    infos->fps += 5;
    sfRenderWindow_setFramerateLimit(infos->window, infos->fps);
    button_set_clicked(button, 1, infos);
    return (0);
}

int button_sound_minus(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;

    if (infos->sound_level > 0)
        infos->sound_level -= 5;
    sound_set_volume(infos);
    button_set_clicked(button, 1, infos);
    return (0);
}

int button_sound_plus(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;

    if (infos->sound_level < 100)
        infos->sound_level += 5;
    sound_set_volume(infos);
    button_set_clicked(button, 1, infos);
    return (0);
}

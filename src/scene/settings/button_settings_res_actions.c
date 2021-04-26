/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** build buttons
*/

#include "my_rpg.h"
#include "elements/entities/button.h"

int button_res_1920(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;
    sfRenderWindow *old = infos->window;

    if (button_type == sfMouseLeft) {
        infos->window = create_window(1920, 1080);
        sfRenderWindow_destroy(old);
        button_set_clicked(button, 1, infos);
    }
    return (0);
}

int button_res_1600(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;
    sfRenderWindow *old = infos->window;

    if (button_type == sfMouseLeft) {
        infos->window = create_window(1600, 900);
        sfRenderWindow_destroy(old);
        button_set_clicked(button, 1, infos);
    }
    return (0);
}

int button_res_1280(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;
    sfRenderWindow *old = infos->window;

    if (button_type == sfMouseLeft) {
        infos->window = create_window(1280, 720);
        sfRenderWindow_destroy(old);
        button_set_clicked(button, 1, infos);
    }
    return (0);
}
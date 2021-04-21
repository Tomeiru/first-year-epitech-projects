/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** howtoplay buttons
*/

#include "my_rpg.h"
#include "elements/image.h"
#include "elements/entities/button.h"
#include "scene/howtoplay_scene.h"

int button_htp_prev(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;
    image_t *img;

    if (button_type == sfMouseLeft) {
        for (list_t *list = infos->scene->elements; list; list = list->next) {
            if (((element_t*) list->data)->type == IMAGE) {
                img = (image_t*) list->data;
                break;
            }
        }
        if (!img)
            return (0);
        image_add_texture_pos(img, -1, 0);
        button_set_clicked(button, 1, infos);
    }
    return (0);
}

int button_htp_next(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;
    image_t *img;

    if (button_type == sfMouseLeft) {
        for (list_t *list = infos->scene->elements; list; list = list->next) {
            if (((element_t*) list->data)->type == IMAGE) {
                img = (image_t*) list->data;
                break;
            }
        }
        if (!img)
            return (0);
        image_add_texture_pos(img, 1, 0);
        button_set_clicked(button, 1, infos);
    }
    return (0);
}
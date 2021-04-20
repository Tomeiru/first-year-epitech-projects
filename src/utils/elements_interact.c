/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** interactions fcts with elements
*/

#include "my_rpg.h"
#include "elements/entities/button.h"

int on_click_interact(list_t *list, infos_t *infos,
sfVector2f pos, sfMouseButtonEvent *mouse_ev)
{
    element_t *element;

    for (; list; list = list->next) {
        element = (element_t*) list->data;
        if (element_point_hit(element, pos)) {
            if (element->on_click)
                return (element->on_click(element, infos, mouse_ev->button));
            return (0);
        }
    }
    return (-1);
}

int on_hover_interact(list_t *list, infos_t *infos, sfVector2f pos)
{
    element_t *element;
    button_t *button;
    char hover;

    infos = infos;
    for (; list; list = list->next) {
        element = (element_t*) list->data;
        hover = element_point_hit(element, pos);
        if (element->type == BUTTON) {
            button = (button_t*) element;
            if (!button->is_hover && hover)
                button_set_hover(button, 1);
            else if (button->is_hover && !hover)
                button_set_hover(button, 0);
        }
    }
    return (-1);
}
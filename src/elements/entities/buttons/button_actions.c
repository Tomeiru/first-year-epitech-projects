/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button actions
*/

#include <unistd.h>
#include "my_rpg.h"
#include "actions.h"
#include "elements/entities/button.h"

int button_resume(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;

    write(2, "button_resume: pause not implemented\n", 37);
    button_set_clicked(button, 1, infos);
    sfMusic_play(infos->music);
    return (0);
}

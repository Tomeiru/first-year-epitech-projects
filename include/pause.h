/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** pause
*/

#ifndef PAUSE_H_
#define PAUSE_H_

#include "my_list.h"
#include "elements/element.h"

typedef struct infos_s infos_t;

typedef struct pause_s {
    char pause;
    list_t *elements;
} pause_t;

pause_t *pause_create(infos_t *infos);
void set_pause(pause_t *pause, infos_t *infos);
void pause_destroy(pause_t *pause);

#endif /* !PAUSE_H_ */

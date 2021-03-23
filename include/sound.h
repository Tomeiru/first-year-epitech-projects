/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** sound
*/

#ifndef SOUND_H_
#define SOUND_H_

#include "my_list.h"

typedef enum sound_e {
    CLICK_SOUND,
} sound_t;

list_t *load_sounds(void);
void play_sound(infos_t *infos, sound_t id);
void destroy_sounds(list_t *sounds);
void sound_set_volume(infos_t *infos);

#endif /* !SOUND_H_ */

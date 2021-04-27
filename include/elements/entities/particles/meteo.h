/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** meteo
*/

#ifndef METEO_H_
#define METEO_H_

#define RAIN_LENGTH 60
#define RAIN_SPACE 90
#define RAIN_COLOR (sfColor){39,115,175,100}

#define NIGHT_VIEW 200

#include "elements/entities/buffer.h"

buffer_t *meteo_create(void);
void meteo_update(entity_t *entity, infos_t *infos, float elapsed);

void night_effect(buffer_t *meteo, infos_t *infos);
void night_effect_player_view(buffer_t *buffer,
sfVector2f top_left, sfVector2f player_pos);
void rain_effect(buffer_t *meteo, float time);
void draw_rain_drop(buffer_t *meteo, int x, int y);

#endif /* !METEO_H_ */

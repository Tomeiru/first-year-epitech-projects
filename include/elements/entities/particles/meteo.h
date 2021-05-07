/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** meteo
*/

#ifndef METEO_H_
#define METEO_H_

#define BUFFER_SCALE 4

#define RAIN_DROPLET 40
#define RAIN_COLOR (sfColor){39,115,175,100}
#define RAIN_SIZE_BASE 15
#define RAIN_SIZE_BONUS 10
#define RAIN_SPEED_BASE 7
#define RAIN_SPEED_BONUS 3

#define SNOW_COLOR sfWhite
#define SNOW_DROPLET 40
#define SNOW_SPEED_BASE 1
#define SNOW_SPEED_BONUS 0.2

#define NIGHT_VIEW 200

#include "elements/entities/buffer.h"

buffer_t *meteo_create(void);
void meteo_update(entity_t *entity, infos_t *infos, float elapsed);

void rain_effect(buffer_t *meteo, float time);
void draw_rain_drop(buffer_t *buffer, int x, int y, unsigned int size);
void snow_effect(buffer_t *buffer, float time);
void draw_snow(buffer_t *buffer, int x, int y);

void night_effect(buffer_t *meteo, infos_t *infos, float darkness);
void night_effect_player_view(buffer_t *buffer, sfVector2f top_left,
sfVector2f player_pos, float darkness);

#endif /* !METEO_H_ */

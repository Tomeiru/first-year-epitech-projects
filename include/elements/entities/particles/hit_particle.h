/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** hit particle
*/

#ifndef HIT_PARTICLE_H_
#define HIT_PARTICLE_H_

#include "elements/entities/buffer.h"

#define HIT_COLOR sfRed

typedef struct hit_particle_s {
    element_type_t type;
    sfVector2f pos;
    float rot;
    sfIntRect hitbox;
    sfSprite *sprite;
    move_element_fct_t move;
    rotate_element_fct_t rotate;
    draw_element_fct_t draw;
    on_click_fct_t on_click;
    get_infos_element_fct_t get_infos;
    destroy_element_fct_t destroy;
    update_entity_fct_t update;
    sfVector2u size;
    sfUint8 *pixels;
    sfTexture *texture;
    char edited;
    element_t *attach;
    float time;
    sfVector2f particles[6];
    sfVector2f acc[6];
} hit_particle_t;

hit_particle_t *hit_particle_create(element_t *attach);
void hit_particle_update(entity_t *entity, infos_t *infos, float elapsed);
int draw_hit_particle(hit_particle_t *hit_particle, sfVector2f particle);

#endif /* !HIT_PARTICLE_H_ */

/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** element
*/

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <SFML/Graphics.h>
#include "my_list.h"

typedef enum element_type_e {
    BACKGROUND,
    IMAGE,
    INV_SLOT,
    INV_KEYB,
    ENEMY,
    INTERACTABLE,
    PLAYER,
    PROJECTILE,
    PARTICLE,
    BAR,
    BUTTON,
    TEXT,
    BUFFER,
} element_type_t;

typedef struct infos_s infos_t;

typedef struct element_s {
    element_type_t type;
    sfVector2f pos;
    float rot;
    sfIntRect hitbox;
    sfSprite *sprite;
    void (*move)(struct element_s *element, sfVector2f pos);
    void (*rotate)(struct element_s *element, float rot);
    void (*draw)(struct element_s *element, sfRenderWindow *window);
    int (*on_click)(struct element_s *element, infos_t *infos, sfMouseButton);
    void (*get_infos)(struct element_s *element, char *str, int size);
    void (*destroy)(struct element_s *element);
} element_t;

typedef void (*move_element_fct_t)(element_t *element, sfVector2f pos);
typedef void (*rotate_element_fct_t)(element_t *element, float rot);
typedef void (*draw_element_fct_t)(element_t *element, sfRenderWindow *window);
typedef int (*on_click_fct_t)(element_t *element,
infos_t *infos, sfMouseButton);
typedef void (*get_infos_element_fct_t)(element_t *element,
char *str, int size);
typedef void (*destroy_element_fct_t)(element_t *element);

element_t *element_create_default(size_t size,
element_type_t type, sfVector2f pos);

void default_element_move(element_t *element, sfVector2f pos);
void default_element_rotate(element_t *element, float rot);
void default_element_draw(element_t *element, sfRenderWindow *window);
void default_element_destroy(element_t *element);

char element_point_hit(element_t *element, sfVector2f pos);
void element_set_hitbox(element_t *element, sfFloatRect global_bounds);

element_t *element_get_closest(infos_t *infos,
sfVector2f pos, element_type_t type);

void prior_element_collision(element_t *element,
sfVector2f *move, sfIntRect hb, infos_t *infos);
void player_prior_element_collision(element_t *element,
sfVector2f *move, sfIntRect hb, infos_t *infos);
element_t *element_collision(element_t *element,
sfIntRect hb, list_t *elements);

#endif /* !ELEMENT_H_ */

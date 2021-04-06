/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** scene
*/

#ifndef SCENE_H_
#define SCENE_H_

#include <SFML/Graphics.h>
#include "my_list.h"

typedef struct infos_s infos_t;
typedef struct element_s element_t;

typedef struct scene_s {
    sfSprite *background;
    list_t *elements;
    list_t *entities;
    list_t *subwindows;
    int (*update)(struct scene_s *scene, infos_t *infos, float elapsed);
    void (*draw)(struct scene_s *scene, infos_t *infos);
    int (*event)(struct scene_s *scene, infos_t *infos, sfEvent *event);
    void (*destroy)(struct scene_s *scene);
} scene_t;

typedef int (*update_scene_fct_t)(scene_t *scene, infos_t *, float elapsed);
typedef void (*draw_scene_fct_t)(scene_t *scene, infos_t *infos);
typedef int (*event_scene_fct_t)(struct scene_s *scene,
infos_t *infos, sfEvent *event);
typedef void (*destroy_scene_fct_t)(scene_t *scene);

scene_t *scene_create_default(size_t size,
update_scene_fct_t update, destroy_scene_fct_t destroy);
void scene_default_draw(scene_t *scene, infos_t *infos);

void scene_add_element(scene_t *scene, element_t *element, char entity);
void scene_remove_element(scene_t *scene, element_t *element, char entity);
void scene_update_elements(scene_t *scene, infos_t *infos, float elapsed);
void scene_destroy_all_elements(scene_t *scene);

int load_scene(infos_t *infos, int action);

#endif /* !SCENE_H_ */

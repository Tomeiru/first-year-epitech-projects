/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** scene elements
*/

#include "my_rpg.h"
#include "scene/scene.h"
#include "graphics/subwindow.h"
#include "elements/entities/entity.h"

void scene_add_element(scene_t *scene, element_t *element, char entity)
{
    if (scene->elements != NULL)
        my_add_in_sorted_list(&(scene->elements), element, &cmp_element_type);
    else
        create_list(&(scene->elements), element);
    if (entity) {
        if (scene->entities != NULL)
            my_add_in_sorted_list(&(scene->entities),
            element, &cmp_element_type);
        else
            create_list(&(scene->entities), element);
    }
}

void scene_remove_element(scene_t *scene, element_t *element, char entity)
{
    my_delete_node(&(scene->elements), element);
    if (entity)
        my_delete_node(&(scene->entities), element);
    element->destroy(element);
}

void scene_update_elements(scene_t *scene, infos_t *infos, float elapsed)
{
    entity_t *entity;

    for (list_t *list = scene->entities; list; list = list->next) {
        entity = (entity_t*) list->data;
        entity->update(entity, infos, elapsed);
    }
}

void scene_update_subwindows(scene_t *scene, infos_t *infos, float elapsed)
{
    subwindow_t *subwindow;

    for (list_t *list = scene->subwindows; list; list = list->next) {
        subwindow = (subwindow_t*) list->data;
        subwindow->update(subwindow, infos, elapsed);
    }
}

void scene_destroy_all_elements(scene_t *scene)
{
    list_t *tmp;
    element_t *element;

    for (list_t *list = scene->elements; list; list = tmp) {
        tmp = list->next;
        element = (element_t*) list->data;
        element->destroy(element);
    }
}
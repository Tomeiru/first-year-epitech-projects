/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** scene
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_list.h"
#include "scene/scene.h"
#include "elements/element.h"
#include "graphics/subwindow.h"

scene_t *scene_create_default(size_t size,
update_scene_fct_t update, destroy_scene_fct_t destroy)
{
    scene_t *scene = malloc(size);

    if (!scene)
        return (NULL);
    scene->background = NULL;
    scene->elements = NULL;
    scene->entities = NULL;
    scene->subwindows = NULL;
    scene->subwindows = NULL;
    scene->update = update;
    scene->draw = &scene_default_draw;
    scene->event = NULL;
    scene->destroy = destroy;
    return (scene);
}

void scene_default_draw(scene_t *scene, infos_t *infos)
{
    element_t *element;
    subwindow_t *subwindow;

    sfRenderWindow_drawSprite(infos->window, scene->background, NULL);
    for (list_t *list = scene->elements; list; list = list->next) {
        element = (element_t*) list->data;
        element->draw(element, infos->window);
    }
    for (list_t *list = scene->subwindows; list; list = list->next) {
        subwindow = (subwindow_t*) list->data;
        subwindow->draw(subwindow, infos->window);
    }
    sfRenderWindow_drawText(infos->window, infos->hover_infos->text, 0);
    sfRenderWindow_display(infos->window);
}

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
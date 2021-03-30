/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** pause
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "graphics/pause.h"
#include "graphics/texture.h"
#include "elements/entities/button.h"

static int pause_create_buttons(pause_t *pause, infos_t *infos)
{
    button_t *resume = text_button_create(infos,
    "Reprendre", (sfVector2f) {865, 350}, GREEN_BUTTON);
    button_t *menu =
    text_button_create(infos, "Menu", (sfVector2f) {865, 500}, BLUE_BUTTON);
    button_t *leave =
    text_button_create(infos, "Quitter", (sfVector2f) {865, 650}, RED_BUTTON);

    if (!resume || !menu || !leave)
        return (1);
    resume->on_click = &button_resume;
    menu->on_click = &button_load_menu_scene;
    leave->on_click = &button_close_game;
    create_list(&(pause->elements), leave);
    create_list(&(pause->elements), menu);
    create_list(&(pause->elements), resume);
    return (0);
}

pause_t *pause_create(infos_t *infos)
{
    pause_t *pause = malloc(sizeof(pause_t));
    element_t *background = element_create_default(sizeof(element_t),
    BACKGROUND, (sfVector2f) {0, 0});
    sfSprite *background_sprite = sfSprite_create();

    if (!background || !background_sprite)
        return (NULL);
    sfSprite_setTexture(background_sprite,
    get_texture(infos, PAUSE_BACKGROUND_TEXT), 0);
    background->sprite = background_sprite;
    pause->elements = NULL;
    if (pause_create_buttons(pause, infos))
        return (NULL);
    create_list(&(pause->elements), background);
    return (pause);
}

void set_pause(pause_t *pause, infos_t *infos)
{
    element_t *element;

    pause->pause = 1;
    sfMusic_pause(infos->music);
    for (list_t *list = pause->elements; list; list = list->next) {
        element = (element_t*) list->data;
        if (element->type == BUTTON)
            button_set_clicked((button_t*) element, 0, infos);
    }
}

void pause_destroy(pause_t *pause)
{
    list_t *next;
    element_t *element;

    for (list_t *list = pause->elements; list; list = next) {
        next = list->next;
        element = (element_t*) list->data;
        element->destroy(element);
        free(list);
    }
    free(pause);
}
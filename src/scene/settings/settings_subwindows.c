/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** settings subwindows
*/

#include "my_rpg.h"
#include "graphics/subwindow.h"
#include "elements/entities/button.h"

subwindow_t *sound_subwindow_create(infos_t *infos)
{
    subwindow_t *subwindow = subwindow_create(infos,
    (sfVector2f) {620, 300}, SETTINGS_SUBWINDOW_TEXT);
    button_t *minus = text_button_create(infos, "-",
    (sfVector2f) {36, 50}, RED_BUTTON);
    text_t *text = text_create("SON", infos->font,
    (sfVector2f) {246, 50}, 30);
    button_t *plus = text_button_create(infos, "+",
    (sfVector2f) {436, 50}, GREEN_BUTTON);

    if (!subwindow || !minus || !text || !plus)
        return (NULL);
    minus->on_click = &button_sound_minus;
    text->update = &text_sound_update;
    plus->on_click = &button_sound_plus;
    subwindow_add_element(subwindow, (element_t*) minus, 1);
    subwindow_add_element(subwindow, (element_t*) text, 1);
    subwindow_add_element(subwindow, (element_t*) plus, 1);
    return (subwindow);
}

subwindow_t *fps_subwindow_create(infos_t *infos)
{
    subwindow_t *subwindow = subwindow_create(infos,
    (sfVector2f) {620, 500}, SETTINGS_SUBWINDOW_TEXT);
    button_t *minus = text_button_create(infos, "-",
    (sfVector2f) {36, 50}, RED_BUTTON);
    text_t *text = text_create("FPS", infos->font,
    (sfVector2f) {246, 50}, 30);
    button_t *plus = text_button_create(infos, "+",
    (sfVector2f) {436, 50}, GREEN_BUTTON);

    if (!subwindow || !minus || !text || !plus)
        return (NULL);
    minus->on_click = &button_fps_minus;
    text->update = &text_fps_update;
    plus->on_click = &button_fps_plus;
    subwindow_add_element(subwindow, (element_t*) minus, 1);
    subwindow_add_element(subwindow, (element_t*) text, 1);
    subwindow_add_element(subwindow, (element_t*) plus, 1);
    return (subwindow);
}

subwindow_t *res_subwindow_create(infos_t *infos)
{
    subwindow_t *subwindow = subwindow_create(infos,
    (sfVector2f) {620, 700}, SETTINGS_SUBWINDOW_TEXT);
    button_t *res1280 = text_button_create(infos, "1280x720",
    (sfVector2f) {36, 50}, BLUE_BUTTON);
    button_t *res1600 = text_button_create(infos, "1600x900",
    (sfVector2f) {236, 50}, BLUE_BUTTON);
    button_t *res1920 = text_button_create(infos, "1920x1080",
    (sfVector2f) {436, 50}, BLUE_BUTTON);

    if (!subwindow || !res1280 || !res1600 || !res1920)
        return (NULL);
    res1280->on_click = &button_res_1280;
    res1600->on_click = &button_res_1600;
    res1920->on_click = &button_res_1920;
    subwindow_add_element(subwindow, (element_t*) res1280, 1);
    subwindow_add_element(subwindow, (element_t*) res1600, 1);
    subwindow_add_element(subwindow, (element_t*) res1920, 1);
    return (subwindow);
}
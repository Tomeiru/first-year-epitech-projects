/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** inventory
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "inventory.h"
#include "scene/world_scene.h"

void inventory_draw(subwindow_t *subwindow, sfRenderWindow *window)
{
    element_t *element;
    slot_button_t *slots;
    list_t *list = subwindow->elements;

    if (subwindow->background)
        sfRenderWindow_drawSprite(window, subwindow->background, NULL);
    for ( ; list->next; list = list->next) {
        slots = (slot_button_t*) list->data;
        sfRenderWindow_drawSprite(window, slots->sprite, NULL);
    }
    element = (element_t*) list->data;
    element->draw(element, window);
    list = subwindow->elements;
    for ( ; list->next; list = list->next) {
        slots = (slot_button_t*) list->data;
        sfRenderWindow_drawSprite(window, slots->icon, NULL);
    }
}

inventory_t *inventory_create(infos_t *infos)
{
    inventory_t *inventory = (inventory_t*) subwindow_create(
    sizeof(inventory_t), infos, (sfVector2f) {1921, 200}, INVENTORY_TEXT);

    inventory->exp_bar = bar_create(infos, (sfIntRect) {80, 280, 560, 80}, 100);
    bar_set_color(inventory->exp_bar, 1);
    bar_set_value(inventory->exp_bar, 0);
    subwindow_add_element((subwindow_t*) inventory, (element_t*) inventory->exp_bar, 1);
    if (!inventory || inventory_create_slots(inventory, infos))
        return (NULL);
    add_item_to_inventory(inventory, 1);
    add_item_to_inventory(inventory, 2);
    inventory->slot_ptr = NULL;
    inventory->update = &inventory_update;
    inventory->draw = &inventory_draw;
    inventory->show = 0;
    inventory->anim = 0;
    return (inventory);
}

void inventory_update(subwindow_t *subwindow, infos_t *infos, float elapsed)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    inventory_t *inventory = (inventory_t*) subwindow;
    const sfView *view = sfRenderWindow_getView(infos->window);
    sfVector2f pos =
    sfRenderWindow_mapPixelToCoords(infos->window, 
    sfMouse_getPosition((sfWindow *)infos->window),
    sfRenderWindow_getView(infos->window));

    pos.x -= 16;
    pos.y -= 16;
    if (world_scene->inventory->slot_ptr)
        sfSprite_setPosition(world_scene->inventory->slot_ptr->icon, pos);
    if (inventory->show && inventory->anim)
        inventory_anim_move(inventory, view, 500, elapsed);
    else if (!inventory->show && inventory->anim) {
        inventory_anim_move(inventory, view, 1921, elapsed);
        if (!inventory->anim)
            world_scene->player->can_move = 1;
    }
}

void inventory_anim_move(inventory_t *inventory,
const sfView *view, int target, float elapsed)
{
    int cam_left_pos = sfView_getCenter(view).x - sfView_getSize(view).x / 2;
    int y_pos = sfView_getCenter(view).y - 150;
    float speed = INVENTORY_SPEED * elapsed;

    if (abs((int) (inventory->pos.x - cam_left_pos - target)) <= speed) {
        inventory->move((subwindow_t*) inventory,
        (sfVector2f) {cam_left_pos + target, y_pos});
        inventory->anim = 0;
    } else {
        if (inventory->pos.x < cam_left_pos + target)
            speed = -speed;
        inventory->move((subwindow_t*) inventory, (sfVector2f)
        {inventory->pos.x - speed, y_pos});
    }
}

void inventory_show(inventory_t *inventory)
{
    if (inventory->anim)
        return;
    inventory->show = !inventory->show;
    inventory->anim = 1;
    inventory->slot_ptr = NULL;
}
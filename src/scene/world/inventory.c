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

inventory_t *inventory_create(infos_t *infos)
{
    inventory_t *inventory = (inventory_t*) subwindow_create(
    sizeof(inventory_t), infos, (sfVector2f) {1921, 200}, INVENTORY_TEXT);

    if (!inventory)
        return (NULL);
    inventory->update = &inventory_update;
    inventory->show = 0;
    inventory->anim = 0;
    return (inventory);
}

void inventory_update(subwindow_t *subwindow, infos_t *infos, float elapsed)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    inventory_t *inventory = (inventory_t*) subwindow;
    sfView *view = sfRenderWindow_getView(infos->window);

    if (inventory->show && inventory->anim)
        inventory_anim_move(inventory, view, 500, elapsed);
    else if (!inventory->show && inventory->anim) {
        inventory_anim_move(inventory, view, 1921, elapsed);
        if (!inventory->anim)
            world_scene->can_move = 1;
    }
}

void inventory_anim_move(inventory_t *inventory,
sfView *view, int target, float elapsed)
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
}
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

int inventory_init(inventory_t *inv, infos_t *infos)
{
    sfSprite *sprite;
    element_t *element;

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        element = element_create_default(sizeof(element_t), INV_SLOT, (sfVector2f) {, });
        sprite = sfSprite_create();
        if (!element || !sprite)
            return (1);
        sfSprite_setTexture(sprite, get_texture(infos, PLAYER_TEXT), 0);
        element->sprite = sprite;
        subwindow_add_element((subwindow_t*) inv, element, 0);
    }
    return (0);
}

inventory_t *inventory_create(infos_t *infos)
{
    inventory_t *inventory = (inventory_t*) subwindow_create(
    sizeof(inventory_t), infos, (sfVector2f) {1921, 200}, INVENTORY_TEXT);

    if (!inventory || inventory_init(inventory, infos))
        return (NULL);
    inventory->update = &inventory_update;
    inventory->show = 0;
    inventory->anim = 0;
    for (int i = 0; i < INVENTORY_SIZE; i++)
        inventory->items[i] = EMPTY;
    return (inventory);
}

void inventory_update(subwindow_t *subwindow, infos_t *infos, float elapsed)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    inventory_t *inventory = (inventory_t*) subwindow;
    const sfView *view = sfRenderWindow_getView(infos->window);

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
}
/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** world scene fcts
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "actions.h"
#include "rpgsh/rpgsh.h"
#include "elements/entities/interactable.h"
#include "scene/world_scene.h"

int world_scene_post_init_common(world_scene_t *world_scene, infos_t *infos)
{
    player_t *player = player_create(infos);
    pause_t *pause = pause_create(infos);
    inventory_t *inventory = inventory_create(infos);
    hud_t *hud = hud_create(infos);

    if (!pause || !player || !inventory || !hud)
        return (1);
    world_scene->world_pause = 0;
    world_scene->player = player;
    world_scene->pause = pause;
    world_scene->inventory = inventory;
    world_scene->hud = hud;
    world_scene->cam_target = (element_t*) player;
    scene_add_element((scene_t*) world_scene, (element_t*) player, 1);
    create_list(&(world_scene->subwindows), pause);
    create_list(&(world_scene->subwindows), inventory);
    create_list(&(world_scene->subwindows), hud);
    return (0);
}

int world_scene_post_init_new(scene_t *scene, infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) scene;

    if (world_scene_post_init_common(world_scene, infos)
    || world_load(world_scene, 0, 0, infos))
        return (1);
    return (0);
}

int world_scene_post_init_save(scene_t *scene, infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) scene;

    if (world_scene_post_init_common(world_scene, infos)
    || world_load_save(world_scene, infos))
        return (1);
    return (0);
}

int world_scene_event(scene_t *scene, infos_t *infos, sfEvent *event)
{
    world_scene_t *world_scene = (world_scene_t*) scene;

    if (event->type == sfEvtKeyPressed)
        world_scene_keyboard_event(world_scene, event->key.code, infos);
    else if (event->type == sfEvtMouseButtonPressed) {
        if (event->mouseButton.button == sfMouseLeft) {
            if (world_scene->hud->dialogue->end) {
                    world_scene->hud->dialogue->end = 0;
                    world_scene->hud->dialogue->str = NULL;
                    world_scene->world_pause = 0;
            } else if (!world_scene->inventory->show
            && !world_scene->pause->pause)
                item_action(world_scene->inventory->slots[0]->item, infos);
        } else if (event->mouseButton.button == sfMouseRight)
            item_action(world_scene->inventory->slots[1]->item, infos);
    }
    return (0);
}

void world_scene_keyboard_event(world_scene_t *world_scene,
sfKeyCode code, infos_t *infos)
{
    switch (code) {
        case sfKeyTab:
            world_scene->player->can_move = 0;
            inventory_show(world_scene->inventory, infos);
            return;
        case sfKeyEscape:
            pause_set_pause(world_scene->pause, infos);
            return;
        case sfKeyE:
            interactable_execute_closest(infos, world_scene->player);
            return;
        default:
            return;
    }
}
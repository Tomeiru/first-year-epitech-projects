/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** world scene
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "actions.h"
#include "rpgsh/rpgsh.h"
#include "elements/entities/interactable.h"
#include "scene/world_scene.h"
#include "elements/entities/enemy.h"

scene_t *world_scene_create(infos_t *infos)
{
    scene_t *scene = scene_create_default(sizeof(world_scene_t),
    &world_scene_update, &world_scene_destroy);
    sfSprite *background = sfSprite_create();
    world_scene_t *world_scene = (world_scene_t*) scene;

    UNUSED(infos);
    if (!scene || !background)
        return (NULL);
    world_scene->background = background;
    world_scene->post_init = &world_scene_post_init;
    world_scene->event = &world_scene_event;
    world_scene->map = NULL;
    world_scene->time = 0;
    return (scene);
}

void world_scene_post_init(scene_t *scene, infos_t *infos)
{
    world_scene_t *world_scene = (world_scene_t*) scene;
    player_t *player = player_create(infos);
    pause_t *pause = pause_create(infos);
    inventory_t *inventory = inventory_create(infos);
    hud_t *hud = hud_create(infos);
    enemy_t *enemy = enemy_create(sizeof(enemy_t), infos, (sfVector2f){600, 500});

    if (!pause || !player || !inventory || !hud)
        return;
    world_scene->world_pause = 0;
    world_scene->player = player;
    world_scene->pause = pause;
    world_scene->inventory = inventory;
    world_scene->hud = hud;
    world_scene->cam_target = (element_t*) player;
    enemy->update = enemy_vertical_update;
    enemy->attack = enemy_ranged_attack;
    scene_add_element(scene, (element_t*)enemy, 1);
    scene_add_element(scene, (element_t*) player, 1);
    create_list(&(scene->subwindows), pause);
    create_list(&(scene->subwindows), inventory);
    create_list(&(scene->subwindows), hud);
    world_load_save(world_scene, infos);
}

int world_scene_update(scene_t *scene, infos_t *infos, float elapsed)
{
    world_scene_t *world_scene = (world_scene_t*) scene;

    update_hover(infos);
    if (check_world_load(world_scene, infos))
        return (QUIT_GAME_ACTION);
    world_scene->time += elapsed;
    if (!world_scene->world_pause && !world_scene->pause->pause)
        scene_update_elements(scene, infos, elapsed);
    camera_move(world_scene, infos, elapsed);
    scene_update_subwindows(scene, infos, elapsed);
    interactable_show_closest(infos, world_scene->hud, world_scene->player);
    return (0);
}

int world_scene_event(scene_t *scene, infos_t *infos, sfEvent *event)
{
    world_scene_t *world_scene = (world_scene_t*) scene;

    if (event->type == sfEvtKeyPressed) {
        switch (event->key.code) {
            case sfKeyTab:
                world_scene->player->can_move = 0;
                inventory_show(world_scene->inventory);
                return (0);
            case sfKeyEscape:
                pause_set_pause(world_scene->pause, infos);
                return (0);
            case sfKeyE:
                interactable_execute_closest(infos, world_scene->player);
                return (0);
            case sfKeyA:
                player_damage(world_scene->player, 1, infos);
                return (0);
            default:
                return (0);
        }
    }
    return (0);
}

void world_scene_destroy(scene_t *scene)
{
    world_scene_t *world_scene = (world_scene_t*) scene;
    list_t *next;

    map_destroy(world_scene->map, world_scene);
    for (list_t *list = scene->subwindows; list; list = next) {
        next = list->next;
        ((subwindow_t*) list->data)->destroy((subwindow_t*) list->data);
        free(list);
    }
    scene_destroy_all_elements(scene);
    free(world_scene);
}

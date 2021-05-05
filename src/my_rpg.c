/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** game managment
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "actions.h"
#include "graphics/texture.h"
#include "graphics/subwindow.h"

static int execute_action(infos_t *infos, int action)
{
    switch (action) {
        case 0:
            return (0);
        case QUIT_GAME_ACTION:
            sfRenderWindow_close(infos->window);
            return (0);
        default:
            infos->scene->destroy(infos->scene);
            return (load_scene(infos, action));
    }
}

static int run_game(infos_t *infos)
{
    sfClock *clock = sfClock_create();
    float elapsed = 0;
    int update_action = 0;
    int user_action = 0;

    if (!clock)
        return (84);
    while (sfRenderWindow_isOpen(infos->window)) {
        if (execute_action(infos, update_action ? update_action : user_action))
            return (84);
        user_action = poll_events(infos);
        elapsed = sfClock_restart(clock).microseconds / FPS;
        update_action = infos->scene->update(infos->scene, infos, elapsed);
        infos->scene->draw(infos->scene, infos);
    }
    sfClock_destroy(clock);
    return (0);
}

int my_rpg(sfRenderWindow *window)
{
    infos_t infos = {0};
    int ret = 0;

    if (setup_infos(&infos, window))
        return (84);
    sfTexture_setRepeated(get_texture(&infos, HOWTOPLAY_IMG_TEXT), 1);
    ret = run_game(&infos);
    if (!ret)
        delete_infos(&infos);
    return (ret);
}
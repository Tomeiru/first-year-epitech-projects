/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button actions
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_rpg.h"
#include "actions.h"
#include "elements/entities/button.h"
#include "scene/world_scene.h"

int button_pause_resume(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    world_scene_t *world_scene = (world_scene_t*) infos->scene;
    button_t *button = (button_t*) element;

    if (button_type == sfMouseLeft) {
        pause_set_pause(world_scene->pause, infos);
        button_set_clicked(button, 1, infos);
        sfMusic_play(infos->music);
    }
    return (0);
}

void pause_set_pause(pause_t *pause, infos_t *infos)
{
    pause->pause = !pause->pause;
    pause->anim = 1;
    sfMusic_pause(infos->music);
}

void pause_anim_move(pause_t *pause,
const sfView *view, int target, float elapsed)
{
    int cam_up_pos = sfView_getCenter(view).y - sfView_getSize(view).y / 2;
    int x_pos = sfView_getCenter(view).x - 960;
    float speed = PAUSE_SPEED * elapsed;

    if (abs((int) (pause->pos.y - cam_up_pos - target)) <= speed) {
        pause->move((subwindow_t*) pause,
        (sfVector2f) {x_pos, cam_up_pos + target});
        pause->anim = 0;
    } else {
        if (pause->pos.y < cam_up_pos + target)
            speed = -speed;
        pause->move((subwindow_t*) pause, (sfVector2f)
        {x_pos, pause->pos.y - speed});
    }
}
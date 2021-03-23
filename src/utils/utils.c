/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** utils
*/

#include <stdlib.h>
#include <math.h>
#include "my_rpg.h"
#include "scene/subwindow.h"

float get_distance(sfVector2f pos1, sfVector2f pos2)
{
    float x = pos2.x - pos1.x;
    float y = pos2.y - pos1.y;

    return (sqrt(x * x + y * y));
}

int cmp_element_type(void *data1, void *data2)
{
    element_t *elem1 = (element_t*) data1;
    element_t *elem2 = (element_t*) data2;

    return (elem1->type - elem2->type);
}

void int_to_str(int value, char *buff, int buff_len)
{
    int pos = 0;
    char c;

    if (value == 0)
        *buff = '0';
    while (value > 0 && pos < buff_len) {
        c = value % 10 + '0';
        for (int i = pos; i >= 0; i--)
            buff[i + 1] = buff[i];
        buff[0] = c;
        pos++;
        value /= 10;
    }
}

int cmp_lb_entries(void *data1, void *data2)
{
    char *str1 = (char*) data1 + 18;
    char *str2 = (char*) data2 + 18;
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);

    if (len1 != len2)
        return (len2 - len1);
    for (; *str1; str1 += 1, str2 += 1) {
        if (*str1 != *str2)
            return (*str2 - *str1);
    }
    return (0);
}

void update_hover(infos_t *infos)
{
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(infos->window,
    sfMouse_getPositionRenderWindow(infos->window),
    sfRenderWindow_getView(infos->window));
    scene_t *scene = infos->scene;
    int ret;

    sfText_setString(infos->hover_infos->text, "");
    for (list_t *list = scene->subwindows; list; list = list->next) {
        ret = on_hover_interact(((subwindow_t*)
        list->data)->elements, infos, pos);
        if (ret > -1)
            return;
    }
    on_hover_interact(infos->scene->elements, infos, pos);
}
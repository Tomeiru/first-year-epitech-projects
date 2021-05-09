/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** text update
*/

#include "my.h"
#include "my_rpg.h"
#include "elements/entities/text.h"

void text_fps_update(entity_t *entity, infos_t *infos, float elapsed)
{
    text_t *text = (text_t*) entity;
    char str[9] = {0};

    UNUSED(elapsed);
    my_strcpy(str, "FPS: ");
    int_to_str(infos->settings.fps, str + 5, 4);
    sfText_setString(text->text, str);
}

void text_sound_update(entity_t *entity, infos_t *infos, float elapsed)
{
    text_t *text = (text_t*) entity;
    char str[11] = {0};

    UNUSED(elapsed);
    my_strcpy(str, "Volume: ");
    int_to_str(infos->settings.sound_level, str + 8, 3);
    sfText_setString(text->text, str);
}
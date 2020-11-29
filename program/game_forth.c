/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-mathieu.brujan
** File description:
** game_forth
*/

#include "my_hunter.h"

sfSprite *filepath_to_sprite(char *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

sfSound *filepath_to_sound(char *filepath)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(filepath);

    sfSound_setBuffer(sound, buffer);
    return (sound);
}

int if_conditions(sfEvent event, struct game_struct *game_man)
{
    if (game_man->game_stats->phase == 0 &&
    event.type == sfEvtMouseButtonReleased &&
    event.mouseButton.button == sfMouseLeft)
        return (1);
    if (game_man->game_stats->phase == 0 &&
    event.type == sfEvtMouseButtonReleased &&
    event.mouseButton.button == sfMouseRight)
        return (2);
    if ((game_man->game_stats->phase == 1
    || game_man->game_stats->phase == 2) &&
    event.type == sfEvtMouseButtonReleased &&
    event.mouseButton.button == sfMouseLeft)
        return (3);
    return (0);
}

void shot(struct game_struct *game_man, sfRenderWindow *window)
{
    sfVector2f actual_pos;
    sfVector2f sprite_pos = sfSprite_getPosition(game_man->game_birds->sprite);

    sfSound_play(game_man->game_gui->gun_shot);
    actual_pos.x = sfMouse_getPositionRenderWindow(window).x;
    actual_pos.y = sfMouse_getPositionRenderWindow(window).y;
    if ((actual_pos.x > sprite_pos.x && actual_pos.x < sprite_pos.x + 136) &&
    (actual_pos.y > sprite_pos.y && actual_pos.y < sprite_pos.y + 136))
        touched(game_man);
    else
        missed(game_man);
}
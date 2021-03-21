/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** create_mic
*/

#include "../include/my_defender.h"

sfRenderWindow *create_window(int width, int height, char *window_name,
    sfView *view)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, window_name, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setView(window, view);
    return (window);
}

sfView *create_view(float width, float height)
{
    sfFloatRect view_rect = create_float_rect(0, 0, width, height);
    sfView *view = sfView_createFromRect(view_rect);

    sfView_setCenter(view, create_float_vector(width/2, height/2));
    return (view);
}

sfSound *filepath_to_sound(char *filepath)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(filepath);

    sfSound_setBuffer(sound, buffer);
    return (sound);
}

sfSprite *filepath_to_sprite(char *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}
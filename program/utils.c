/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-mathieu.brujan
** File description:
** utils
*/

#include "my_runner.h"


char *print_u(unsigned long long nb)
{
    int len = det_len_unsigned_dec(nb);
    char *number = malloc(sizeof(char) * len);
    int i = 0;

    if (nb == 0)
        return (my_strdup("0"));
    for ( ; nb != 0; nb /= 10) {
        number[i++] = nb % 10 + 48;
    }
    number[i] = '\0';
    my_revstr(number);
    return (number);
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
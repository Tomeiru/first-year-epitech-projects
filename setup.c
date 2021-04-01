/*
** EPITECH PROJECT, 2021
** duo_stumper3
** File description:
** setup
*/

#include "stumper.h"

void create_array(info_t *info)
{
    char **array = malloc(sizeof(char *) * 6);

    if (array == NULL)
        exit(84);
    for (int i = 0; i < 5; i++) {
        array[i] = malloc(sizeof(char) * info->width + 1);
        if (array[i] == NULL)
            exit(84);
        for (int j = 0; j < info->width; j++)
            array[i][j] = ' ';
        array[i][info->width] = '\0';
    }
    array[5] = NULL;
    info->array = array;
}

void init_struct(info_t *info)
{
    info->width = strlen(info->numbers) * 6;
    create_array(info);
}

/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include <unistd.h>
#include "rush.h"

int error(int *res)
{
    int i = 0;

    for (i = 0; res[i] == 0; i++);
    if (i == 5)
        return (84);
    return (0);
}
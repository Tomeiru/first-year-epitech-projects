/*
** EPITECH PROJECT, 2021
** need4stek
** File description:
** timestamp
*/

#include <stdlib.h>
#include "need4stek.h"

void set_timestamp_from_str(timestamp_t *timestamp, char *str)
{
    if (*str == '[')
        str += 1;
    timestamp->seconds = atol(str);
    for (; *str && *str != ' ' && *str != ','; str++);
    if (!*str)
        return;
    timestamp->nanoseconds = atol(str);
}
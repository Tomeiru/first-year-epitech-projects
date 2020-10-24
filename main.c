/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <unistd.h>
#include "rush.h"

int main(void)
{
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len = read(0, buff + offset, BUFF_SIZE - offset);

    while (len > 0) {
        offset = offset + len;
        len = read(0, buff + offset, BUFF_SIZE - offset);
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    return (rush(buff, 0));
}
/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_coding_byte
*/

#include "asm.h"

static unsigned char get_increment(char c)
{
    if (c == 'r')
        return (0b1);
    if (c == '%')
        return (0b10);
    return (0b11);
}

unsigned char get_coding_byte(char **args)
{
    unsigned char coding_byte = 0;
    unsigned char increment = 0;
    unsigned char multiply = 0b1000000;

    for (int i = 0; args[i]; i++) {
        increment = get_increment(args[i][0]);
        coding_byte += increment * multiply;
        multiply /= 0b100;
    }return (coding_byte);
}
/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_magic_number
*/

#include "asm.h"

void write_magic_number(int cor_file)
{
    unsigned char magic_number[4];

    magic_number[0] = 0;
    magic_number[1] = 0xea;
    magic_number[2] = 0x83;
    magic_number[3] = 0xf3;
    write(cor_file, magic_number, 4);
}

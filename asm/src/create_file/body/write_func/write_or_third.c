/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_and_third
*/

#include "asm.h"

void write_or_eleven(int cor_file, unsigned char coding_byte,
char **args)
{
    unsigned char or_buffer[11] = "00000000000";
    unsigned int or_value_fst = get_direct_value(args[0]);
    unsigned int or_value_sec = get_direct_value(args[1]);

    or_buffer[0] = 0x07;
    or_buffer[1] = coding_byte;
    for (int i = 5; i != 1; i--) {
        if (or_value_fst == 0) {
            or_buffer[i] = 0;
            continue;
        }or_buffer[i] = or_value_fst % 0x100;
        or_value_fst /= 0x100;
    }for (int i = 9; i != 5; i--) {
        if (or_value_sec == 0) {
            or_buffer[i] = 0;
            continue;
        }or_buffer[i] = or_value_sec % 0x100;
        or_value_sec /= 0x100;
    }or_buffer[10] = (unsigned char)my_getnbr(++args[2]);
    write(cor_file, or_buffer, 11);
}
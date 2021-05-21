/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_and_third
*/

#include "asm.h"

void write_and_eleven(int cor_file, unsigned char coding_byte,
char **args)
{
    unsigned char and_buffer[11] = "00000000000";
    unsigned int and_value_fst = get_direct_value(args[0]);
    unsigned int and_value_sec = get_direct_value(args[1]);

    and_buffer[0] = 0x06;
    and_buffer[1] = coding_byte;
    for (int i = 5; i != 1; i--) {
        if (and_value_fst == 0) {
            and_buffer[i] = 0;
            continue;
        }and_buffer[i] = and_value_fst % 0x100;
        and_value_fst /= 0x100;
    }for (int i = 9; i != 5; i--) {
        if (and_value_sec == 0) {
            and_buffer[i] = 0;
            continue;
        }and_buffer[i] = and_value_sec % 0x100;
        and_value_sec /= 0x100;
    }and_buffer[10] = (unsigned char)my_getnbr(++args[2]);
    write(cor_file, and_buffer, 11);
}
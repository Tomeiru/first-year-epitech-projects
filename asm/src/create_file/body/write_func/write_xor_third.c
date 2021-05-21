/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Wxorkspace)
** File description:
** write_and_third
*/

#include "asm.h"

void write_xor_eleven(int cor_file, unsigned char coding_byte,
char **args)
{
    unsigned char xor_buffer[11] = "00000000000";
    unsigned int xor_value_fst = get_direct_value(args[0]);
    unsigned int xor_value_sec = get_direct_value(args[1]);

    xor_buffer[0] = 0x08;
    xor_buffer[1] = coding_byte;
    for (int i = 5; i != 1; i--) {
        if (xor_value_fst == 0) {
            xor_buffer[i] = 0;
            continue;
        }xor_buffer[i] = xor_value_fst % 0x100;
        xor_value_fst /= 0x100;
    }for (int i = 9; i != 5; i--) {
        if (xor_value_sec == 0) {
            xor_buffer[i] = 0;
            continue;
        }xor_buffer[i] = xor_value_sec % 0x100;
        xor_value_sec /= 0x100;
    }xor_buffer[10] = (unsigned char)my_getnbr(++args[2]);
    write(cor_file, xor_buffer, 11);
}
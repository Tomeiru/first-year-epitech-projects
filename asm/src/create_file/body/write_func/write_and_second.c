/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_and_second
*/

#include "asm.h"

static void write_and_eight_direct_first(int cor_file,
char **args, unsigned char *and_buffer)
{
    unsigned int and_value = get_direct_value(args[0]);

    for (int i = 5; i != 1; i--) {
        if (and_value == 0) {
            and_buffer[i] = 0;
            continue;
        }and_buffer[i] = and_value % 0x100;
        and_value /= 0x100;
    }and_buffer[6] = (unsigned char)my_getnbr(++args[1]);
    write(cor_file, and_buffer, 8);
}

void write_and_eight(int cor_file, unsigned char coding_byte,
char **args)
{
    unsigned char and_buffer[8] = "00000000";
    unsigned int and_value;

    and_buffer[0] = 0x06;
    and_buffer[1] = coding_byte;
    and_buffer[7] = (unsigned char)my_getnbr(++args[2]);
    if (coding_byte == 0x94) {
        write_and_eight_direct_first(cor_file, args, and_buffer);
        return;
    }and_value = get_direct_value(args[1]);
    for (int i = 6; i != 2; i--) {
        if (and_value == 0) {
            and_buffer[i] = 0;
            continue;
        }and_buffer[i] = and_value % 0x100;
        and_value /= 0x100;
    }and_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    write(cor_file, and_buffer, 8);
}

static void write_and_nine_direct_first(int cor_file,
char **args, unsigned char *and_buffer)
{
    unsigned int and_value_fst = get_direct_value(args[0]);
    unsigned int and_value_sec = get_indirect_value(args[1]);

    for (int i = 5; i != 1; i--) {
        if (and_value_fst == 0) {
            and_buffer[i] = 0;
            continue;
        }and_buffer[i] = and_value_fst % 0x100;
        and_value_fst /= 0x100;
    }for (int i = 7; i != 5; i--) {
        if (and_value_sec == 0) {
            and_buffer[i] = 0;
            continue;
        }and_buffer[i] = and_value_sec % 0x100;
        and_value_sec /= 0x100;
    }write(cor_file, and_buffer, 9);
}

static void write_and_nine_indirect_first(int cor_file,
char **args, unsigned char *and_buffer)
{
    unsigned int and_value_fst = get_indirect_value(args[0]);
    unsigned int and_value_sec = get_direct_value(args[1]);

    for (int i = 3; i != 1; i--) {
        if (and_value_fst == 0) {
            and_buffer[i] = 0;
            continue;
        }and_buffer[i] = and_value_fst % 0x100;
        and_value_fst /= 0x100;
    }for (int i = 7; i != 3; i--) {
        if (and_value_sec == 0) {
            and_buffer[i] = 0;
            continue;
        }and_buffer[i] = and_value_sec % 0x100;
        and_value_sec /= 0x100;
    }write(cor_file, and_buffer, 9);
}

void write_and_nine(int cor_file, unsigned char coding_byte,
char **args)
{
    unsigned char and_buffer[9] = "000000000";

    and_buffer[0] = 0x06;
    and_buffer[1] = coding_byte;
    and_buffer[8] = (unsigned char)my_getnbr(++args[2]);
    if (coding_byte == 0xB4) {
        write_and_nine_direct_first(cor_file, args, and_buffer);
        return;
    }write_and_nine_indirect_first(cor_file, args, and_buffer);
}
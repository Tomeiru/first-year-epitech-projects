/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_and_second
*/

#include "asm.h"

static void write_or_eight_direct_first(int cor_file,
char **args, unsigned char *or_buffer)
{
    unsigned int or_value = get_direct_value(args[0]);

    for (int i = 5; i != 1; i--) {
        if (or_value == 0) {
            or_buffer[i] = 0;
            continue;
        }or_buffer[i] = or_value % 0x100;
        or_value /= 0x100;
    }or_buffer[6] = (unsigned char)my_getnbr(++args[1]);
    write(cor_file, or_buffer, 8);
}

void write_or_eight(int cor_file, unsigned char coding_byte,
char **args)
{
    unsigned char or_buffer[8] = "00000000";
    unsigned int or_value;

    or_buffer[0] = 0x07;
    or_buffer[1] = coding_byte;
    or_buffer[7] = (unsigned char)my_getnbr(++args[2]);
    if (coding_byte == 0x94) {
        write_or_eight_direct_first(cor_file, args, or_buffer);
        return;
    }or_value = get_direct_value(args[1]);
    for (int i = 6; i != 2; i--) {
        if (or_value == 0) {
            or_buffer[i] = 0;
            continue;
        }or_buffer[i] = or_value % 0x100;
        or_value /= 0x100;
    }or_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    write(cor_file, or_buffer, 8);
}

static void write_or_nine_direct_first(int cor_file,
char **args, unsigned char *or_buffer)
{
    unsigned int or_value_fst = get_direct_value(args[0]);
    unsigned int or_value_sec = get_indirect_value(args[1]);

    for (int i = 5; i != 1; i--) {
        if (or_value_fst == 0) {
            or_buffer[i] = 0;
            continue;
        }or_buffer[i] = or_value_fst % 0x100;
        or_value_fst /= 0x100;
    }for (int i = 7; i != 5; i--) {
        if (or_value_sec == 0) {
            or_buffer[i] = 0;
            continue;
        }or_buffer[i] = or_value_sec % 0x100;
        or_value_sec /= 0x100;
    }write(cor_file, or_buffer, 9);
}

static void write_or_nine_indirect_first(int cor_file,
char **args, unsigned char *or_buffer)
{
    unsigned int or_value_fst = get_indirect_value(args[0]);
    unsigned int or_value_sec = get_direct_value(args[1]);

    for (int i = 3; i != 1; i--) {
        if (or_value_fst == 0) {
            or_buffer[i] = 0;
            continue;
        }or_buffer[i] = or_value_fst % 0x100;
        or_value_fst /= 0x100;
    }for (int i = 7; i != 3; i--) {
        if (or_value_sec == 0) {
            or_buffer[i] = 0;
            continue;
        }or_buffer[i] = or_value_sec % 0x100;
        or_value_sec /= 0x100;
    }write(cor_file, or_buffer, 9);
}

void write_or_nine(int cor_file, unsigned char coding_byte,
char **args)
{
    unsigned char or_buffer[9] = "000000000";

    or_buffer[0] = 0x07;
    or_buffer[1] = coding_byte;
    or_buffer[8] = (unsigned char)my_getnbr(++args[2]);
    if (coding_byte == 0xB4) {
        write_or_nine_direct_first(cor_file, args, or_buffer);
        return;
    }write_or_nine_indirect_first(cor_file, args, or_buffer);
}
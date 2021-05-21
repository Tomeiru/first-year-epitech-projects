/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_sti
*/

#include "asm.h"

static void write_sti_seven(int cor_file, unsigned char coding_byte,
char **args)
{
    unsigned char xor_buffer[7] = "0000000";
    unsigned short sti_value_first = get_index_value(args[1]);
    unsigned short sti_value_second = get_index_value(args[2]);

    xor_buffer[0] = 0x0b;
    xor_buffer[1] = coding_byte;
    for (int i = 4; i != 2; i--) {
        if (sti_value_first == 0) {
            xor_buffer[i] = 0;
            continue;
        }xor_buffer[i] = sti_value_first % 0x100;
        sti_value_first /= 0x100;
    }for (int i = 6; i != 4; i--) {
        if (sti_value_second == 0) {
            xor_buffer[i] = 0;
            continue;
        }xor_buffer[i] = sti_value_second % 0x100;
        sti_value_second /= 0x100;
    }xor_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    write(cor_file, xor_buffer, 7);
}

static void write_sti_six_index_first(int cor_file,
char **args, unsigned char *sti_buffer)
{
    unsigned short sti_value = get_index_value(args[1]);

    for (int i = 4; i != 2; i--) {
        if (sti_value == 0) {
            sti_buffer[i] = 0;
            continue;
        }sti_buffer[i] = sti_value % 0x100;
        sti_value /= 0x100;
    }sti_buffer[5] = (unsigned char)my_getnbr(++args[2]);
    write(cor_file, sti_buffer, 6);
}

static void write_sti_six(int cor_file, unsigned char coding_byte,
char **args)
{
    unsigned char sti_buffer[6] = "000000";
    unsigned short sti_value;

    sti_buffer[0] = 0x0b;
    sti_buffer[1] = coding_byte;
    sti_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    if (coding_byte == 0x64) {
        write_sti_six_index_first(cor_file, args, sti_buffer);
        return;
    }sti_value = get_index_value(args[2]);
    for (int i = 5; i != 3; i--) {
        if (sti_value == 0) {
            sti_buffer[i] = 0;
            continue;
        }sti_buffer[i] = sti_value % 0x100;
        sti_value /= 0x100;
    }sti_buffer[3] = (unsigned char)my_getnbr(++args[1]);
    write(cor_file, sti_buffer, 6);
}

static void write_sti_five(int cor_file, unsigned char coding_byte,
char **args)
{
    unsigned char sti_buffer[5];

    sti_buffer[0] = 0x0b;
    sti_buffer[1] = coding_byte;
    sti_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    sti_buffer[3] = (unsigned char)my_getnbr(++args[1]);
    sti_buffer[4] = (unsigned char)my_getnbr(++args[2]);
    write(cor_file, sti_buffer, 5);
}

void write_sti(char *line, int cor_file)
{
    char **args = get_args_arr(line, get_info_label(line));
    int coding_byte = get_coding_byte(args);

    if (coding_byte == 0x68) {
        write_sti_seven(cor_file, coding_byte, args);
        return;
    }if (coding_byte == 0x58 || coding_byte == 0x64) {
        write_sti_six(cor_file, coding_byte, args);
        return;
    }write_sti_five(cor_file, coding_byte, args);
}
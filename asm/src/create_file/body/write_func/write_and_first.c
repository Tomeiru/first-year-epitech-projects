/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_and
*/

#include "asm.h"

static void write_and_five(int cor_file, unsigned char coding_byte,
char **args)
{
    unsigned char and_buffer[5];

    and_buffer[0] = 0x06;
    and_buffer[1] = coding_byte;
    and_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    and_buffer[3] = (unsigned char)my_getnbr(++args[1]);
    and_buffer[4] = (unsigned char)my_getnbr(++args[2]);
    write(cor_file, and_buffer, 5);
}

static void write_and_six_indirect_first(int cor_file,
char **args, unsigned char *and_buffer)
{
    unsigned int and_value = get_indirect_value(args[0]);

    for (int i = 3; i != 1; i--) {
        if (and_value == 0) {
            and_buffer[i] = 0;
            continue;
        }and_buffer[i] = and_value % 0x100;
        and_value /= 0x100;
    }and_buffer[4] = (unsigned char)my_getnbr(++args[1]);
    write(cor_file, and_buffer, 6);
}

static void write_and_six(int cor_file, unsigned char coding_byte,
char **args)
{
    unsigned char and_buffer[6] = "000000";
    unsigned int and_value;

    and_buffer[0] = 0x06;
    and_buffer[1] = coding_byte;
    and_buffer[5] = (unsigned char)my_getnbr(++args[2]);
    if (coding_byte == 0xD4) {
        write_and_six_indirect_first(cor_file, args, and_buffer);
        return;
    }and_value = get_indirect_value(args[1]);
    for (int i = 4; i != 2; i--) {
        if (and_value == 0) {
            and_buffer[i] = 0;
            continue;
        }and_buffer[i] = and_value % 0x100;
        and_value /= 0x100;
    }and_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    write(cor_file, and_buffer, 6);
}

static void write_and_seven(int cor_file, unsigned char coding_byte,
char **args)
{
    unsigned char and_buffer[7] = "0000000";
    unsigned int and_value_fst = get_indirect_value(args[0]);
    unsigned int and_value_sec = get_indirect_value(args[1]);

    and_buffer[0] = 0x06;
    and_buffer[1] = coding_byte;
    for (int i = 3; i != 1; i--) {
        if (and_value_fst == 0) {
            and_buffer[i] = 0;
            continue;
        }and_buffer[i] = and_value_fst % 0x100;
        and_value_fst /= 0x100;
    }for (int i = 5; i != 3; i--) {
        if (and_value_sec == 0) {
            and_buffer[i] = 0;
            continue;
        }and_buffer[i] = and_value_sec % 0x100;
        and_value_sec /= 0x100;
    }and_buffer[6] = (unsigned char)my_getnbr(++args[2]);
    write(cor_file, and_buffer, 7);
}

void write_and(char *line, int cor_file)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned char coding_byte = get_coding_byte(args);

    if (coding_byte == 0x54) {
        write_and_five(cor_file, coding_byte, args);
        return;
    }if (coding_byte == 0xD4 || coding_byte == 0x74) {
        write_and_six(cor_file, coding_byte, args);
        return;
    }if (coding_byte == 0xF4) {
        write_and_seven(cor_file, coding_byte, args);
        return;
    }if (coding_byte == 0x94 || coding_byte == 0x64) {
        write_and_eight(cor_file, coding_byte, args);
        return;
    }if (coding_byte == 0xB4 || coding_byte == 0xE4) {
        write_and_nine(cor_file, coding_byte, args);
        return;
    }write_and_eleven(cor_file, coding_byte, args);
}
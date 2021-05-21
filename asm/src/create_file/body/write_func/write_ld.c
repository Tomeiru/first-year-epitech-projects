/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_ld
*/

#include "asm.h"

static void write_ld_five(int cor_file, char **args,
unsigned char coding_byte)
{
    unsigned char ld_buffer[5] = "00000";
    unsigned short ld_value = get_indirect_value(args[0]);

    ld_buffer[0] = 2;
    ld_buffer[1] = coding_byte;
    for (int i = 3; i != 1; i--) {
        if (ld_value == 0) {
            ld_buffer[i] = 0;
            continue;
        }
        ld_buffer[i] = ld_value % 0x100;
        ld_value /= 0x100;
    }ld_buffer[4] = (unsigned char)my_getnbr(++args[1]);
    write(cor_file, ld_buffer, 5);
}

static void write_ld_seven(int cor_file, char **args,
unsigned char coding_byte)
{
    unsigned char ld_buffer[7] = "0000000";
    unsigned int ld_value = get_direct_value(args[0]);

    ld_buffer[0] = 2;
    ld_buffer[1] = coding_byte;
    for (int i = 5; i != 1; i--) {
        if (ld_value == 0) {
            ld_buffer[i] = 0;
            continue;
        }
        ld_buffer[i] = ld_value % 0x100;
        ld_value /= 0x100;
    }ld_buffer[6] = (unsigned char)my_getnbr(++args[1]);
    write(cor_file, ld_buffer, 7);
}

void write_ld(char *line, int cor_file)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned char coding_byte = get_coding_byte(args);

    if (coding_byte == 0xD0) {
        write_ld_five(cor_file, args, coding_byte);
        return;
    }write_ld_seven(cor_file, args, coding_byte);
}
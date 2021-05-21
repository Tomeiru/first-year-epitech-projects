/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_ld
*/

#include "asm.h"

static void write_lld_five(int cor_file, char **args,
unsigned char coding_byte)
{
    unsigned char lld_buffer[5] = "00000";;
    unsigned short lld_value = get_indirect_value(args[0]);

    lld_buffer[0] = 0x0D;
    lld_buffer[1] = coding_byte;
    for (int i = 3; i != 1; i--) {
        if (lld_value == 0) {
            lld_buffer[i] = 0;
            continue;
        }
        lld_buffer[i] = lld_value % 0x100;
        lld_value /= 0x100;
    }lld_buffer[4] = (unsigned char)my_getnbr(++args[1]);
    write(cor_file, lld_buffer, 5);
}

static void write_lld_seven(int cor_file, char **args,
unsigned char coding_byte)
{
    unsigned char lld_buffer[7] = "0000000";;
    unsigned int lld_value = get_direct_value(args[0]);

    lld_buffer[0] = 0x0D;
    lld_buffer[1] = coding_byte;
    for (int i = 5; i != 1; i--) {
        if (lld_value == 0) {
            lld_buffer[i] = 0;
            continue;
        }
        lld_buffer[i] = lld_value % 0x100;
        lld_value /= 0x100;
    }lld_buffer[6] = (unsigned char)my_getnbr(++args[1]);
    write(cor_file, lld_buffer, 7);
}

void write_lld(char *line, int cor_file)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned char coding_byte = get_coding_byte(args);

    if (coding_byte == 0xD0) {
        write_lld_five(cor_file, args, coding_byte);
        return;
    }write_lld_seven(cor_file, args, coding_byte);
}
/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_ldi
*/

#include "asm.h"

static void write_indirect_ldi(int cor_file, unsigned char *ldi_buffer,
char **args)
{
    unsigned short indirect = get_indirect_value(args[0]);
    unsigned short index = get_index_value(args[1]);

    for (int i = 3; i != 1; i--) {
        if (indirect == 0) {
            ldi_buffer[i] = 0;
            continue;
        }ldi_buffer[i] = indirect % 0x100;
        indirect /= 0x100;
    }for (int i = 5; i != 3; i--) {
        if (index == 0) {
            ldi_buffer[i] = 0;
            continue;
        }ldi_buffer[i] = index % 0x100;
        index /= 0x100;
    }ldi_buffer[6] = (unsigned char)my_getnbr(++args[2]);
    write(cor_file, ldi_buffer, 7);
}

static void write_direct_ldi(int cor_file, unsigned char *ldi_buffer,
char **args)
{
    unsigned short first_index = get_index_value(args[0]);
    unsigned short sec_index = get_index_value(args[1]);

    for (int i = 3; i != 1; i--) {
        if (first_index == 0) {
            ldi_buffer[i] = 0;
            continue;
        }ldi_buffer[i] = first_index % 0x100;
        first_index /= 0x100;
    }for (int i = 5; i != 3; i--) {
        if (sec_index == 0) {
            ldi_buffer[i] = 0;
            continue;
        }ldi_buffer[i] = sec_index % 0x100;
        sec_index /= 0x100;
    }ldi_buffer[6] = (unsigned char)my_getnbr(++args[2]);
    write(cor_file, ldi_buffer, 7);
}

void write_ldi(char *line, int cor_file)
{
    unsigned char ldi_buffer[7] = "0000000";
    char **args = get_args_arr(line, get_info_label(line));
    unsigned char coding_byte = get_coding_byte(args);

    ldi_buffer[0] = 0x0a;
    ldi_buffer[1] = coding_byte;
    if (coding_byte == 0xa4) {
        write_direct_ldi(cor_file, ldi_buffer, args);
        return;
    }write_indirect_ldi(cor_file, ldi_buffer, args);
    return;
}

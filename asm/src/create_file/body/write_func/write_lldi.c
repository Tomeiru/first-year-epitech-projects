/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_ldi
*/

#include "asm.h"

static void write_indirect_lldi(int cor_file, unsigned char *lldi_buffer,
char **args)
{
    unsigned short indirect = get_indirect_value(args[0]);
    unsigned short index = get_index_value(args[1]);

    for (int i = 3; i != 1; i--) {
        if (indirect == 0) {
            lldi_buffer[i] = 0;
            continue;
        }lldi_buffer[i] = indirect % 0x100;
        indirect /= 0x100;
    }for (int i = 5; i != 3; i--) {
        if (index == 0) {
            lldi_buffer[i] = 0;
            continue;
        }lldi_buffer[i] = index % 0x100;
        index /= 0x100;
    }lldi_buffer[6] = (unsigned char)my_getnbr(++args[2]);
    write(cor_file, lldi_buffer, 7);
}

static void write_direct_lldi(int cor_file, unsigned char *lldi_buffer,
char **args)
{
    unsigned short first_index = get_index_value(args[0]);
    unsigned short sec_index = get_index_value(args[1]);

    for (int i = 3; i != 1; i--) {
        if (first_index == 0) {
            lldi_buffer[i] = 0;
            continue;
        }lldi_buffer[i] = first_index % 0x100;
        first_index /= 0x100;
    }for (int i = 5; i != 3; i--) {
        if (sec_index == 0) {
            lldi_buffer[i] = 0;
            continue;
        }lldi_buffer[i] = sec_index % 0x100;
        sec_index /= 0x100;
    }lldi_buffer[6] = (unsigned char)my_getnbr(++args[2]);
    write(cor_file, lldi_buffer, 7);
}

static void write_lldi_seven(char *line, int cor_file)
{
    unsigned char lldi_buffer[7] = "0000000";
    char **args = get_args_arr(line, get_info_label(line));
    unsigned char coding_byte = get_coding_byte(args);

    lldi_buffer[0] = 0x0e;
    lldi_buffer[1] = coding_byte;
    if (coding_byte == 0xa4) {
        write_direct_lldi(cor_file, lldi_buffer, args);
        return;
    }write_indirect_lldi(cor_file, lldi_buffer, args);
    return;
}

static void write_lldi_five(char *line, int cor_file)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned char coding_byte = get_coding_byte(args);
    unsigned char lldi_buffer[5];

    lldi_buffer[0] = 0x0e;
    lldi_buffer[1] = coding_byte;
    lldi_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    lldi_buffer[3] = (unsigned char)my_getnbr(++args[1]);
    lldi_buffer[4] = (unsigned char)my_getnbr(++args[2]);
    write(cor_file, lldi_buffer, 5);
}

void write_lldi(char *line, int cor_file)
{
    char **args = get_args_arr(line, get_info_label(line));
    unsigned char coding_byte = get_coding_byte(args);

    if (coding_byte == 0xa4 || coding_byte == 0xe4) {
        write_lldi_seven(line, cor_file);
        return;
    }if (coding_byte == 0x54) {
        write_lldi_five(line, cor_file);
        return;
    }write_lldi_six(line, cor_file);
}

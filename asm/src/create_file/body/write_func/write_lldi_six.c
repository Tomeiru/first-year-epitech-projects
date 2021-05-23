/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_lldi_six
*/

#include "asm.h"

static void write_lldi_six_d_r_r(int cor_file,
unsigned char *lldi_buffer, char **args)
{
    unsigned short index = get_index_value(args[0]);

    lldi_buffer[4] = (unsigned char)my_getnbr(++args[1]);
    for (int i = 3; i != 1; i--) {
        if (index == 0) {
            lldi_buffer[i] = 0;
            continue;
        }
        lldi_buffer[i] = index % 0x100;
        index /= 0x100;
    }write(cor_file, lldi_buffer, 6);
}

static void write_lldi_six_i_r_r(int cor_file,
unsigned char *lldi_buffer, char **args)
{
    unsigned short indirect = get_indirect_value(args[0]);

    lldi_buffer[4] = (unsigned char)my_getnbr(++args[1]);
    for (int i = 3; i != 1; i--) {
        if (indirect == 0) {
            lldi_buffer[i] = 0;
            continue;
        }
        lldi_buffer[i] = indirect % 0x100;
        indirect /= 0x100;
    }write(cor_file, lldi_buffer, 6);
}

static void write_lldi_six_r_d_r(int cor_file,
unsigned char *lldi_buffer, char **args)
{
    unsigned short index = get_index_value(args[1]);

    lldi_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    for (int i = 4; i != 2; i--) {
        if (index == 0) {
            lldi_buffer[i] = 0;
            continue;
        }
        lldi_buffer[i] = index % 0x100;
        index /= 0x100;
    }write(cor_file, lldi_buffer, 6);
}

void write_lldi_six(char *line, int cor_file)
{
    char **args = get_args_arr(line, get_info_label(line));
    unsigned char coding_byte = get_coding_byte(args);
    unsigned char lldi_buffer[6] = "000000";

    lldi_buffer[0] = 0x0e;
    lldi_buffer[1] = coding_byte;
    lldi_buffer[5] = (unsigned char)my_getnbr(++args[2]);
    if (coding_byte == 0x64) {
        write_lldi_six_r_d_r(cor_file, lldi_buffer, args);
        return;
    }if (coding_byte == 0x94) {
        write_lldi_six_d_r_r(cor_file, lldi_buffer, args);
        return;
    }write_lldi_six_i_r_r(cor_file, lldi_buffer, args);

}
/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_st
*/

#include "asm.h"

static void write_st_five(int cor_file, char **args,
unsigned char coding_byte)
{
    unsigned char st_buffer[5] = "00000";;
    unsigned short st_value = get_indirect_value(args[1]);

    st_buffer[0] = 3;
    st_buffer[1] = coding_byte;
    st_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    for (int i = 4; i != 2; i--) {
        if (st_value == 0) {
            st_buffer[i] = 0;
            continue;
        }
        st_buffer[i] = st_value % 0x100;
        st_value /= 0x100;
    }write(cor_file, st_buffer, 5);
}

static void write_st_four(int cor_file, char **args,
unsigned char coding_byte)
{
    unsigned char st_buffer[4];

    st_buffer[0] = 3;
    st_buffer[1] = coding_byte;
    st_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    st_buffer[3] = (unsigned char)my_getnbr(++args[1]);
    write(cor_file, st_buffer, 4);
}

void write_st(char *line, int cor_file)
{
    int label = get_info_label(line);
    char **args = get_args_arr(line, label);
    unsigned char coding_byte = get_coding_byte(args);

    if (coding_byte == 0x70) {
        write_st_five(cor_file, args, coding_byte);
        return;
    }write_st_four(cor_file, args, coding_byte);
}
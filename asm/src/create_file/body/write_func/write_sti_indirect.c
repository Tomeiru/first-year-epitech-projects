/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_sti_indirect
*/

#include "asm.h"

static void write_sti_indirect_idx(int cor_file, unsigned char coding_byte,
char **args)
{
    unsigned char sti_buffer[7] = "0000000";
    unsigned short sti_value = get_indirect_value(args[1]);
    unsigned short sti_value_sec = get_index_value(args[2]);

    sti_buffer[0] = 0x0b;
    sti_buffer[1] = coding_byte;
    sti_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    for (int i = 4; i != 2; i--) {
        if (sti_value == 0) {
            sti_buffer[i] = 0;
            continue;
        }sti_buffer[i] = sti_value % 0x100;
        sti_value /= 0x100;
    }for (int i = 6; i != 4; i--) {
        if (sti_value_sec == 0) {
            sti_buffer[i] = 0;
            continue;
        }sti_buffer[i] = sti_value_sec % 0x100;
        sti_value_sec /= 0x100;
    }write(cor_file, sti_buffer, 7);
}

static void write_sti_indirect_register(int cor_file, unsigned char coding_byte,
char **args)
{
    unsigned char sti_buffer[6] = "000000";
    unsigned short sti_value = get_indirect_value(args[1]);

    sti_buffer[0] = 0x0b;
    sti_buffer[1] = coding_byte;
    sti_buffer[2] = (unsigned char)my_getnbr(++args[0]);
    for (int i = 4; i != 2; i--) {
        if (sti_value == 0) {
            sti_buffer[i] = 0;
            continue;
        }sti_buffer[i] = sti_value % 0x100;
        sti_value /= 0x100;
    }sti_buffer[5] = (unsigned char)my_getnbr(++args[2]);
    write(cor_file, sti_buffer, 6);
}

void write_sti_indirect(int cor_file, unsigned char coding_byte,
char **args)
{
    if (coding_byte == 0x74) {
        write_sti_indirect_register(cor_file, coding_byte, args);
        return;
    }write_sti_indirect_idx(cor_file, coding_byte, args);
}
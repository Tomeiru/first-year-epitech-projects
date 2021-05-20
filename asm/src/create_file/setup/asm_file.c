/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** asm_file
*/

#include "asm.h"

void asm_file(info_t *info, int i)
{
    if (error_check_file(info->files[i]) == 84) {
        info->return_value = 84;
        return;
    }create_cor_file(info->files[i], info->filenames[i]);
}
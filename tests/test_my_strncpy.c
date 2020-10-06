/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>

Test (my_strncpy, copy_only_4_characters)
{
    char dest[5] = {0};

    my_strncpy(dest, "paindemie", 4);
    cr_assert_str_eq(dest, "pain");
}

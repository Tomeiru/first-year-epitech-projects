/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>

Test (my_revstr, reverse_a_string)
{
    char str[5] = "dems";

    my_revstr(str, "dems");
    cr_assert_str_eq(str, "smed");
}

/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test (my_strncmp, find_a_different_character)
{
    char str[5] = "dems";
    char srr[9] = "demsolo";

    cr_assert_eq(my_strncmp(str, srr, 8), strncmp(str, srr, 8));
}
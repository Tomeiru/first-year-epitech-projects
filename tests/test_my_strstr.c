/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test (my_strstr, find_a_string)
{
    char *str = "hi fucking cunt";
    char *arr = "fucking";

    cr_assert_str_eq(my_strstr(str, arr), "fucking cunt");
}

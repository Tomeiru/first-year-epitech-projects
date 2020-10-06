/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>

Test (my_str_islower, contains_only_lower_char)
{
    char str[6] = "salut";

    cr_assert_eq(my_str_islower(str), 1);
}

Test (my_str_islower, contains_only_UPPER_char)
{
    char str[6] = "SALUT";

    cr_assert_eq(my_str_islower(str), 0);
}

Test (my_str_islower, contains_numbers)
{
    char str[6] = "74657";

    cr_assert_eq(my_str_islower(str), 0);
}

Test (my_str_islower, contains_weird_things)
{
    char str[6] = "[]}";

    cr_assert_eq(my_str_islower(str), 0);
}
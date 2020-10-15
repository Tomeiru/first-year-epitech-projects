/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>

Test (is_valid_num, contains_non_num_chars)
{
    char str[5] = "Ul*£";

    cr_assert_eq(is_valid_num(str), 0);
}

Test (is_valid_num, contains_num_chars)
{
    char str[10] = "847465647";

    cr_assert_eq(is_valid_num(str), 1);
}

Test (is_valid_num, contains_negative_num_char)
{
    char str[8] = "-884748";

    cr_assert_eq(is_valid_num(str), 1);
}

Test (is_valid_num, contains_num_and_bad_minus)
{
    char str[19] = "7473463-----743743";

    cr_assert_eq(is_valid_num(str), 0);
}

Test (is_valid_num, contains_num_and_bad_front_minus)
{
    char str[19] = "-----7473463743743";

    cr_assert_eq(is_valid_num(str), 0);
}
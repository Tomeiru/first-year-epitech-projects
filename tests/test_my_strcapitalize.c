/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>

char *my_strcapitalize(char *str);

Test (my_strcapitalize, no_cap)
{
    char *str = "hey, 42Wds fo-two; fi+o";
    cr_assert_str_eq(my_strcapitalize(strdup(str)), "Hey, 42wds Fo-Two; Fi+O");
}

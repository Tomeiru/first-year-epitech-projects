/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

int error(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if ((str[i] == '%' || str[i] == '/') && str[i + 1] == '0')
            return (84);
    }
    return (1);
}
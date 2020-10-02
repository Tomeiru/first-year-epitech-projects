/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int l = 0;

    while (str[l] != '\0'){
        l = l + 1;
    }
    return (l);
}

/*
** EPITECH PROJECT, 2020
** n
** File description:
** n
*/

int my_strlen(char const *str)
{
    int l = 0;

    while (str[l] != '\0'){
        l = l + 1;
    }
    return (l);
}

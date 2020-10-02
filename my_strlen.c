/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** Function that counts and returns the number of characters found in the string passed as parameter.
*/

int my_strlen(char const *str)
{
    int l = 0;

    while (str[l] != '\0'){
        l = l + 1;
    }
    return(l);
}

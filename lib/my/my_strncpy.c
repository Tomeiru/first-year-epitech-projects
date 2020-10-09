/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    
    int i = 0;

    for (; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    for (; n > i; i++)
        dest[i] = '\0';
    return (dest);
}
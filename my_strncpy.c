/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    
    int i = 0;
    
    for (i = 0; src[i] != '\0' && i < n; i++)
        dest [i] = src [i];
    for ( ; n > i; i++)
    return (dest);
}
/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    
    for ( ; src[i] != '\0'; i++)
        dest [i] = src [i];
    if (dest[i] != "\0")
        dest[i] = '\0';
    return (dest);
}

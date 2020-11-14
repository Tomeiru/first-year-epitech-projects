/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_xmaj
*/

#include "my_printf.h"

char which_letter_maj(unsigned long long decimal)
{
    unsigned long long value = 10;
    int i = 0;
    char letter[6] = {
        'A', 'B', 'C', 'D', 'E', 'F'
    };

    for ( ; i < 6; i++) {
        if (decimal % 16 == value)
            return (letter[i]);
        value++;
    }
    return (0);
}

char *print_xmaj(unsigned long long decimal)
{
    int len = det_len_unsigned_hexa(decimal);
    char *hexadecimal = malloc(sizeof(char) * len);
    int i = 0;

    if (decimal == 0)
        return (my_strdup("0"));
    for ( ; decimal != 0; decimal /= 16)
        if (decimal % 16 >= 10)
            hexadecimal[i++] = which_letter_maj(decimal);
        else
            hexadecimal[i++] = decimal % 16 + 48;
    hexadecimal[i] = '\0';
    my_revstr(hexadecimal);
    return (hexadecimal);
}

char which_letter_min(unsigned long long decimal)
{
    unsigned long long value = 10;
    int i = 0;
    char letter[6] = {
        'a', 'b', 'c', 'd', 'e', 'f'
    };

    for ( ; i < 6; i++) {
        if (decimal % 16 == value)
            return (letter[i]);
        value++;
    }
    return (0);
}

char *print_x(unsigned long long decimal)
{
    int len = det_len_unsigned_hexa(decimal);
    char *hexadecimal = malloc(sizeof(char) * len);
    int i = 0;

    if (decimal == 0)
        return (my_strdup("0"));
    for ( ; decimal != 0; decimal /= 16)
        if (decimal % 16 >= 10)
            hexadecimal[i++] = which_letter_min(decimal);
        else
            hexadecimal[i++] = decimal % 16 + 48;
    hexadecimal[i] = '\0';
    my_revstr(hexadecimal);
    return (hexadecimal);
}
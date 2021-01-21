/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** main
*/

#include "giantman.h"

char *my_get_first_line(char const *src)
{
    char *dest;
    int i = 0;

    for ( ; src[i] != '\n' && src[i] != '\0'; i++);
    dest = malloc(sizeof(char) * (i + 1));
    for (i = 0; src[i] != '\n'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

int get_new_len(char *file)
{
    char *new_len = my_get_first_line(file);
    return (my_getnbr(new_len));
}

int get_index(char *file)
{
    char *index = my_get_first_line(file);
    return (my_getnbr(index));
}

void decompress_and_print(char *file, int new_len, int i)
{
    int j = 0;
    unsigned char temp = 0;
    char *uncompressed_file = malloc(sizeof(char) * (new_len + 1));

    for ( ; j < i; j++)
        uncompressed_file[j] = file[j];
    for ( ; j < new_len; j++) {
        temp = file[i++];
        if (temp > 9 && temp < 100) {
            uncompressed_file[j++] = temp / 10 + 48;
            uncompressed_file[j++] = temp % 10 + 48;
        }if (temp > 99) {
            uncompressed_file[j++] = temp / 100 + 48;
            uncompressed_file[j++] = temp % 100 / 10 + 48;
            uncompressed_file[j++] = temp % 10 + 48;
        }if (temp < 10)
            uncompressed_file[j++] = temp + 48;
        uncompressed_file[j] = file[i++];
    }write(1, uncompressed_file, new_len);
}

void ppm_decompression(char *file, int len)
{
    int new_len = get_new_len(file);
    int i = 0;

    for ( ; *file != '\n'; file++);
    i = get_index(++file);
    for ( ; *file != '\n'; file++);
    file++;
    decompress_and_print(file, new_len, i);
}
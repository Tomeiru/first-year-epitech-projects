/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-mathieu.brujan
** File description:
** ppm_compression
*/

#include "antman.h"

int get_new_len(char *file, int len)
{
    int new_len = get_index(file, len);

    for (int i = get_index(file, len); file[i]; i++)
        if (file[i] == '\n')
            new_len += 2;
    return (new_len);
}

int conditions(char *reverse_file, int *i)
{
    int index = *i;

    if ((reverse_file[index + 1] >= '0' && reverse_file[index + 1] <= '9') &&
    (reverse_file[index + 2] >= '0' && reverse_file[index + 2] <= '9') &&
    (reverse_file[index + 3] >= '0' && reverse_file[index + 3] <= '9') &&
    (reverse_file[index + 4] == '\n')) {
        *i += 3;
        return (0);
    }if ((reverse_file[index + 2] >= '0' && reverse_file[index + 2] <= '9') &&
    (reverse_file[index + 1] >= '0' && reverse_file[index + 1] <= '9') &&
    (reverse_file[index + 3] == '\n')) {
        *i += 2;
        return (0);
    }if ((reverse_file[index + 1] >= '0' && reverse_file[index + 1] <= '9') &&
    (reverse_file[index + 2] == '\n')) {
        *i += 1;
        return (0);
    }return (1);
}

int get_index(char *file, int len)
{
    char *reverse_file = my_revstr(my_strdup(file));
    int stop = 0;
    int i = 0;

    for ( ; reverse_file[i] && stop == 0; i++)
        stop = conditions(reverse_file, &i);
    free(reverse_file);
    return (len - i + 1);
}

unsigned char compress_number(char *file, int *i)
{
    int index = *i;
    char *number;

    if ((file[index + 1] >= '0' && file[index + 1] <= '9') &&
    (file[index + 2] >= '0' && file[index + 2] <= '9')) {
        number = malloc(sizeof(char) * 4);
        number[0] = file[index];
        number[1] = file[index + 1];
        number[2] = file[index + 2];
        number[3] = '\0';
        *i += 3;
        return (my_getnbr(number));
    }if (file[index + 1] >= '0' && file[index + 1] <= '9') {
        number = malloc(sizeof(char) * 3);
        number[0] = file[index];
        number[1] = file[index + 1];
        number[2] = '\0';
        *i += 2;
        return (my_getnbr(number));
    }*i += 1;
    return (file[index] - 48);
}

void ppm_compression(char *file, int len)
{
    int new_len = get_new_len(file, len);
    unsigned char *compressed_file = malloc(sizeof(unsigned char) *
    (new_len + 1));
    int j = 0;
    int i = get_index(file, len);

    for ( ; j < i; j++)
        compressed_file[j] = file[j];
    for ( ; j < new_len; j++) {
        if (file[i] <  '0' || file[i] > '9')
            compressed_file[j] = file[i++];
        else
            compressed_file[j] = compress_number(file, &i);
    }
    my_put_nbr(len);
    write(1, "\n", 1);
    my_put_nbr(get_index(file, len));
    write(1, "\n", 1);
    write(1, compressed_file, new_len);
}
/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-mathieu.brujan
** File description:
** lyr_compression
*/

#include "include/antman.h"

void print_compressed(t_link *dictionary, char *compressed, int compress_len)
{
    for ( ; dictionary != NULL; dictionary = dictionary->next) {
        my_putstr(dictionary->word);
        write(1, '\n', 1);
    }
}

char *compress_file(char *file, int len, t_link *copy)
{
    char *compressed = malloc(sizeof(char) * len);

    for (int i = 0; file[i] != '\0'; i++) {
        
    }
}

void lyr_compression(char *file, int len, int compress_len)
{
    int word_length = 0;
    char *compressed;
    t_link *dictionary = malloc(sizeof(*dictionary));

    dictionary = NULL;
    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == ' ')
            word_length = 0;
        else
            word_length++;
        if (word_length >= 3 && (file[i + 1] == ' ' || file[i + 1] == '\0'))
            update_dictionary(file, i, word_length, &dictionary);
    }
    for (t_link *copy = dictionary; copy != NULL; copy = copy->next) {
        compressed = compress_file(file, compress_len, copy);
        compress_len = my_strlen(compressed);
    }
    print_compressed(dictionary, compressed, compress_len);
    return;
}
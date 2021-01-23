/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-mathieu.brujan
** File description:
** dictionary modifying functions for lyric compression
*/

#include "include/antman.h"

void add_word(char *buffer, t_link **dictionary)
{
    t_link *element = malloc(sizeof(*element));
    t_link *copy = *dictionary;

    element->word = buffer;
    element->next = NULL;
    if (*dictionary == NULL) {
        *dictionary = element;
        return;
    }
    for ( ; copy->next != NULL; copy = copy->next);
    copy->next = element;
}

int check_word(char *file, char *buffer, int word_length)
{
    int counter = 0;
    int k = 0;

    for (int i = 0; file[i] != '\0'; i++) {
        if (buffer[k] == file[i]) {
            k++;
        } else
            k = 0;
        if (k == word_length) {
            counter++;
            k = 0;
        }
    }
    if (counter >= 2)
        return (1);
    return (0);
}

char *get_word(char *file, int i, int word_length)
{
    int j = 0;
    char *buffer = malloc(sizeof(char) * word_length + 1);

    for (int k = i - (word_length - 1); k != k + word_length; k++) {
        buffer[j] = file[k];
        j++;
    }
    buffer[j] = '\0';
    return (buffer);
}

void update_dictionary(char *file, int i, int word_length, t_link **dictionary)
{
    char *buffer = get_word(file, i, word_length);

    if (check_word(file, buffer, word_length) == 1){
        add_word(buffer, dictionary);
    }
}
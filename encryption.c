/*
** EPITECH PROJECT, 2020
** 103cypher
** File description:
** answer_calc
*/

#include "cipher.h"

int len_matrix_finder(int len_key)
{
    int i = 0;

    for ( ; i * i < len_key; i++);
    return (i);
}

int *key_matrix_value(char *key, int len_matrix)
{
    int full_len = (len_matrix * len_matrix);
    int *key_matrix = malloc(sizeof(int) * (full_len + 1));
    int i = 0;

    for ( ; i < full_len; i++)
        key_matrix[i] = 0;
    key_matrix[i] = -1;
    for (i = 0; key[i]; i++)
        key_matrix[i] = key[i];
    return (key_matrix);
}

int *message_matrix_value(char *message, int len_matrix)
{
    int len_message = strlen(message);
    if (len_message % len_matrix != 0)
        len_message += len_matrix - (len_message % len_matrix);
    int *msg_matrix = malloc(sizeof(int) * (len_message + 1));
    int i = 0;

    for ( ; i < len_message; i++)
        msg_matrix[i] = 0;
    msg_matrix[i] = -1;
    for (i = 0; message[i]; i++)
        msg_matrix[i] = message[i];
    return (msg_matrix);
}

int *encrypted_message(int *key_matrix, int *message_matrix, int len_matrix, int len_message)
{
    if (len_message % len_matrix != 0)
        len_message += len_matrix - (len_message % len_matrix);
    int *e_message = malloc(sizeof(int) * (len_message + 1));
    int j = 0;
    int i = 0;

    for ( ; i < len_message; i++)
        e_message[i] = 0;
    e_message[i] = -1;
    for (i = 0; i < len_message; i++) {
        for (j = 0; j < len_matrix; j++)
            e_message[i] += message_matrix[j + i / len_matrix * len_matrix] * key_matrix[j * len_matrix + i % len_matrix];
    }
    return (e_message);
}

void encryption(char **av)
{
    int len_key = strlen(av[2]);
    int len_matrix = len_matrix_finder(len_key);
    int *key_matrix = key_matrix_value(av[2], len_matrix);
    int *message_matrix = message_matrix_value(av[1], len_matrix);
    int *encryption = encrypted_message(key_matrix, message_matrix, len_matrix, strlen(av[1]));
    int len_message = strlen(av[1]);
    int k = 0;


    if (len_message % len_matrix != 0)
        len_message += len_matrix - (len_message % len_matrix);
    printf("Key matrix:\n");
    for (int i = 0; i < len_matrix; i++) {
        for (int j = 0; j < len_matrix; j++) {
            if (j != len_matrix - 1)
                printf("%-6i", key_matrix[k++]);
            else
                printf("%i\n", key_matrix[k++]);
        }
    }
    printf("\nEncrypted message:\n");
    for (int i = 0; i < len_message; i++) {
        if (i != len_message - 1)
            printf("%i ", encryption[i]);
        else
            printf("%i\n", encryption[i]);
    }
}
/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-103cipher-mathieu.brujan
** File description:
** decryption
*/

#include "cipher.h"

int *cofactor_adjugation(int *cofactor)
{
    int *adjugate = malloc(sizeof(int) * 9);

    adjugate[0] = cofactor[0];
    adjugate[1] = cofactor[3];
    adjugate[2] = cofactor[6];
    adjugate[3] = cofactor[1];
    adjugate[4] = cofactor[4];
    adjugate[5] = cofactor[7];
    adjugate[6] = cofactor[2];
    adjugate[7] = cofactor[5];
    adjugate[8] = cofactor[8];
    return (adjugate);
}

int *minor_to_cofactor(int *minor)
{
    int *cofactor = malloc(sizeof(int) * 9);

    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0)
            cofactor[i] = minor[i];
        else
            cofactor[i] = -minor[i];
    }
    free(minor);
    return (cofactor);
}

int *key_to_minor(int *key_matrix)
{
    int *minor = malloc(sizeof(int) * 9);

    minor[0] = key_matrix[4] * key_matrix[8] - key_matrix[5] * key_matrix[7];
    minor[1] = key_matrix[3] * key_matrix[8] - key_matrix[5] * key_matrix[6];
    minor[2] = key_matrix[3] * key_matrix[7] - key_matrix[4] * key_matrix[6];
    minor[3] = key_matrix[1] * key_matrix[8] - key_matrix[2] * key_matrix[7];
    minor[4] = key_matrix[0] * key_matrix[8] - key_matrix[2] * key_matrix[6];
    minor[5] = key_matrix[0] * key_matrix[7] - key_matrix[1] * key_matrix[6];
    minor[6] = key_matrix[1] * key_matrix[5] - key_matrix[2] * key_matrix[4];
    minor[7] = key_matrix[0] * key_matrix[5] - key_matrix[2] * key_matrix[3];
    minor[8] = key_matrix[0] * key_matrix[4] - key_matrix[1] * key_matrix[3];
    return (minor);
}

double *adjugate_to_inverse(int *adjugate, int determinant)
{
    double *inversed_key = malloc(sizeof(double) * 9);
    double uno = 1;
    double ddeterminant = determinant;
    double invert = uno / ddeterminant;
    //printf("%f\n", invert);
    for (int i = 0; i < 9; i++)
        inversed_key[i] = uno / ddeterminant * adjugate[i];
    return (inversed_key);
}

double *inversion_mat(int *key_matrix)
{
    int *minor = key_to_minor(key_matrix);
    int *cofactor = minor_to_cofactor(minor);
    int *adjugate = cofactor_adjugation(cofactor);
    int determinant = key_matrix[0] * cofactor[0] + key_matrix[1] * cofactor[1] + key_matrix[2] * cofactor[2];
    double *inversed_key = adjugate_to_inverse(adjugate, determinant);
    return (inversed_key);
}

double *decryption_num_matrix(char *message)
{
    int count = 1;
    int i = 0;
    double *msg_matrix;

    for ( ; message[i]; i++)
        if (message[i] == ' ')
            count++;
    if (count % 3 != 0)
        count += 3 - (count % 3);
    msg_matrix = malloc(sizeof(double) * (count + 1));
    for (i = 0; i < count; i++)
        msg_matrix[i] = 0;
    msg_matrix[i] = -1;
    for (i = 0; message[0]; i++)
        msg_matrix[i] = strtol(message, &message, 0);
    return (msg_matrix);
}

char *decrypted_message(double *key_matrix, double *message_matrix, int len_matrix, char *message)
{
    int count = 1;
    for (int i = 0; message[i]; i++)
        if (message[i] == ' ')
            count++;
    if (count % 3 != 0)
        count += 3 - (count % 3);
    double *e_message_d = malloc(sizeof(double) * (count + 1));
    char *e_message = malloc(sizeof(char) * (count + 1));
    int j = 0;
    int i = 0;

    for (i = 0; i < count; i++) {
        for (j = 0; j < len_matrix; j++)
            e_message_d[i] += message_matrix[j + i / len_matrix * len_matrix] * key_matrix[j * len_matrix + i % len_matrix];
        e_message[i] = e_message_d[i] + 0.5;
    }
    return (e_message);
}

void decryption(char **av)
{
    int len_key = strlen(av[2]);
    int len_matrix = len_matrix_finder(len_key);
    int *key_matrix = key_matrix_value(av[2], len_matrix);
    double *number_matrix = decryption_num_matrix(av[1]);
    double *inversed_key = inversion_mat(key_matrix);
    char *encryption = decrypted_message(inversed_key, number_matrix, len_matrix, av[1]);
    int k = 0;

    for (int i = 0; i < 9; i++)
        if (inversed_key[i] == -0)
            inversed_key[i] = 0;
    printf("Key matrix:\n");
    for (int i = 0; i < len_matrix; i++) {
        for (int j = 0; j < len_matrix; j++) {
            if (j != len_matrix - 1)
                printf("%-8.3f", inversed_key[k++]);
            else
                printf("%.3f\n", inversed_key[k++]);
        }
    }
    printf("%s\n", encryption);
}
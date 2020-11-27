/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** file_name_to_array
*/

#include "my_ls.h"

char *add_quote(char *str)
{
    int add_quote = 0;
    int i = 0;
    char new_str[my_strlen(str) + 3];

    for ( ; str[i]; i++)
        if (str[i] == ' ')
            add_quote = 1;
    if (add_quote == 1) {
        new_str[0] = 39;
        for (i = 0; i < my_strlen(str); i++)
            new_str[i + 1] = str[i];
        new_str[i + 1] = 39;
        new_str[i + 2] = '\0';
        return (my_strdup(new_str));
    }
    return (my_strdup(str));
}

char **file_name_to_array(int nb_file, char *filepath)
{
    char *array_filename[nb_file];
    DIR *dir = opendir(filepath);
    struct dirent *file = readdir(dir);
    int i = 0;

    while (file != NULL) {
        if (file->d_name[0] != '.')
            array_filename[i++] = file->d_name;
        file = readdir(dir);
    }
    return (my_arrdup(array_filename, nb_file));
}
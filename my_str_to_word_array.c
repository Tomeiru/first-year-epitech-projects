/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

int my_isnotalphanumerical(char d)
{
    int count = 0;
    
    if (d > 57 && d < 65 || d > 90 &&
    d < 97 || d > 122 || d < 48) {
        count++;
    }
    if (count == 0)
        return (1);
    else
        return (0);
}

int charcounter(char const *str)
{
    int maxchar = 0;
    int totalchar = 0;
    int char_i = 0;

    for (char_i = 0; str[char_i] != '\0'; char_i++) {
        if (my_isnotalphanumerical(str[char_i]) == 0)
            totalchar++;
        else {
            if (totalchar + 1 > maxchar) {
                totalchar++;
                maxchar = totalchar;
                totalchar = 0;
            }
            totalchar = 0;
        }
    }
    return (maxchar);
}

int ligncounter(char const *str)
{
    int totalign = 0;
    int char_i = 0;

    for (char_i = 0; str[char_i] != '\0'; char_i++) {
        if (my_isnotalphanumerical(str[char_i]) == 0) {
            if (my_isnotalphanumerical(str[char_i + 1]) == 1)
                totalign++;
        }
    }
    totalign += 2;
    return(totalign);
}

char **my_str_to_word_array(char const *str)
{
    int char_i = 0;
    int char_ia = 0;
    int string_i = 0;
    int charmax = charcounter(str);
    char **wordarray;

    if (str[char_i] == ' ')
        string_i = -1;
    wordarray = malloc(sizeof(char*) * ligncounter(str));
    wordarray[string_i] = malloc(sizeof(char) * charmax);
    for (char_i = 0; str[char_i] != '\0'; char_i++) {
        if (my_isnotalphanumerical(str[char_i]) == 0) {
            if (my_isnotalphanumerical(str[char_i + 1]) == 1) {
                wordarray[string_i][char_ia] = '\0';
                string_i++;
                wordarray[string_i] = malloc(sizeof(char) * charmax);
                char_ia = 0;
            }
            else {
                char_ia++;
            }
        }
        else {
            wordarray[string_i][char_ia] = str[char_i];
            char_ia++;
        }
    }
    return (wordarray);
}
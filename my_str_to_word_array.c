/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

int charcounter (char const *str)
{
    int maxchar = 0;
    int totalchar = 0;
    int char_i = 0;

    for (char_i = 0; str[char_i] != '\0'; char_i++) {
        if (str[char_i] > 57 && str [char_i] < 65 || str[char_i] > 90 &
        & str[char_i] < 97 || str[char_i] > 122 || str[char_i] < 48) {
            if (totalchar + 1 > maxchar) {
                totalchar++;
                maxchar = totalchar;
                totalchar = 0;
            }
            totalchar = 0;
        }
        else {
            totalchar++;
        }
    }
    return (maxchar);
}

int ligncounter (char const *str)
{
    int totalign = 0;
    int char_i = 0;

    for (char_i = 0; str[char_i] != '\0'; char_i++) {
        if (str[char_i] > 57 && str [char_i] < 65 || str[char_i] > 90 &
        & str[char_i] < 97 || str[char_i] > 122 || str[char_i] < 48) {
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
    int string_i = 1;
    int charmax = charcounter(str);
    char **wordarray;
    
    wordarray = malloc(sizeof(char*) * ligncounter(str));
    wordarray[string_i] = malloc(sizeof(char) * charmax);
    for (char_i = 0; str[char_i] != '\0'; char_i++) {
        if (str[char_i] > 57 && str [char_i] < 65 || str[char_i] > 90 &
        & str[char_i] < 97 || str[char_i] > 122 || str[char_i] < 48) {
            wordarray[string_i][char_ia] = '\0';
            string_i++;
            wordarray[string_i] = malloc(sizeof(char) * charmax);
            char_ia = 0;
        }
        else {
            wordarray[string_i][char_ia] = str[char_i];
            char_ia++;
        }
    }
    wordarray[string_i + 1] = "\0";
    return (wordarray);
}
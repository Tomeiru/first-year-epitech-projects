/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** main
*/

char **list_to_arr(char **all_words, int nb_words, char *str)
{
    int k = 0;
    int j = 0;
    int backupk = 0;
    
    for (int i = 0; i < nb_words; i++) {
        for ( ; str[k] == '\t' || str[k] == ' '; k++);
        backupk = k;
        for ( ; str[k] != '\t' && str[k] != ' ' &&
                  str[k] != '\0'; k++) {
            j++;
        }
        all_words[i] = malloc(sizeof(char) * (j + 1));
        k = backupk;
        for (j = 0; str[k] != '\t' && str[k] != ' ' &&
                 str[k] != '\0'; k++) {
            all_words[i][j] = str[k];
            j++;
        }
    }
    return (all_words);
}

int words_counter(char *str)
{
    int i = 0;
    int k = 0;
    int result = 0;

    if (str[0] != '\t' && str[0] != ' ') {
        i++;
        result++;
    }for ( ; str[i] == '\t' || str[i] == ' '; i++);
    if (result == 0 && str[i] == '\0')
        return (0);
    for ( ; str[i]; i++)
        if (str[i] != '\t' && str[i] != ' ' && str[i] != '\0'
            && (str[i - 1] == '\t' || str[i - 1] == ' '))
            result++;
    return (result);
}

void norm(char **all_words, int nb_words, char *str, int i)
{
    int count = 1;
    int stop = 0;

    for (int k = 0; k < i; k++)
        if (my_strcmp(all_words[k], all_words[i]) == 0)
            stop = 1;
    for (int j = 0; j < nb_words && stop == 0; j++)
        if (j != i && my_strcmp(all_words[i], all_words[j]) == 0)
            count++;
    if (stop == 0)
        printf("%s: %i\n", all_words[i], count);
    count = 1;
    stop = 0;
}

int countwords(char *str)
{
    int nb_words = words_counter(str);
    char **all_words;
    int count = 1;
    int stop = 0;

    if (nb_words == 0) {
        write(1, "\n", 1);
        return (0);
    }all_words = malloc(sizeof(char *) * nb_words);
    all_words = list_to_arr(all_words, nb_words, str);
    for (int i = 0; i < nb_words; i++)
        norm(all_words, nb_words, str, i);
    return (0);
}

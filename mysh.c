/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-minishell1-mathieu.brujan
** File description:
** mysh
*/

#include "mysh.h"

char *add_bin(char *input)
{
    int len = get_input_len(input);
    char *str = malloc(sizeof(char) * (len + 6));
    int i = 0;
    int j = 0;

    str[0] = '/';
    str[1] = 'b';
    str[2] = 'i';
    str[3] = 'n';
    str[4] = '/';
    for ( ; input[i] == ' '; i++);
    for ( ; input[i] != ' ' && input[i] != '\0'; i++) {
        str[j + 5] = input[i];
        j++;
    }str[j + 5] = '\0';
    return (str);
}

int words_counter(char *str)
{
    int i = 0;
    int result = 0;

    if (str[0] != ' ') {
        i++;
        result++;
    }for ( ; str[i] == ' '; i++);
    if (result == 0 && str[i] == '\0')
        return (0);
    for ( ; str[i]; i++)
        if (str[i] != ' ' && str[i] != '\0' && str[i - 1] == ' ')
            result++;
    return (result);
}

char **assign_command(char *input, int words_count)
{
    int k = 0;
    int j = 0;
    int backupk = 0;
    char **commands = malloc(sizeof(char *) * (words_count) + 1);
    
    for (int i = 0; i < words_count; i++) {
        for ( ; input[k] == ' '; k++);
        backupk = k;
        for ( ; input[k] != ' ' && input[k] != '\0'; k++)
            j++;
        commands[i] = malloc(sizeof(char) * (j + 1));
        k = backupk;
        for (j = 0; input[k] != ' ' && input[k] != '\0'; k++) {
            commands[i][j] = input[k];
            j++;
        }
    }commands[words_count] = NULL;
    commands[0] = add_bin(commands[0]);
    return (commands);
}

char **get_command(int return_val)
{
    int input_len = 0;
    char *input = get_input(&input_len, return_val);
    int words_count = words_counter(input);
    char **command;

    if (input[0] == '\0')
        return (get_command(0));
    if (words_count == 1) {
        command = malloc(sizeof(char *) * 2);
        command[0] = add_bin(input);
        command[1] = NULL;
        return (command);
    }else {
        command = assign_command(input, words_count);
        return (command);
    }
}

int mysh(char **env, int return_val)
{
    char **command = get_command(return_val);
    int status;

    if (is_it_builtin(command[0]) == 1)
        return_val = builtin(command, env);
    else if (fork() == 0)
        exit(execve(command[0], command, env));
    if (is_it_builtin(command[0]) != 1) {
        waitpid(0, &status, 0);
        return_val = WEXITSTATUS(status);
    }if (return_val == 255) {
        command[0] += 5;
        write(1, command[0], my_strlen(command[0]));
        write(1, ": Command not found.\n", 21);
        return_val = 1;
    }if (isatty(0) == 1) {
        return (mysh(env, return_val));
    }else
        exit(return_val);
}
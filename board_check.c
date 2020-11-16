/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** board_check
*/

#include "bsq.h"

static int line_length(char *board)
{
    int len = my_strlen(board);
    int i = 0;
    int j = 0;

    for (i = 0; board[i] != '\n' && board[i] != '\0'; i++);
    len -= ++i;
    for ( ; board[i] != '\n' && board[i] != '\0'; i++)
        j++;
    if (len % ++j != 0)
        return (84);
    return (0);
}

static int line_counter(int line_number, char *board)
{
    int i = 0;
    int counter = 0;

    for (i = 0; board[i] != '\n' && board[i] != '\0'; i++);
    for ( ; board[i]; i++)
        if (board[i] == '\n')
            counter++;
    if (line_number != counter - 1)
        return (84);
    return (0);
}

static int check_all_character(char *board)
{
    int i = 0;

    for (i = 0; board[i] != '\n' && board[i] != '\0'; i++);
    for ( ; board[i]; i++)
        if (board[i] != 'o' && board[i] != '.' && board[i] != '\n')
            return (84);
    return (0);
}

int my_get_first_line(char *board)
{
    int i = 0;
    char *first_line;
    int number = 0;

    for (i = 0; board[i] != '\n' && board[i] != '\0'; i++);
    first_line = malloc(sizeof(char) * i + 1);
    for (i = 0; board[i] != '\n' && board[i] != '\0'; i++)
        first_line[i] = board[i];
    first_line[i] = '\0';
    number = my_getnbr(first_line);
    for (i = 0; first_line[i]; i++)
        if (first_line[i] < '0' || first_line[i] > '9') {
            number = -1;
            break;
        }
    free(first_line);
    if (number <= 0)
        return (-1);
    return (number);
}

int board_check(char *board)
{
    int line_number = my_get_first_line(board);

    if (line_number == -1 || check_all_character(board) == 84 || 
    line_counter(line_number, board) == 84 || line_length(board) == 84)
        return (84);
    return (0);
}
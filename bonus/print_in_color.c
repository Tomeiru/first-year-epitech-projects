/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** bonus functions for navy
*/

void print_in_color(char *board)
{
    write(1, board, 52);
    for (int i = 52; board[i] != '\0'; i++) {
        if (board[i] == '.')
            write(1, "\033[0;34m", 7);
        else if (board[i] == 'x')
            write(1, "\033[0;31m", 7);
        if (board[i] == 'o')
            write(1, "\033[0;33m", 7);
        my_putchar(board[i]);
        write(1, "\033[0m", 4);
    }
}
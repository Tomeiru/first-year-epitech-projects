/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** board_creation
*/

#include "navy.h"

char *create_board(void)
{
    char *board = malloc(sizeof(char) * 395);

    board = strcat(board, "my positions:\n |A B C D E F G H\n");
    board = strcat(board, "-+---------------\n1|. . . . . . . .\n");
    board = strcat(board, "2|. . . . . . . .\n3|. . . . . . . .\n");
    board = strcat(board, "4|. . . . . . . .\n5|. . . . . . . .\n");
    board = strcat(board, "6|. . . . . . . .\n7|. . . . . . . .\n");
    board = strcat(board, "8|. . . . . . . .\n\nenemy's positions\n");
    board = strcat(board, " |A B C D E F G H\n-+---------------\n");
    board = strcat(board, "1|. . . . . . . .\n2|. . . . . . . .\n");
    board = strcat(board, "3|. . . . . . . .\n4|. . . . . . . .\n");
    board = strcat(board, "5|. . . . . . . .\n6|. . . . . . . .\n");
    board = strcat(board, "7|. . . . . . . .\n8|. . . . . . . .\n\n");
    return (board);
}

char *place_boats(char *board, int pos_first, int pos_sec, int value)
{
    if (pos_first > pos_sec)
        my_swap(&pos_first, &pos_sec);
    if ((pos_sec - pos_first) % 18 == 0)
        for (int i = pos_first; i <= pos_sec; i += 18)
            board[i] = value;
    else
        for (int i = pos_first; i <= pos_sec; i += 2)
            board[i] = value;
    return (board);
}

char *add_boat(char *board, char *pos_str)
{
    int first = 0;
    int second = 0;
    int pos_first = 0;
    int pos_sec = 0;

    for (int i = 0; i < 4; i++) {
        first = pos_to_value(pos_str[i * 8 + 2], pos_str[i * 8 + 3]);
        second = pos_to_value(pos_str[i * 8 + 5], pos_str[i * 8 + 6]);
        pos_first = 52 + (first % 10 * 18) + (first * 2 - (first % 10)) / 10;
        pos_sec = 52 + (second % 10 * 18) + (second * 2 - (second % 10)) / 10;
        board = place_boats(board, pos_first, pos_sec, i + 2 + 48);
    }
    return (board);
}
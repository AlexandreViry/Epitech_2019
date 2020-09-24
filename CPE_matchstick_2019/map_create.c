/*
** EPITECH PROJECT, 2020
** map create
** File description:
** functions to create the map
*/


#include <stdlib.h>
#include "my.h"

void display_board_game(char **board, int n)
{
    int width = 1 + 2 * n;

    for (int i = 0; i <= n + 1; i++) {
        for (int x = 0; x != width; x++) {
            my_putchar(board[i][x]);
        }
        my_putchar ('\n');
    }
    my_putchar('\n');
}

char **create_border(char **board, int n)
{
    int width = 2 * n + 1;

    for (int i = 0; i < width; i++) {
        board[0][i] = '*';
    }
    for (int i = 1; i <= n + 1; i++) {
        board[i][0] = '*';
        for (int y = 1; y != width; y++)
            board[i][y] = ' ';
        board[i][width - 1] = '*';
    }
    for (int z = 0; z < width; z++)
        board[n + 1][z] = '*';
    return (board);
}

char **init_i(char **board, int n)
{
    int x = 1;
    int y = n;

    for (int i = 1; i <= n; i++) {
        for (int z = y; z != x + y; z++)
            board[i][z] = '|';
        y = y - 1;
        x = x + 2;
    }
    return (board);
}

char **create_board_game(int n)
{
    int i = 0;
    int width = 1 + 2 * n;
    char **board =  malloc (sizeof(char *) * (n + 3));

    for (; i < n + 2; i++)
        board[i] = malloc(sizeof(char) * (width + 2));
    board[i] = NULL;
    create_border(board, n);
    init_i(board, n);
    return (board);
}


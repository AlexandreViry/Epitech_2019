/*
** EPITECH PROJECT, 2020
** print_maze
** File description:
** display the maze
*/

#include "include/my.h"

void print_maze(char **maze, int x, int y)
{
    for (int i = 0; i < x - 2; i++)
        printf("%s\n", maze[i]);
    printf("%s", maze[x - 1]);
}

void print_board(board_t board)
{
    for (int i = 0; i < board.hight; i++) {
        for (int y = 0; board.cell_board[i][y] != -1; y++)
            printf("%d", board.cell_board[i][y]);
        printf("\n");
    }
}

void print_board_with_char(board_t board)
{
    for (int i = 0; i < board.hight; i++) {
        for (int y = 0; board.cell_board[i][y] != -1; y++) {
            if (board.cell_board[i][y] == 0)
                printf("X");
            else
                printf("*");
        }
        printf("\n");
    }
}

/*
** EPITECH PROJECT, 2020
** solver
** File description:
** values
*/

#include "include/fcts.h"

int up(int **array, int i, int j)
{
    int line_up = i - 1;

    if (line_up == -1)
        return -1;
    else
        return array[line_up][j];
}

int down(int **array, int line, int i, int j)
{
    int line_down = i + 1;

    if (line_down >= line)
        return -1;
    else
        return array[line_down][j];
}

int left(int **array, int i, int j)
{
    int col_left = j - 1;

    if (col_left == -1)
        return -1;
    else
        return array[i][col_left];
}

int right(int **array, int col, int i, int j)
{
    int col_right = j + 1;

    if (col_right >= col)
        return -1;
    else
        return array[i][col_right];
}
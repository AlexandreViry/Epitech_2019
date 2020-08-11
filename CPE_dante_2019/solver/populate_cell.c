/*
** EPITECH PROJECT, 2020
** dante_solver
** File description:
** populate cell
*/

#include "include/fcts.h"

int choose_lowest(int a, int b, int c, int d)
{
    int value = 99999999;

    if (a != -1 && a != 0 && value > a)
        value = a;
    if (b != -1 && b != 0 && value > b)
        value = b;
    if (c != -1 && c != 0 && value > c)
        value = c;
    if (d != -1 && d != 0 && value > d)
        value = d;
    if (value == 99999999)
        value = 0;
    return value;
}

int populate_cell(int **array, c_t coords, int i, int j)
{
    int value = 0;
    int cell = array[i][j];
    int up_cell = up(array, i, j);
    int down_cell = down(array, coords.line, i, j);
    int left_cell = left(array, i, j);
    int right_cell = right(array, coords.col, i, j);

    if (cell != 0)
        return cell;
    value = choose_lowest(up_cell, down_cell, left_cell, right_cell);
    if (value == 0)
        return value;
    else {
        value = value + 1;
        return value;
    }
}

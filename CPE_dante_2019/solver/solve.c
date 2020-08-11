/*
** EPITECH PROJECT, 2020
** dante_solver
** File description:
** solver
*/

#include <stdio.h>
#include "include/fcts.h"

void print_char_map(int **array, int i, int j)
{
    if (array[i][j] == -1)
        printf("X");
    else if (array[i][j] == -2)
        printf("o");
    else
        printf("*");
}

void print_solved_map(int **array, c_t coords)
{
    for (int i = 0; i < coords.line; i++) {
        for (int j = 0; j < coords.col; j++) {
            print_char_map(array, i, j);
        }
        if (i < coords.line - 1)
            printf("\n");
    }
}

c_t move(char pos, c_t path)
{
    if (pos == 'r')
        path.col = path.col + 1;
    if (pos == 'l')
        path.col = path.col - 1;
    if (pos == 'u')
        path.line = path.line - 1;
    if (pos == 'd')
        path.line = path.line + 1;
    return path;
}

char find_path(int temp, int **array, c_t path, c_t coords)
{
    char pos;
    int up_cell = up(array, path.line, path.col);
    int down_cell = down(array, coords.line, path.line, path.col);
    int right_cell = right(array, coords.col, path.line, path.col);
    int left_cell = left(array, path.line, path.col);

    temp = array[path.line][path.col] - 1;
    if (temp == right_cell)
        pos = 'r';
    if (temp == down_cell)
        pos = 'd';
    if (temp == left_cell)
        pos = 'l';
    if (temp == up_cell)
        pos = 'u';
    return pos;
}

void solve(int **array, c_t coords)
{
    char pos;
    int temp = 0;
    c_t path;

    path.line = coords.line - 1;
    path.col = coords.col - 1;
    if (array[path.line][path.col] == 0 || array[path.line][path.col] == -1)
        exit(84);
    while (path.col != 0 || path.line != 0) {
        pos = find_path(temp, array, path, coords);
        array[path.line][path.col] = -2;
        path = move(pos, path);
    }
    array[0][0] = -2;
    print_solved_map(array, coords);
}

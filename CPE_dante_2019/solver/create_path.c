/*
** EPITECH PROJECT, 2020
** dante_solver
** File description:
** create_path
*/

#include "include/fcts.h"

int attribute(int **array, c_t coords, int i, int j)
{
    if (array[i][j] == 0)
        array[i][j] = populate_cell(array, coords, i, j);
    return array[i][j];
}

int **populate(int **array, c_t coords)
{
    for (int i = 0; i < coords.line; i++) {
        for (int j = 0; j < coords.col; j++)
            array[i][j] = attribute(array, coords, i, j);
    }
    return array;
}

int create_path(int **array, int col, int line)
{
    int i = 0;
    int cells = col * line;
    c_t coords;

    coords.line = line;
    coords.col = col;
    if (array[0][0] == -1)
        exit(84);
    else
        array[0][0] = 1;
    while (i < cells) {
        array = populate(array, coords);
        i++;
    }
    solve(array, coords);
    return 0;
}

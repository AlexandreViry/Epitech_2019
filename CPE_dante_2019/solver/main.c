/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function for solver
*/

#include "include/fcts.h"

int return_value(char **map, int **maze)
{
    int ret = 0;
    int col = my_strlen(map[0]);
    int line = my_tablen(map) - 2;

    ret = create_path(maze, col, line);
    return ret;
}

int main(int ac, char **av)
{
    int r = 0;
    char **map;
    int **maze;

    if (ac != 2)
        return 84;
    map = sgl_to_dbl(av[1]);
    maze = word_to_int_array(map);
    r = return_value(map, maze);
    return r;
}

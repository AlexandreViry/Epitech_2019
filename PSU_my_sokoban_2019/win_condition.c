/*
** EPITECH PROJECT, 2020
** validation
** File description:
** is it win ?
*/

#include "include/my.h"

int is_it_o(int win, char c)
{
    if (win == 1)
        return (win);
    if (c == 'O')
        return (1);
    return (0);
}

int error(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);

    if (ac != 2)
        return (1);
    if (fd < 0)
        return (1);
}

int is_it_win(char **map)
{
    int win = 0;

    for (int i = 0; map[i] != NULL; i++)
        for (int x = 0; map[i][x] != '\0'; x++)
            win = is_it_o(win, map[i][x]);
    return (win);
}
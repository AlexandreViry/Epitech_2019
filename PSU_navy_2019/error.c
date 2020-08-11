/*
** EPITECH PROJECT, 2020
** error
** File description:
** error cases
*/

#include "include/my.h"

int check_error(char *map)
{
    int boat = map[0] - 49;

    if (map[2] == map[5])
        if (map[6] != map [3] + boat)
            return (84);
    else if (map[3] == map[6])
        if (map[5] != map [2] + boat)
            return (84);
    return (0);
}

int analyse_map(char *str, int fd)
{
    char *buff = malloc(sizeof(char) * 33);
    char **coo;
    int y = 50;

    read(fd, buff, 31);
    coo = sgl_to_dbl(buff);
    for (int i = 0; i != 4; i++) {
        if (coo[i][0] != y) {
            free(coo);
            return (84);
        }
        y++;
    }
    for (int i = 0; i < 4; i++)
        if (check_error(coo[i]) == 84) {
            free(coo);
            return (84);
        }
    return (y);
}

int error(int ac, char **av)
{
    int i = who_is_playing(ac);

    if (i == 1) {
        if (open(av[1], O_RDONLY) < 0)
            return (84);
        i = analyse_map(av[1], open(av[1], O_RDONLY));
        return (i);
    }
    if (i == 2) {
        if (open(av[2], O_RDONLY) < 0)
            return (84);
        i = analyse_map(av[2], open(av[2], O_RDONLY));
        return (i);
    }
    return (i);
}
/*
** EPITECH PROJECT, 2020
** main ls
** File description:
** main of ls
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <dirent.h>
#include "my.h"

int look3(int ac, char **av)
{
    int i = 1;

    if (av[i][1] == 'R')
        tR (ac, av);
}

int look(int ac, char **av)
{
    int i = 1;

    if (ac == 1)
        if (ls(".") == 84)
            return (84);
    if (ac == 2 && av[1][0] != '-') {
        if (ls(av[1]) == 84)
            return (84);
        return (0);
    }
    while (i != ac) {
        if (av[i][0] == '-') {
            look3 (ac, av);
            return (0);
        }
        i++;
    }
    look2 (ac, av);
    return (0);
}

int main (int ac, char **av)
{
    look(ac, av);
}

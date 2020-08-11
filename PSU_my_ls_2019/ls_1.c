/*
** EPITECH PROJECT, 2020
** ls_1
** File description:
** first part of the code
*/

#include "my.h"

int ls(char *av)
{
    DIR *dir;
    struct dirent *repo;

    dir = opendir(av);
    if (dir == NULL)
        return (84);
    for (repo; (repo = readdir(dir)) != NULL;)
        if (repo->d_name[0] != '.') {
            my_putstr(repo->d_name);
            my_putstr("  ");
        }
    my_putstr("\n");
    closedir(opendir(av));
    return (0);
}

int look2(int ac, char **av)
{
    int i = 1;

    while (i != ac) {
        my_putstr(av[i]);
        my_putstr(":\n");
        ls(av[i]);
        if (i != ac - 1)
            my_putstr("\n");
        i++;
    }
}

int tr2(int ac, char **av)
{
}

int tR(int ac, char **av)
{
    if (ac == 2) {
        my_putstr(".");
        my_putstr(":\n");
        ls(".");
    }
    if (ac > 2) {
        my_putstr(av[2]);
        my_putstr(":\n");
        ls(av[2]);
    }
    tr2(ac, av);
}

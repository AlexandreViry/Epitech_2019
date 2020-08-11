/*
** EPITECH PROJECT, 2020
** main
** File description:
** main program
*/

#include "my.h"

int the_end(char **av, int i)
{
    while (av[1][i] != '\0') {
        int tmp = av[1][i];

        if (64 < tmp && tmp < 91 || tmp > 96 && tmp < 123)
            return (0);
        i++;
    }
    return (1);
}
int space(char **av, int i)
{
    int tmp = av[1][i];

    if (the_end(av, i + 1) == 1)
        return (0);
    if (64 < tmp && tmp < 91 || tmp > 96 && tmp < 123) {
        if (av[1][i + 1] == ' ')
            my_putchar (' ');
        else
            return (0);
    }
}

int verification(int ac, char **av)
{
    int i = 0;

    while (av[1][i] != '\0') {
        int tmp = av[1][i];
        
        if (64 < tmp && tmp < 91 || tmp > 96 && tmp < 123)
            my_putchar (tmp);
        else if (tmp == '?' || '.' || '!')
            my_putchar (tmp);
        space (av, i);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac > 2)
        return (84);
    if (if_nothing (ac) == 0)
        return (0);
    verification (ac, av);
    my_putchar ('\n');
}

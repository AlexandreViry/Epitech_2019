/*
** EPITECH PROJECT, 2020
** main
** File description:
** first function
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int error_case(int first, int last)
{
    if (first > last) {
        my_putstr("Error: the second parameter must ");
        my_putstr("be greater than the first one.\n");
        return (1);
    }
    return (0);
}

int other_case(int i)
{
    if (i % 2 == 0 && i % 3 == 0)
        printf("FuzzBozz\n");
    if (i % 2 != 0 && i % 3 != 0)
        printf("%d\n", i);
}

int display_it(int ac, char **av)
{
    int first = atoi(av[1]);
    int last = atoi(av[2]);

    for (int i = first; i <= last; i++) {
        if (i % 2 == 0 && i % 3 != 0)
            printf("Fuzz\n");
        if (i % 3 == 0 && i % 2 != 0)
            printf("Bozz\n");
        other_case(i);
    }
}

int main(int ac, char **av)
{
    if (error(ac, av) == 1)
        return (84);
    if (error_case(atoi(av[1]), atoi(av[2])) == 1)
        return (84);
    display_it(ac, av);
    return (0);
}

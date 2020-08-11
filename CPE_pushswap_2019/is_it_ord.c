/*
** EPITECH PROJECT, 2019
** is it in order 
** File description:
** search if the array is already ordonated
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>

int verify(int ac, char **av)
{
    int i = 1;

    while  (i != ac - 1) {
        if (my_atoi(av[i]) <= my_atoi(av[i + 1]))
            i++;
        else 
            return (1);
    }
    my_putchar('\n');
    return (0);
}

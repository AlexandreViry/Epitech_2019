/*
** EPITECH PROJECT, 2019
** my_compute_square_root.c
** File description:
** We make Roots
*/

#include "my.h"
int my_compute_square_root(int nb)
{
    if (nb < 0) {
        return (0);
    }
    int test = 1;
    int sqrt;

    while (sqrt != nb) {
        sqrt = test * test;
        test = test + 1;
    }
    return (test);
}

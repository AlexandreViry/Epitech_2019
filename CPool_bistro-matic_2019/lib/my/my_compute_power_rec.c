/*
** EPITECH PROJECT, 2019
** my_compute_power_rec.c
** File description:
** We make recurrent power
*/

#include "my.h"
int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    result = nb * my_compute_power_rec(nb, p - 1);
    return (result);
}

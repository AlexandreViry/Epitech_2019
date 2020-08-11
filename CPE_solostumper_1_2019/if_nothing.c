/*
** EPITECH PROJECT, 2020
** if_nothing
** File description:
** displays a \n
*/

#include "my.h"

int if_nothing(int ac)
{
    if (ac < 2) {
        my_putchar('\n');
        return (0);
    } else {
        return (1);
    }
}

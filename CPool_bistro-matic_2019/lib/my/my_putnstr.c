/*
** EPITECH PROJECT, 2019
** my_putnstr.c
** File description:
** We put n char from string
*/

#include "../../include/my.h"
int my_putnstr(char const *str, int nb)
{
    int i;
    i = nb;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}

/*
** EPITECH PROJECT, 2020
** my_put_str
** File description:
** displays a string
*/

#include "include/my.h"

int my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

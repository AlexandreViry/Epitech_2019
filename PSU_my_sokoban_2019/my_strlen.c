/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** count how many chars
*/

#include "include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

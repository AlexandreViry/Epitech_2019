/*
** EPITECH PROJECT, 2020
** my_itoa
** File description:
** from int to string
*/

#include "include/my.h"

char *my_itoa(int i)
{
    char *tmp;
    int len = 0;

    for (int y = i; y > 0; y = y / 10)
        len++;
    tmp = malloc(sizeof(char) * len + 1);
    tmp[len] = '\0';
    while (len--) {
        tmp[len] = i % 10 + 48;
        i = i / 10;
    }
    return (tmp);
}

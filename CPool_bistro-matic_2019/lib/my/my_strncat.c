/*
** EPITECH PROJECT, 2019
** my_strncat.c
** File description:
** We combine part of strings
*/

#include "my.h"
char *my_strncat(char *dest, char const *src, int n)
{
    int m = 0;
    int y = 0;
    int w = n - 1;
    while (dest[y] != '\0') {
        y = y + 1;
    }
    while (m <= w) {
        dest[y] = src[m];
        m = m + 1;
        y = y + 1;
    }
    return (dest);
}

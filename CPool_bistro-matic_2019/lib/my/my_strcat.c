/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** We combine words
*/

#include "my.h"
char *my_strcat(char *dest, char const *src)
{
    int m = 0;
    int n = 0;

    while (dest[m] != '\0') {
        m = m + 1;
    }
    while (src[n] != '\0') {
        dest[m] = src[n];
        m = m + 1;
        n = n + 1;
    }
    return (dest);
}

/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** We copie n char from a string to another
*/

#include "my.h"
void copie_str_w_lim(char *dest, char const *src, int n)
{
    int i = 0;
    int y = n - 1;
    for (i = 0; i <= y; i++) {
        if (src[i] != '\0') {
            dest[i] = src[i];
        } else {
            dest[i] = '\0';
        }
    }
}

char *my_strncpy(char *dest, char const *src, int n)
{
    copie_str_w_lim(dest, src, n);
    my_putstr(dest);
    return (dest);
}

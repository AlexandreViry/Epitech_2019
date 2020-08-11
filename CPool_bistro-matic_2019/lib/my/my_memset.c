/*
** EPITECH PROJECT, 2019
** my_memset.c
** File description:
** we do a memory fill
*/

#include "my.h"
char *my_memset(char *str, char c, int nb)
{
    int count;
    for (count = 0; count != nb; count++) {
        str[count] = c;
    }
    return (str);
}

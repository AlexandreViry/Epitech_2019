/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** we copy string
*/

#include "my.h"
#include <stdlib.h>
char *my_strdup(char const *str, char *dest)
{
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        dest[i] = str[i];
    }
    dest[i] = '\0';
    return (dest);
}

/*
** EPITECH PROJECT, 2019
** newtring.c
** File description:
** first fonction
*/

#include <stdlib.h>
#include "include/my.h"

char *take_newstring(char **str,int x)
{
    char *str2 = *str;
    x = x - 1;
    int y = str2[x];
    char *str3 = malloc(sizeof(char) * my_strlen(str2));
    int z = 0;
    int f = str2[x + 1];

    while (y >= 48 && y <= 57 ||y == f) {
        x = x - 1;
        y = str2[x];
    }
    x = x + 1;
    y = str2[x];
    while (y >= 48 && y <= 57 || y == f) {
        str3[z] = str2[x];
        x = x + 1;
        y = str2[x];
        z = z + 1;
    }
    return (str3);
}

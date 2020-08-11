/*
** EPITECH PROJECT, 2019
** my_strtol
** File description:
** a
*/
#include "../../include/my.h"
#include <stdlib.h>
char *my_strtol(char **str)
{
    int results = 0;
    char *str2 = *str;
    int r = my_strlen(*str);
    char *str3 = malloc(sizeof(char) * r);
    int x = number2(&str2) + 1;
    int y = 0;
    int z = 0;
    
    while (str2[y] != '\0') {
        z = str2[x];
        str3[y] = str2[x];
        x = x + 1;
        y = y + 1;
    }
    return (str3);
}

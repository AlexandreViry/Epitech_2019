/*
** EPITECH PROJECT, 2019
** calcul.c
** File description:
** calculate 
*/
#include <stdlib.h>
#include "include/my.h"

char *take_newstring(char **str,int x);

int calcul(char **str,int x)
{
    char *str2 = *str;
    char *str3 = malloc(sizeof(char) * my_strlen(str2));
    str3 = take_newstring(&str2, x);
    int y = 0;

    if (str2[x] == '*') {
        y = products(&str3);
        return (y);
    }
    if (str2[x] == '/') {
        y = quotient(&str3);
        return (y);
    }
    if (str2[x] == '%') {
        y = modulo(&str3);
        return (y);
    }
    if (str2[x] == '-') {
        y = difference(&str3);
        return (y);
    }
}

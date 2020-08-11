/*
** EPITECH PROJECT, 2020
** my_strcut
** File description:
** cut a function
*/

#include "../include/my.h"

char *my_strcut(char *str, int i, char c)
{
    char *tmp = malloc(sizeof(char) * my_strlen3(str));
    int y = 0;

    for (; str[i] != c; y++, i++)
        tmp[y] = str[i];
    tmp[y++] = '\0';
    return (tmp);
}
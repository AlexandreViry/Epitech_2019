/*
** EPITECH PROJECT, 2019
** my_str_copy_skip.c
** File description:
** We copy string and we skip the value i;
*/

#include "./my.h"
char *my_copy_str_skip(char *str, int i)
{
    int n = 0;
    n = i + 1;
    while (str[n] != '\0') {
        str[i] = str[n];
        i = i + 1;
        n = n + 1;
    }
    str[i] = '\0';
    return (str);
}

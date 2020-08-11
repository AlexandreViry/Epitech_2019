/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** differences between two strings
*/

#include "my.h"

int my_strcmp(char *str, char *str2)
{
    int i = 0;

    for (;str[i] && str2[i] && str[i] == str2[i]; i++) {
    }
    return (str[i] - str2[i]);
}

int my_strcmp2(char *str, char *str2)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            break;
        if (str[i] == ' ')
            break;
        i++;
    }
    char *str1 = malloc(sizeof (char) * i + 4);
    
    for (int y = 0; y != i; y++)
        str1[y] = str[y];
    i = my_strcmp(str1, str2);
    return (i);
}

/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** differences between two strings
*/

#include "my.h"

int my_strncmp(char *str, char *str2, int i)
{
    if (my_strlen(str) < i || my_strlen(str2) < i)
        return 1;
    for (int y = 0; y < i; y++)
        if (str[y] != str2[y])
            return 1;
    return 0;
}

int my_strcmp(char *str, char *str2)
{
    int i = 0;

    for (;str[i] && str2[i] && str[i] == str2[i]; i++);
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
    char *str1 = malloc(sizeof(char) * i + 4);

    for (int y = 0; y != i; y++)
        str1[y] = str[y];
    i = my_strcmp(str1, str2);
    return (i);
}

int my_strcmp3(char *str, char *str2, char c)
{
    int i = 0;
    int boolean = 0;

    for (; str[i] != c && str2[i] != c; i++)
        if (str[i] != str2[i]) {
            boolean = -1;
            break;
        }
    if (boolean == 0 && str[i] == c && str2[i] == c)
        return 0;
    else
        return -1;
}

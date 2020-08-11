/*
** EPITECH PROJECT, 2020
** clear_string
** File description:
** delete spaces and tabulation
*/

#include "include/my.h"

int check_spaces(char *str, int i)
{
    for (int y = 0; str[i] == ' '; i++);
    i--;
    return (i);
}

char *clear_string(char *str)
{
    int y = 0;
    char *tmp = malloc(sizeof(char) * my_strlen3(str) + 1);

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\t')
            str[i] = ' ';
    for (int i = 0; str[i] != '\0'; i++, y++) {
        if (str[i] == ' ' && str[i + 1] == ' ')
            i = check_spaces(str, i);
        tmp[y] = str[i];
    }
    if (tmp[0] == ' ') {
        for (y = 0; tmp[y] != '\0'; y++)
            tmp[y] = tmp[y + 1];
        tmp[y + 1] = '\0';
    }
    free (str);
    return (tmp);
}
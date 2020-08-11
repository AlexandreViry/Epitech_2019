/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concat two strings
*/

#include "../include/my.h"

char *my_strcat(char *str, char *str2)
{
    int y = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(str) + my_strlen(str2) + 2));

    for (int i = 0; str[i] != '\0'; ++i, ++y)
        dest[i] = str[i];
    for (int i = 0; str2[i] != '\0'; ++i, ++y)
        dest[y] = str2[i];
    dest[y + 1] = '\0';
    return (dest);
}
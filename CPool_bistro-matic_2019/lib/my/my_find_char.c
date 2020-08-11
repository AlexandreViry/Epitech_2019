/*
** EPITECH PROJECT, 2019
** my_find_char.c
** File description:
** We search for char
*/

#include "./my.h"
int my_find_char(char *str, char c)
{
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] = c) {
            return (i);
        } else {
            return (0);
        }
    }
}

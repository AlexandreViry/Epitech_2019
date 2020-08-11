/*
** EPITECH PROJECT, 2019
** my_str_islower.c
** File description:
** We search if str contains only lowercase
*/

#include "my.h"
int my_str_islower(char const *str)
{
    int x = 0;
    while (str[x] != '\0') {
        if (str[x] >= 'a' && str[x] <= 'z') {
            x++;
        } else if (str[0] == '\0') {
            return (1);
        } else {
            return (0);
        }
    }
    return (1);
}

/*
** EPITECH PROJECT, 2019
** my_str_isupper.c
** File description:
** to be completed
*/

#include "my.h"
int my_str_isupper(char const *str)
{
    int x = 0;
    while (str[x] != '\0') {
        if (str[x] >= 'A' && str[x] <= 'Z') {
            x++;
        } else if (str[0] == '\0') {
            return (1);
        } else {
            return (0);
        }
    }
    return (1);
}

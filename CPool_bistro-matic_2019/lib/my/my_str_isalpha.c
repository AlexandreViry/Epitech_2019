/*
** EPITECH PROJECT, 2019
** my_str_isalpha.c
** File description:
** fidn if there is only alphabetical char
*/

#include "my.h"
int my_str_isalpha(char const *str)
{
    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] >= 'a' && str[x] <='z') {
            x++;
        } else if (str[x] >= 'A' && str[x] <= 'Z') {
            x++;
        } else {
            return (0);
        }
    }
    return (1);
}

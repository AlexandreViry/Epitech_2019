/*
** EPITECH PROJECT, 2019
** my_str_isnum.c
** File description:
** find is the string only contain digit
*/

#include "my.h"
int my_str_isnum(char const *str)
{
    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] >= '0' && str[x] <='9') {
            x++;
        } else if (str[0] == '\0') {
            return(1);
        } else {
            return (0);
        }
    }
    return (1);
}

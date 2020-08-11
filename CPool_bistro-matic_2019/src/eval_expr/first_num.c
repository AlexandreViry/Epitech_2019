/*
** EPITECH PROJECT, 2019
** eval expr op +
** File description:
** more operators
*/

#include "../../include/my.h"
#include "../../include/evalexp.h"
char *first_num(char *str, char *dest)
{
    int i = 0;
    while (str[i] != '+' && str[i] != '-' && str[i] != '\0' ) {
        if (str[i] == '*' || str[i] == '%' || str[i] == '/') {
            dest = factors(str);
            return (dest);
        } else {
            i = i + 1;
        }
    }
    dest = number(str, dest);
    return (dest);
}

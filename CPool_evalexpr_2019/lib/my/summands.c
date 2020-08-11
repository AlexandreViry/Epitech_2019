/*
** EPITECH PROJECT, 2019
** summands
** File description:
** a
*/

#include <stdlib.h>

int number(char **str);
int my_strlen(char *str);
int number2(char **str);
char *my_strtol(char **str);

int summands(char **str)
{
    int results = 0;
    char *str2 = *str;
    int y = my_strlen(str2);
    int x = 0;

    while (x < y) {
        results = number(&str2) + results;
        x = x + number2(&str2);
        str2 = my_strtol(&str2);
        x = x + 1;
    }
    return (results);
}

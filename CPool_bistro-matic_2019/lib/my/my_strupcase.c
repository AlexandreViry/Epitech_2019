/*
** EPITECH PROJECT, 2019
** my_strupcase.c
** File description:
** We put string in CAPS
*/

#include "my.h"
char *my_strupcase(char *str)
{
    int count;

    for (count = 0; str[count] != '\0'; count++) {
        if (str[count] >= 'a' && str[count] <= 'z') {
            str[count] = str[count] - 32;
        }
    }
    return (str);
}

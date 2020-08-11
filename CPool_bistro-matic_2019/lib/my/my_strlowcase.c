/*
** EPITECH PROJECT, 2019
** my_strlowcase.c
** File description:
** We put strings in minuscule
*/

#include "my.h"
#include <stdio.h>
char *my_strlowcase(char *str)
{
    int count;

    for (count = 0; str[count] != '\0'; count++) {
        if (str[count] >= 'A' && str[count] <= 'Z') {
            str[count] = str[count] + 32;
        }
    }
    return (str);
}

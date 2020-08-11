/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** We reverse string
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
void reverse_str(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char temp;

    i = my_strlen(str);
    k = i / 2;
    i = i - 1;
    while (j < k) {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        i = i - 1;
        j = j + 1;
    }
    j = j + i + 1;
    str[j] = '\0';
}

char *my_revstr(char *str)
{ 
    reverse_str(str);
    return (str);
}

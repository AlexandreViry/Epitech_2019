/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** We compare the n chars value
*/

#include "my.h"
int my_strncmp(char const *s1, char const *s2, int n)
{
    int count = 0;
    int val_s1 = 0;
    int val_s2 = 0;
    int result;

    while (count < n) {
        val_s1 = val_s1 + s1[count];
        val_s2 = val_s2 + s2[count];
        count++;
    }
    result = val_s2 - val_s1;
    return (result);
}

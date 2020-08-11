/*
** EPITECH PROJECT, 2019
** my_isneg.c
** File description:
** Test if number is negative
*/

#include "my.h"
int my_isneg(int n)
{
    if(n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (0);
}

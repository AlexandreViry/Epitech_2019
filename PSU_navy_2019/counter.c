/*
** EPITECH PROJECT, 2020
** counter
** File description:
** count how many signals
*/

#include "include/my.h"

int counter3(int i)
{
    static int count = 0;

    if (i != 0) {
        count = count + i;
        return (count);
    }
    return (count);
}
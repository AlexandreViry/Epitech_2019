/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** We disp characters
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include <string.h>
void my_putchar(char c)
{
    write(1, &c, 1);
}

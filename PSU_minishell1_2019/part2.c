/*
** EPITECH PROJECT, 2020
** part2
** File description:
** second part of the code
*/

#include "my.h"

int analyse(char *buff)
{
    char *str = malloc(sizeof(char) * 5);

    if (my_strlen2(buff, 0) < 3)
        return (1);
    str[0] = 'e';
    str[1] = 'x';
    str[2] = 'i';
    str[3] = 't';
    for (int i = 0; i < 4; i++) {
        if (buff[i] == '\n')
            return (-1);
        if (buff[i] != str[i])
            return (0);
    }
    return (-1);
}

void print_env(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        my_putstr(env[i]);
        my_putchar('\n');
        i++;
    }
}

int how_many_rep(char *str)
{
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '/')
            y++;
    return (y);
}

/*
** EPITECH PROJECT, 2020
** my_sh main
** File description:
** main function
*/

#include "my.h"

int prompt(char **env)
{
    size_t len = 0;
    ssize_t read2;
    char *buff = NULL;

    while (1) {
        buff = NULL;
        my_putstr("$>");
        read2 = getline(&buff, &len, stdin);
        if (read2 < 0 || analyse(buff) < 0)
            return (0);
        other_functions(buff, env);
    }
}

int main(int ac, char **av, char **env)
{
    (void)av;
    if (ac != 1)
        return (84);
    if (prompt(env) == 0)
        return (0);
    return (0);
}

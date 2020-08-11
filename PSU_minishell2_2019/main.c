/*
** EPITECH PROJECT, 2020
** my_sh main
** File description:
** main function
*/

#include "my.h"

void error_function(char *function)
{
    if (my_strcmp(function, "") == 0)
        return;
    my_putstr(function);
    my_putstr(": Command not found.\n");
}

int analyse(char *str)
{
    if (my_strcmp(str, "exit\n") == 0)
        return -1;
    if (my_strcmp(str, "exit") == 0)
        return -1;
    return (0);
}

int try_exe(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            str[i] = '\0';
    if (access(str, X_OK) == 0) {
        fork_it(str, str);
        return (1);
    }
    return (0);
}

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
        buff = clear_string(buff);
        redirection(buff, &env);
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
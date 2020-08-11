/*
** EPITECH PROJECT, 2020
** env
** File description:
** env functions
*/

#include "include/my.h"

void print_pwd(void)
{
    char *temp = malloc(sizeof(char) * 200);

    my_putstr(getcwd(temp, 150));
        my_putchar('\n');
    free(temp);
}

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
}

char *search(char *str)
{
    char *function;
    int i = 0;
    int y = 0;

    if (str[i] == ' ')
        for (; str[i] == ' '; i++);
    for (int z = 0; str[z] != ' '; z++, y++)
        if (str[z] == '\n' || str[z] == '\0')
            break;
    function = malloc(sizeof(char) * (y + 1));
    y = 0;
    for (; str[i] != ' '; i++, y++) {
        if (str[i] == '\n' || str[i] == '\0')
            break;
        function[y] = str[i];
    }
    function[y] = '\0';
    return function;
}

int redirection(char *buff, char ***env)
{
    char *function = search(buff);

    if (function[0] == '\n' || function[0] == '\0')
        return (0);
    if (my_strcmp(function, "env") == 0) {
        print_env(*env);
        return (0);
    }
    if (my_strcmp(function, "pwd") == 0) {
        print_pwd();
        return (0);
    }
    if (my_strcmp(function, "cd") == 0) {
        my_cd(buff);
        return (0);
    }
    if (my_strcmp(function, "setenv") == 0 ||
    my_strcmp(function, "unsetenv") == 0) {
        my_set_env(env, buff);
        return 0;
    }
    if (try_exe(buff) == 1)
        return 0;
    if (search_path(buff, *env, function) != 0)
        return (0);
    error_function(function);
}
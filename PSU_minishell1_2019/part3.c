/*
** EPITECH PROJECT, 2020
** part3
** File description:
** part3 of the code
*/

#include "my.h"

char *divide_by_arg(char *buff)
{
    int count = my_strlen2(buff, 3);
    char *arg;
    int c = 0;

    arg = malloc(sizeof (char) * (count + 3));
    for (int i = 3; i != count + 3; i++) {
        arg[c] = buff[i];
        c++;
    }
    return (arg);
}

int my_cd(char *buff)
{
    char *arg;
    char *tamp = malloc(sizeof (char) * 100);
    int count = 0;

    getcwd (tamp, 200);
    count = how_many_rep(tamp) - 2;
    free(tamp);
    if (buff[2] == '\n' || buff[2] == '\0') {
        for (int i = 0; i != count; i++)
            chdir("../");
        return (0);
    }
    arg = divide_by_arg(buff);
    chdir(arg);
    return (0);
}

void other_functions(char *buff, char **env)
{
    if (my_strcmp2(buff, "env") == 0)
        print_env(env);
    if (my_strcmp2(buff, "cd") == 0)
        my_cd(buff);
}

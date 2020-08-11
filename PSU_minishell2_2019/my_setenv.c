/*
** EPITECH PROJECT, 2020
** setenv and unsetenv
** File description:
** modify the env
*/

#include "include/my.h"

char **remove_env(char **env, int i)
{
    int y = 0;

    for (;env[y] != NULL; y++);
    for (; env[i] != NULL; i++)
        env[i] = env[i + 1];
    env[i] = NULL;
    return env;
}

char **my_unset_env(char **array, char **env)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    if (i != 2)
        return env;
    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], array[1], my_strclen(env[i], '=') - 1) == 0) {
            env = remove_env(env, i);
            return env;
        }
    }
    env = remove_env(env, i);
    env[i + 1] = NULL;
    return (env);
}

char **put_in_env(my_struct_t *struc, char **env, int i)
{
    if (struc->tmp[2] == NULL) {
        env[i] = my_strcat(struc->tmp[1], "=");
        return (env);
    }
    env[i] = my_strcat(struc->tmp[1], "=");
    env[i] = my_strcat(env[i], struc->tmp[2]);
    return env;
}

char **set_the_env(my_struct_t *struc, char **env, char *buff)
{
    char **tmp;
    int i = 0;

    for (; env[i] != NULL; i++) {
        if (my_strncmp(env[i], struc->tmp[1], my_strclen(env[i], '=')) == 0) {
            env = put_in_env(struc, env, i);
            return env;
        }
    }
    tmp = malloc(sizeof(char *) * (i + 2));
    for (int y = 0; env[y] != NULL; y++) {
        tmp[y] = env[y];
    }
    put_in_env(struc, tmp, i);
    tmp[i + 1] = NULL;
    return (tmp);
}

char **my_set_env(char ***env, char *buff)
{
    my_struct_t struc = {0};
    struc.tmp = my_str_to_word_array(buff, ' ');
    int i = 0;

    for (;struc.tmp[i] != NULL; i++);
    if (my_strcmp(struc.tmp[0], "setenv") == 0 && i == 1) {
        print_env(*env);
        return *env;
    }
    if (my_strcmp(struc.tmp[0], "unsetenv") == 0 && i != 2) {
        my_putstr("unsetenv: Too few arguments.\n");
        return *env;
    }
    if (my_strcmp(struc.tmp[0], "setenv") == 0) {
        *env = set_the_env(&struc, *env, buff);
    }
    if (my_strcmp(struc.tmp[0], "unsetenv") == 0)
        *env = my_unset_env(struc.tmp, *env);
}

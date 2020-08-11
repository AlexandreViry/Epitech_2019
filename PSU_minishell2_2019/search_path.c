/*
** EPITECH PROJECT, 2020
** search path
** File description:
** search the path of the function
*/

#include <errno.h>
#include "include/my.h"

static int manage_errors(char **array)
{
    if (errno == EACCES) {
        my_putstr(array[0]);
        my_putstr(": Permission denied.\n");
    }
    else if (errno == ENOEXEC) {
        my_putstr(array[0]);
        my_putstr(": Exec format error. Wrong Architecture.\n");
    }
    else
        perror("shell");
    return 0;
}

int fork_it(char *str, char *arg)
{
    int i = 0;
    pid_t pid;
    char **array = my_str_to_word_array(arg, ' ');

    pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid > 0) {
        waitpid(pid, &i, 0);
        kill(pid, SIGTERM);
    }
    else {
        if (execve(str, array, NULL) == -1)
            manage_errors(array);
    }
    return (0);
}

int search_path(char *path, char **env, char *func)
{
    int i = 0;
    char **array;

    for (; env[i] != NULL; i++)
        if (my_strcmp3("PATH=", env[i], '=') == 0) {
            array = my_str_to_word_array(env[i], ':');
            break;
        }
    array[0] = my_strcut(array[0], 5, '\0');
    i = index_1(env[i], ':');
    for (int y = 0; y != i; y++)
        if (access(my_strcat(array[y], my_strcat("/", func)), X_OK) == 0) {
            fork_it(my_strcat(array[y], my_strcat("/", func)), path);
            return (1);
        }
    return 0;
}
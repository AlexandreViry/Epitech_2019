/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** all prototypes
*/

#ifndef _MY_H_
#define _MY_H_
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "linked_list.h"


void my_putchar(char c);
int my_putstr(char *str);
int my_put_nbr(int nb);
int my_strlen(char *str);
int my_strcmp(char *str, char *str2);
int my_strcmp2(char *str, char *str2);
int index_1(char *str, char c);
int my_strcmp3(char *str, char *str2, char c);
int my_strlen2(char *str, int i);
char *divide_by_arg(char *buff);
int my_cd(char *buff);
int other_functions(char *buff, char **env);
int analyse(char *buff);
void print_env(char **env);
int how_many_rep(char *str);
int my_put_in_list(Linked_list **list, char *str);
int my_param_to_list(Linked_list **list, char **str);
int my_atoi(char *str);
char *my_strcut(char *str, int i, char c);
void my_show_list(Linked_list *list);
int my_get_nbr(char *str);
char **my_str_to_word_array(char *str, char c);
int search_path(char *path, char **env, char *func);
void error_function(char *function);
char *my_strcat(char *str, char *str2);
char *clear_string(char *str);
int my_strlen3(char *str);
int try_exe(char *str);
int my_strncmp(char *str, char *str2, int i);
char **my_set_env(char ***env, char *buff);
int my_strclen(char *str, char c);
int fork_it(char *str, char *arg);

#endif
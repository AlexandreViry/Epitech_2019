/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** all prototypes
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void my_putchar(char c);
int my_putstr(char *str);
int my_put_nbr(int nb);
int my_strlen(char *str);
int my_strcmp(char *str, char *str2);
int my_strcmp2(char *str, char *str2);
int my_strlen2(char *str, int i);
char *divide_by_arg(char *buff);
int my_cd(char *buff);
void other_functions(char *buff, char **env);
int analyse(char *buff);
void print_env(char **env);
int how_many_rep(char *str);

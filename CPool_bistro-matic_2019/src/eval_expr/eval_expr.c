/*
** EPITECH PROJECT, 2019
** evalexpr
** File description:
** the main funtion
*/

#include <stdlib.h>
#include "../../include/bistro.h"
#include "../../include/my.h"
#include "../../include/evalexp.h"
char *operator_setup(char const *ops, char *str)
{
    my_replace_char(str, ops[0], '(');
    my_replace_char(str, ops[1], ')');
    my_replace_char(str, ops[2], '+');
    my_replace_char(str, ops[3], '-');
    my_replace_char(str, ops[4], '*');
    my_replace_char(str, ops[5], '/');
    my_replace_char(str, ops[6], '%');
    return (str);
}

char *eval_expr(char const *base, char const *ops,      \
                char const *expr, unsigned int size)
{
    char str[size];
    my_strdup(expr, str);
    return (str);
}

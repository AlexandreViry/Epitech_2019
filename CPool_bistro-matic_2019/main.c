/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** bistro's main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./include/bistromatic.h"
#include "./include/my.h"
static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = '\0';
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    for (int i = 0; ops[i] != '\0'; i++) {
        for (int j = i + 1; ops[j] != '\0'; j++) {
            if (ops[i] == ops[j]) {
                my_putstr(SYNTAX_ERROR_MSG);
                exit(EXIT_OPS);
            }
        }
    }
}

static void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

static void check_parenthesis(char const *str, char c, char d)
{
    int i = 0;
    int j = 0;
    for (int k = 0; str[k] != '\0'; k++)
    {
        if (str[k] == c)
            i = i + 1;
        if (str[k] == d)
            j = j + 1;
    }
    if (j != i) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    check_parenthesis(expr, ops[0], ops[1]);
    eval_expr(av[1], av[2], expr, size);
    return (EXIT_SUCCESS);
}

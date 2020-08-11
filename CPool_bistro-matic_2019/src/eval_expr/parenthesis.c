/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** parenthesis
*/

#include "../../include/my.h"
#include "../../include/evalexp.h"
void del_space(char *str)
{
    int y;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            str =  my_copy_str_skip(str, i);
            i = i + 1;
        } else {
            i = i + 1;
        }
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            y = y + 1;
            parenthesis(str);
            i = 0;
        }
    }
}

void calc_btw_parenthesis(char *str, int x, int y)
{
    int nb;
    int len;
    char des[y + 3];
    my_copy_segment(str, des, x, y);
    my_put_in_seg(str, des, x - 1, y + 1);
}

void parenthesis(char *str)
{
    int z;
    int y = 0;
    int len = my_strlen(str);
    int nb = 0;
    int x = len;
    while (x != 0) {
        if (str[x] == '(') {
            y = y + 1;
            nb = x;
            x = 0;
        } else {
            x = x - 1;
        }
    }
    z = nb;
    x = nb + 1;
    while (str[z] != ')') {
        z = z + 1;
    }
    calc_btw_parenthesis(str, x, z);
}

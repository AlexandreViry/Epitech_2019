/*
** EPITECH PROJECT, 2019
** eval-expr
** File description:
** operators prog
*/

#include "../../include/evalexp.h"
#include "../../include/my.h"
#include "../../include/bistro.h"
char *number(char *str, char *dest)
{
    int i = 0;
    int j = 0;
    int len = my_strlen(str);
    while (str[i] != '\0') {
        if (str[0] == '-') {
            i = i + 1;
        }
        if (str[i] <= '9' && str[i] >= '0') {
            i = i + 1;
            j = j + 1;
        } else {
            i = len;
        }
    }
    my_copy_segment(str, dest, 0, j);
    str = my_copy_strn(str, j);
    return (dest);
}

char *test_op(char *str, char *dest, char *dest2)
{
    int len = 0;
    if (str[0] == '*') {
        str = my_copy_strn(str, 1);
        number(str, dest2);
        dest = infinMul(dest, dest2);
    }
    if (str[0] == '/') {
        str = my_copy_strn(str, 1);
        number(str, dest2);
        dest = infinDiv(dest, dest2);
    }
    if (str[0] == '%') {
        str = my_copy_strn(str, 1);
        number(str, dest2);
        dest = infinMod(dest, dest2);
    }
    len = my_strlen(dest);
    my_put_in_seg(str, dest, 0, len);
    return (str);
}

char *factors(char *str)
{
    int len = my_strlen(str);
    char dest2[len];
    char dest[len];
    int j = 0;
    number(str, dest);
    while (str[j] != '+' && str[j] != '-' && str[j] != '\0') {
        test_op(str, dest, dest2);
        j = j + 1;
    }
    return (str);
}

char *summands(char *str)
{
    int i = 0;
    int len = my_strlen(str);
    char dest2[len];
    char dest[len];
    first_num(str, dest);
    while (str[0] != '\0') {
        if (str[0] == '+') {
            str = my_copy_strn(str, 1);
            dest2 == number(str, dest2); 
            infinAdd(dest, dest2);
            len = my_strlen(dest);
            my_put_in_seg(str, dest, 0, len);
        }
        if (str[0] == '-') {
            str = my_copy_strn(str, 1);
            infinsub(dest, dest2);
            len = my_strlen(dest);
            my_put_in_seg(str, dest, 0, len);
        }
    }
    return (str);
}

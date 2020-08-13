/*
** EPITECH PROJECT, 2019
** infinmod
** File description:
** infinite modulo
*/

#include "../infinadd/include/infinadd.h"
#include "../../include/bistro.h"
#include "../../include/my.h"
char *the_rest(char *str, char *str2, char *res)
{
    int len1 = my_strlen(str);
    int len2 = my_strlen(str2);
    char unit[3] = "1";
    while (len1 > len2) {
        str = infinsub(str, str2);
        res = infinAdd(res, unit);
        len1 = my_strlen(str);
    }
    int first_num1 = str[0];
    int first_num2 = str2[0];
    while (first_num1 > first_num2) {
        str = infinsub(str, str2);
        res = infinAdd(res, unit);
        first_num1 = str[0];
    }
    return (res);
}

char *infinMod(char *str, char *str2)
{
    int len = my_strlen(str) + my_strlen(str2) + 1;
    char res[len];
    my_memset(res, '0', len);
    if (str[0] != '-' && str2[0] != '-') {
        str = del_zero(str);
        str2 = del_zero(str2);
        my_revstr(str);
        my_revstr(str2);
        str = the_rest(str, str2, res);
    }
    return (str);
}
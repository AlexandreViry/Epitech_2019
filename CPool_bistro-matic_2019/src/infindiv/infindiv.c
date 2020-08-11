/*
** EPITECH PROJECT, 2019
** infindiv
** File description:
** infinite division
*/

#include "../../include/bistro.h"
#include "../../include/my.h"
#include "../infinadd/include/infinadd.h"
char *substract(char *str, char *str2, char *res)
{
    int len1 = my_strlen(str);
    int len2 = my_strlen(str2);
    char unit[3] = "1";
    while (len1 > len2) {
        str = infinsub(str, str2);
        infinAdd(res, unit);
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

char *neg_test(char *str, char *str2, char *res)
{
    char *result;
    char neg[8] = "-1";
    char neg3[8] = "-1";
    if (str[0] == '-' && str2[0] != '-') {
        infinMul(str, neg);
        result = substract(str, str2, res);
        infinMul(result, neg3);
    }
    if (str2[0] == '-' && str[0] != '-') {
        infinMul(str2, neg);
        result = substract(str, str2, res);
        infinMul(result, neg3);
    }
    if (str[0] == '-' && str2[0] == '-') {
        char neg2[8] = "-1";
        infinMul(str, neg);
        infinMul(str2, neg);
        result = substract(str, str2, res);
    }
    return (result);
}

char *infinDiv(char *str, char *str2)
{
    int len = my_strlen(str) + my_strlen(str2) + 1;
    char res[len];
    my_memset(res, '0', len);
    int len1 = my_strlen(str);
    int len2 = my_strlen(str2);
    len = which_is_longer(len1, len2);
    if (str[0] != '-' && str2[0] != '-') {
        str = del_zero(str);
        str2 = del_zero(str2);
        if (len == len2)
            return (0);
        str = substract(str, str2, res);
    } else if (str[0]= '-' || str2[0] == '-') {
        neg_test(str, str2, res);
    }
    if (res[0] == '0') {
        res[0] = '1';
        res[1] = '\0';
    }
    return (str);
}

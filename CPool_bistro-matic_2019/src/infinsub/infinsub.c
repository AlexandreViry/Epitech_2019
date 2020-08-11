/*
** EPITECH PROJECT, 2019
** infinsub.c
** File description:
** sub
*/

#include "../infinadd/include/infinadd.h"
#include "../../include/bistro.h"
#include "../../include/my.h"
#include <stdio.h>
#include <stdlib.h>
char *if_res_zero(char *str)
{
    int i = 0;
    if (str[i] == '0')
        str = "0";
    return (str);
}

char *sub_for_same(char *str1, char *str2, int size)
{
    int i = 0;
    str1 = my_revstr(str1);
    str2 = my_revstr(str2);
    char *result = malloc(sizeof(char) * size);
    int ret = 0;
    while (str1[i] != '\0') {
        int a = str1[i] - 48;
        int b = str2[i] - 48 + ret;
        ret = 0;
        if (a < b) {
            a = a + 10;
            ret = ret + 1;
        }
        char x = a - b + 48;
        result[i] = x;
        i++;
    }
    result = my_revstr(result);
    return(result);
}

char *same_positive(char *str1, char *str2, int size)
{
    int first_nb1 = str1[0];
    int first_nb2 = str2[0];
    char *neg = "-1";
    char *result;

    if (first_nb1 < first_nb2) {
        result = sub_for_same(str2, str1, size);
        result = my_revstr(result);
        result[size] = '-';
        result[size + 1] = '\0';
        result = my_revstr(result);
        return (result);
    }
    result = sub_for_same(str1, str2, size);
    return (result);
}

char *become_longer(char *str1, char *str2, int size)
{
    str1 = my_revstr(str1);
    str2 = my_revstr(str2);
    int i;
    for (i = size - 1; str2[i] != '\0'; i++) {
        str1[i] = '0';
    }
    str1[i + 2] = '\0';
    str1 = my_revstr(str1);
    str2 = my_revstr(str2);
    return (str1);
}

char *different_size(char *str1, char *str2, int size1, int size2)
{
    int first_nb1 = str1[0];
    int first_nb2 = str2[0];
    int big_size = which_is_longer(size1, size2);
    char *result;
    if (big_size == size2) {
        str1 = become_longer(str1, str2, size2);
    }
    if (big_size == size1) {
        str2 = become_longer(str2, str1, size1);
    }
    if (size2 > size1) {
        result = sub_for_same(str2, str1, big_size);
        result = my_revstr(result);
        result[big_size] = '-';
        result[big_size + 1] = '\0';
        result = my_revstr(result);
        return (result);
    }
    sub_for_same(str1, str2, big_size);
}

char *sub_for_neg(char *str1, char *str2)
{
    int len;
    char neg[8] = "-1";

    infinMul(str1, neg);
    str1 = my_revstr(str1);
    infinAdd(str1, str2);
    str1 = my_revstr(str1);
    len = my_strlen(str1);
    str1[len] = '-';
    str1 = my_revstr(str1);
    return (str1);
}


char *if_neg(char *str1, char *str2, int size1, int size2)
{
    char neg[8] = "-1";
    char *result = malloc((size1 + size2) * sizeof(char));
    if (str2[0] == '-' && str1[0] == '-' && size1 == size2) {
        str2[0] == '0';
        str1[0] == '0';
        str2 = del_zero(str2);
        str1 = del_zero(str1);
        result = sub_for_same(str1, str2, size1);
    }
    if (size1 != size2 && str1[0] == '-' && str2[0] == '-') {
        str2[0] == '0';
        str1[0] == '0';
        str2 = del_zero(str2);
        str1 = del_zero(str1);
        result = different_size(str2, str1, size2, size1);
        result = infinMul(result, neg);
        return (result);
    }
    if (str1[0] == '-' && str2[0] != '-')
        result = sub_for_neg(str1, str2);
    else if  (str2[0] == '-' && str1[0] != '-') {
        str2[0] = '0';
        if (size1 < size2)
            str1 = become_longer(str1, str2, size2);
        if (size1 > size2)
            str2 = become_longer(str2, str1, size1);
        result = infinAdd(str1, str2);
        return(result);
    }
    return (result);
}

char *infinsub(char *str1, char *str2)
{
    str1 = change_zero(str1);
    str2 = change_zero(str2);
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    char *result;

    if (size1 == size2 && str1[0] != '-' && str2[0] != '-')
        result = same_positive(str1, str2, size1);
    if (size1 != size2 && str1[0] != '-' && str2[0] != '-')
        result = different_size(str1, str2, size1, size2);
    if (str2[0] == '-' || str1[0] == '-')
        result = if_neg(str1, str2, size1, size2);
    result = change_zero(result);
    result = if_res_zero(result);
    return (result);
}

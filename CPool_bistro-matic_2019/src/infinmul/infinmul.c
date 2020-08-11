/*
** EPITECH PROJECT, 2019
** infinmul
** File description:
** infinite multiplication
*/

#define ATN(c) (c - '0')
#define NTA(f) (f + '0')
#include "../../include/my.h"
#include "../infinadd/include/infinadd.h"
#include "../../include/bistro.h"
#include "./include/infinmul.h"
char *multiplication(char *str, char *str2, char *res)
{
    int result = 0;
    int dec = 0;
    int j;
    int counter = 0;
    for (int i = 0; str2[i] != '\0'; i++) {
        counter = i;
        for (j = 0; str[j] != '\0'; j++) {
            result = ATN(str2[i]) * ATN(str[j]) + dec + ATN(res[counter]);
            dec = result / 10;
            res[counter] = NTA(result % 10);
            counter = counter + 1;
        }
        if (dec != 0) {
            res[counter] = NTA(dec);
            dec = 0;
        }
    }
    res[counter + 2] = '\0';
    my_revstr(res);
    res = del_zero(res);
    return (res);
}

char *str_is_neg(char *str, char *str2, char *res)
{
    int i = 0;
    if (str[0] == '-' && str2[0] == '-') {
        str = del_zero(str);
        str2 = del_zero(str2);
        my_revstr(str);
        my_revstr(str2);
        res = multiplication(str, str2, res);
    } else if (str[0] == '-') {
        str = del_zero(str);
        str[1] = '0';
        my_revstr(str);
        my_revstr(str2);
        res = multiplication_for_neg(str, str2, res, i);
    } else {
        str2[0] = '0';
        str2 = del_zero(str2);
        my_revstr(str);
        my_revstr(str2);
        res = multiplication_for_neg(str, str2, res, i);
    }
    return (res);
}

char *infinMul(char *str, char *str2)
{
    int len = my_strlen(str) + my_strlen(str2) + 1;
    char res[len];
    my_memset(res, '0', len);
    if (str[0] != '-' && str2[0] != '-') {
        str = del_zero(str);
        str2 = del_zero(str2);
        my_revstr(str);
        my_revstr(str2);
        str = multiplication(str, str2, res);
    } else if (str[0] == '-' || str2[0] == '-') {
        str = str_is_neg(str, str2, res);
        return (str);
    }
    if (str[0] == '0' && str[1] == '0')
        str[1] = '\0';
    return (str);
}

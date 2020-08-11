/*
** EPITECH PROJECT, 2019
** InfinAdd
** File description:
** we make addition
*/

#include "./include/infinadd.h"
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "../../include/bistro.h"
char *change_zero(char *str)
{
    if (str[0] == '0' || str[1] == '0') {
        str = del_zero(str);
    } else {
        return (str);
    }
    return (str);
}

char *direct_add(char *str, char *str2, char *res)
{
    int len;
    int len1;
    int len2;
    len1 = my_strlen(str);
    len2 = my_strlen(str2);
    len = which_is_longer(len1, len2);
    if (len == len1) {
        res = make_add(str, str2, res);
    } else if (len == len2) {
        res = make_add2(str, str2, res);
    } else { 
        res = same_len_add(str, str2, res);
    }
    return (res);
}

char *infinAdd(char *str, char *str2)
{
    int len1;
    int len2;
    int ze;
    len1 = my_strlen(str);
    len2 = my_strlen(str2);
    ze = which_is_longer(len1, len2) + 2;
    char res[ze];
    if (str[0] != '-' && str2[0] != '-') {
        str = del_zero(str);
        str2 = del_zero(str2);
        str = my_revstr(str);
        str2 = my_revstr(str2);
        direct_add(str, str2, res);
        my_strdup(res, str);
    } else if (str[0] == '-' || str2[0] == '-') {
        str = infinsub(str, str2);
        return (str);
    }
    return (str);
}

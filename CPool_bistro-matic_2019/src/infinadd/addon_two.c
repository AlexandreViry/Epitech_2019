/*
** EPITECH PROJECT, 2019
** Infin_Add
** File description:
** the second addon
*/

#define NTA(n) (n + '0')
#define ATN(c)(c - '0')
#include "./include/infinadd.h"
#include "./include/my.h"
char *del_zero(char *str)
{
    int i = 0;
    if (str[0] == '-') {
        i = i + 1;
    }
    if (str[0] == '0' && str[1] == '\0') {
        return (str);
    }
    if (str[0] == '-' && str[1] == '0' && str[2] == '\0') {
        return (str);
    }
    while (str[i] != '\0') {
        if (str[i] != '0') {
            str = my_copy_strn(str, i);
            return (str);
        }
        i = i + 1;
    }
    return (str);
}

char *final_result(char *res, int i, int count)
{
    if (i == 1) {
        res[count] = '1';
        count = count + 1;
        i = 0;
    }        
    res[count] = '\0';
    res = my_revstr(res);
    del_zero(res);
    return(res);
}

char *make_add(char *str1, char *str2, char *res)
{
    int result;
    int dec = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    while (str1[i] != '\0') {
        while (str2[j] != '\0') {
            result = ATN(str1[i]) + ATN(str2[j]) + dec;
            dec = result / 10;
            res[count] = NTA(result % 10);
            count = count + 1;
            j = j + 1;
            i = i + 1;
        }
        result = ATN(str1[i]) + dec;
        dec = result / 10;
        res[count] = NTA(result % 10);
        count = count + 1;
        i = i + 1;
    }
    res = final_result(res, dec, count);
    return (res);
}

char *make_add2(char *str1, char *str2, char *res)
{
    int result;
    int dec = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    while (str2[i] != '\0') {
        while (str1[j] != '\0') {
            result = ATN(str1[j]) + ATN(str2[i]) + dec;
            dec = result / 10;
            res[count] = NTA(result % 10);
            count = count + 1;
            j = j + 1;
            i = i + 1;
        }
        result = ATN(str2[i]) + dec;
        dec = result / 10;
        res[count] = NTA(result % 10);
        count = count + 1;
        i = i + 1;
    }
    res = final_result(res, dec, count);
    return (res);
}

char *same_len_add(char *str1, char *str2, char *res)
{
    int result;
    int dec = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    while (str2[j] != '\0') {
        result = ATN(str1[i]) + ATN(str2[j]) + dec;
        dec = result / 10;
        res[count] = NTA(result % 10);
        count = count + 1;
        j = j + 1;
        i = i + 1;
    }
    res = final_result(res, dec, count);
    return (res);
}

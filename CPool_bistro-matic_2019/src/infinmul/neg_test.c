/*
** EPITECH PROJECT, 2019
** infinmul
** File description:
** infinmul for negatives numbers
*/

#define ATN(c) (c - '0')
#define NTA(f) (f + '0')
#include "../../include/my.h"
#include "../infinadd/include/infinadd.h"
#include "../../include/bistro.h"
char *multiplication_for_neg(char *str, char *str2, char *res, int counter)
{
    int result = 0;
    int dec = 0;
    int j;
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
    res[counter] = '-';
    res[counter + 1] = '\0';
    res = my_revstr(res);
    return (res);
}

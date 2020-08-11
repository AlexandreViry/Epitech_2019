/*
** EPITECH PROJECT, 2019
** my_put_in_seg
** File description:
** we put a segment into an str
*/

#include "./my.h"
char *my_put_in_seg(char *str, char *seg, int a, int b)
{
    int len;
    int rest;
    int i = 0;
    int j = 0;
    rest = b - a;
    len = my_strlen(seg);
    while (i != len) {
        str[a] = seg[j];
        j = j + 1;
        a = a + 1;
        i = i + 1;
    }
    i = a;
    if (a < b) {
        while (a < b) {
            my_copy_str_skip(str, i);
            a = a + 1;
        }
    }
    return (str);
}

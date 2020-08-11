/*
** EPITECH PROJECT, 2019
** main
** File description:
** calcul
*/
#include <stdlib.h>
#include "include/my.h"
int calcul(char **str,int x);
int get_max(char **str,int x);
int get_min(char **str,int x);

char *remplace_string(char **str,int x,int y)
{
    char *str2 = *str;
    char *str3 = *str;
    int z = get_min(&str2,x) + 1;
    int u = get_max(&str2,x);
    char *str4 = malloc(sizeof(char) * y);
    str4 = int_to_string(y);
    int e = 0;
    int f = my_strlen(str4);

    while (str2[z] != '\0') {
        str2[z] = str4[e];
        e++;
        z++;
        if (e == f) {
            e++;
            while (str3[u] != '\0') {
                str2[z] = str2[u];
                z++;
                u++;
            }
            str2[z] = '\0';
            return (str2);
        }
    }
    return (str2);
}

int eval_expr(char *str)
{
    char *str2 = str;
    int results = 0;
    int x = 0;
    char *str3 = malloc(sizeof(char) * my_strlen(str2));
    int y = 0;

    while (str2[x] != '\0') {
        if (str2[x] == '*' || str2[x] == '/' || str2[x] == '%') {
            y = calcul(&str2,x);
            str2 = remplace_string(&str2,x,y);
            x = 0;
        }
        x = x + 1;
    }
    x = 0;
    
    while (str2[x] != '\0') {
        if (str2[x] == '-') {
            y = calcul(&str2,x);
            str2 = remplace_string(&str2,x,y);
            x = 0;
        }
        x = x + 1;
    }
    results = summands(&str2);
    return(results);
}

int main(int ac,char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}

/*                                                                                                                                                                                                                   
** EPITECH PROJECT, 2019                                                                                                                                                                                             
** infin_add                                                                                                                                                                                                         
** File description:                                                                                                                                                                                                 
** add two strings with infinite numbers                                                                                                                                                                             
*/
#include<unistd.h>
#include<stdlib.h>
#define ATN(c) (c - '0')
#define NTA(n) (n + '0')
#include "my.h"

int result1(char *nb1, char *nb2, int x)
{
    int a = 0;
    int i = 0;
    int j = 0;
    int res;
    int c = my_strlen(nb1);
    int d = my_strlen(nb2);
    int stock = 0;
    int v = my_strlen(nb1);
    int k = my_strlen(nb2);
    char *result = malloc(sizeof(char) * c + d);
    
    while (a != x) {
        res = ATN(nb1[i]) + ATN (nb2[j]) + stock;
        stock = 0;
        if (res > 9) {
            res = res % 10;
            stock = 1;
        }
        if (i > c && a != x) {  
            ATN(nb1[i]) == 0;
        }                                                                                                                                                                                                            
        if (j > d && a != x) {           
            ATN(nb2[j]) == 0;                                                                                                                                                                                        
   }                                                                             
        result[a] = NTA(res);   
        a++;
        i++;
        j++;
    }
    my_revstr(result);
    my_putstr(result);
    return (0);
}

int main (int ac, char **av)
{
    int value1 = my_strlen(av[1]);
    int value2 = my_strlen(av[2]);
    if (value1 <= value2) {
        int size = value2;
        
        result1(av[1], av[2], value2);
    }
    else {
        int size = value1;
        result1(av[1], av[2], value1);
    }
    return(0);
}

/*
** EPITECH PROJECT, 2019
** disp_stdarg
** File description:
** display everything
*/

#include "../../include/my.h"
#include <stdarg.h>

void flag3(char *s, int i, va_list list)
{
    switch(s[i]) {
    case 'p':
        my_put_pointer(va_arg(list, int));
        break;
    default:
        my_putchar(s[i - 1]);
        my_putchar(s[i]);
        break;
    }
}

void flag2(char *s, int i, va_list list)
{
    switch(s[i]) {
    case 'X' :
        my_put_hexa(va_arg(list, int));
        break;
    case 'x' :
        my_put_hexa2(va_arg(list, int));
        break;
    case 'o' :
        my_put_octa(va_arg(list, int));
        break;
    case 'b' :
        my_put_binar(va_arg(list, int));
        break;
    default:
        flag3(s, i, list);
        break;
    }
}

void flag(char *s, int i, va_list list)
{
    switch(s[i]) {
    case 's':        
        my_putstr(va_arg(list, char *));
        break;
    case 'i':
        my_put_nbr(va_arg(list, int));
        break;
    case 'd':
        my_put_nbr(va_arg(list, int));
        break;
    default :
        flag2(s, i, list);
        break;
    }
}

void my_printf( char *s, ... )
{
    va_list list;
    va_start(list, s);
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%' && s[i+1] != '%') {
            i++;
            switch(s[i]) {
            case 'c':
                my_putchar(va_arg(list, int));
                break;
            default :
                flag(s, i, list);
                break;
            }
        }
        else 
            my_putchar(s[i]);
        va_end(list);
    }
}

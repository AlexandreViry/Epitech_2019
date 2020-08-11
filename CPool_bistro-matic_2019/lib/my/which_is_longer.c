/*
** EPITECH PROJECT, 2019
** which_is_longer
** File description:
** test which str is longer
*/

#include "./my.h"
int which_is_longer(int nb, int nb1)
{
    if (nb > nb1) {
        return (nb);
    } else if (nb < nb1) {
        return (nb1);
    } else {
        return (0);
    }
}

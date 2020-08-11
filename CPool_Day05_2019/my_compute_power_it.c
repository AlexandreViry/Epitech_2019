/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** iterative function
*/

int my_compute_power_it(int nb , int p) {
    if (p<0) {
        return(0);
        my_putchar('0');
    }
    if (p == 0) {
        return(1);
        my_putchar('1');
    }
    else {
        int x;
        while (p > 1) {
            x  = nb * nb;
            p--;
        }
        my_putchar (x+48);
        return (x);
    }
}

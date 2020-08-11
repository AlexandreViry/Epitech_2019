/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it
** File description:
** day 5 task 1.
*/

int my_compute_factorial_it(int nb)
{
    int y;
    
    if (nb < 0 || nb >= 13) {
        return (0);
    }
    else if (nb == 1 || nb == 0) {
        return (1);
    }
    else {
        for (y=1;nb>1;nb = nb - 1) {
            y = nb*y;
        }
        return (y);
    }
}

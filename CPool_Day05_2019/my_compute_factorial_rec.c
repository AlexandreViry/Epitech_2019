/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec.c
** File description:
** Write a recursive function for number given.
*/

int my_compute_factorial_rec(int nb) {
    if (nb < 0 || nb >= 13) {
        return (0);
    }
    if (nb==0 || nb == 1) {
        return (1);
    }
    else {
        return (nb * my_compute_factorial_rec (nb-1));
    }
}

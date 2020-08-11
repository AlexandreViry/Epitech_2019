/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** displays the lowercase alphabet in ascending order, on a single line.
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    int a;

    a = 97;
    while (a <= 122)
    {
        my_putchar(a);
        a = a + 1;
    }
}

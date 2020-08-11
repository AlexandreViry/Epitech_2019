/*
** EPITECH PROJECT, 2019
** my_put_pointer
** File description:
** display the pointer
*/

void my_putchar(char c);
int  my_put_nbr(int nb);
int my_put_hexa2(int nb);
void my_put_pointer(int nb)
{
    my_put_nbr(0);
    my_putchar('x');
    my_put_hexa2(nb);
}

/*
** EPITECH PROJECT, 2019
** my_print_revalpha.c
** File description:
** Write a function that, beginning withz, displays the lowercase alphabet in descending order, on a single line.
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    int z;
        
    z = 122;       
    while (z >= 97)
        {
            my_putchar(z);
            z = z - 1;
        }
        return(0);
}

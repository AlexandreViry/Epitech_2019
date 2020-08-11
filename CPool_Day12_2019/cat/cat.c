/*
** EPITECH PROJECT, 2019
** cat.c
** File description:
** copy of function cat.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}

void char_error(char c)
{
    write (2, &c, 1);
}
int my_putstror(char const *str)
{
    int i = 0;
    
    while (str[i] != '\0')
    {
        char_error (str[i]);
        i = i + 1;
    }
    return (0);
}
int how_many_char

int main(int ac, char *av[])
{
    int fd;
    int o = 30000;
    char buffer[o];
    int i = 1;
    int size;

    while (i < ac) {
        fd = open(av[i], O_RDONLY);
        if (fd == -1) {
            my_putstror("Error with open\n");
            return (84);
        }
        size = read (fd, buffer, SSIZE_MAX);
        my_putstr(buffer);
        i++;
    }
    return (0);
}

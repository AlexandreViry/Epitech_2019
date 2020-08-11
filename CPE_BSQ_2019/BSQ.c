/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** display the biggest
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int other_case(int nb);
void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar(45);
        nb = nb * -1;
    }
    if  (nb < 10)
        my_putchar(nb + 48);
    else
        other_case(nb);
    return (0);
}

int other_case(int nb)
{
    int c;
    c = nb;
    nb = nb / 10;
    c = c % 10;
    my_put_nbr(nb);
    my_putchar(c + 48);
    return (0);
}

int condition1(char *buff, int * arr, int i)
{
    switch (buff[i]) {
    case 'o':
        arr[i] = 0;
        break;
    case '.':
        arr[i] = 1;
        break;
    case '\n':
        arr[i] = 9999;
        break;
    }
    if (arr[i] != 0 && arr[i] != 9999) {
        if(arr[i] > 0)
            arr[i] = arr[i-1] + 1;
        my_put_nbr(arr[i]);
        return (0);
    }
    my_put_nbr(arr[i]);
    return (0);
}

void bsq(char **filepath)
{
    struct stat sb; 
    int fd = open(filepath[1], O_RDONLY);
    
    stat(filepath[1], &sb);
    char *buff = malloc(sizeof(char) * (int)sb.st_size);
    int *arr = malloc(sizeof(int) * (int)sb.st_size);
    int i = 0;
    
    read(fd, buff, sb.st_size);
    while (buff[i] != '\0') {
        condition1(buff, arr, i);
        i++;
    }
    my_putchar('\n');
    close(fd);
}

int main(int ac, char **av)
{
    (void) ac;
    bsq(av);
    return(0);
}


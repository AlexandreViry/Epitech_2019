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

int map_size(char *buff)
{
    int i = 0;

    while (buff[i] != '\n')
        i++;
    return(i);
}

void bsq(char **filepath)
{
    struct stat sb; 
    int fd = open(filepath[1], O_RDONLY);
    stat(filepath[1], &sb);
    char *buff = malloc(sizeof(char) * (int)sb.st_size);
    int i = 0;
    read(fd, buff, sb.st_size);
    while (buff[i] != '\0') {
        my_putchar(buff[i]);
        i++;
    }
    close(fd);
}

int main(int ac, char **av)
{
    (void) ac;
    bsq(av);
    return(0);
}

/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** read the line you chose
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int counter(void)
{
    static int count = -1;
    count++;
    return count;
}

char *getnextline(int fd)
{
    if (fd < 0)
        return (84);
    int count = counter();
    char *buffer = malloc(sizeof(char) * count);
    while (buffer[count] != '\n') {
        read(fd, buff, count);
        counter();
        count = counter();
        free(buffer);
        char *buffer = malloc(sizeof(char) * count);
    }
    return (buffer);
}
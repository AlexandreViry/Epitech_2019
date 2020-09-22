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
#include <string.h>

char *sub_str(char *str, int *sub)
{
    char *new_str;
    int count = 0;

    new_str = malloc(strlen(str) - *sub + 1);
    for (int tmp = 0; str[tmp] != '\0' &&
             str[tmp] != '\n'; tmp++, count++, *sub++)
        new_str[count] = str[tmp];
    new_str[count + 1] = '\0';
    free(str);
    return new_str;
}

char *getnextline(int fd)
{
    char *buffer;
    char *result;
    static int count = 1;
    static int old_len = 0;

    if (fd < 0)
        return (NULL);
    result = malloc(READ_SIZE + 1);
    buffer = malloc(2);
    for (count = 0; count < READ_SIZE; count++) {
        if (read(fd, buffer, 1) < 0)
            return NULL;
        result[count] = buffer[0];
        if (result[count] == '\0' || result[count] == '\n') {
            result[count] = '\0';
            break;
        }
    }
    free(buffer);
    result[count + 1] = '\0';
    return (result);
}

int main(void)
{
    int fd = open("test.txt", O_RDONLY);

    printf("%s\n", getnextline(fd));
    printf("%s\n", getnextline(fd));
    printf("%s\n", getnextline(fd));
    printf("%s\n", getnextline(fd));
    printf("%s\n", getnextline(fd));
    close(fd);
    return 0;
}

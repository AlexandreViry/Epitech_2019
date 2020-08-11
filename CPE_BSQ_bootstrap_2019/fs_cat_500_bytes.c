/*
** EPITECH PROJECT, 2019
** fs_cat_500_bytes
** File description:
** diplays the first 500 bytes of a file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void fs_cat_500_bytes(char const *filepath)
{
    char *buff[500];
    int fd = open(filepath, O_RDONLY);

    read(fd, buff, 500);
    write(1, buff, 500);
    close(fd);
}

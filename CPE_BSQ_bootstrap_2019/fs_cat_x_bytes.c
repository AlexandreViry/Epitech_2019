
/*
** EPITECH PROJECT, 2019
** fs_cat_x_bytes
** File description:
** displays the first x octets
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void fs_cat_x_bytes(char const *filepath, int x)
{
    char *buff[x + 1];
    int fd = open(filepath, O_RDONLY);
    
    read(fd, buff, x);
    write(1, buff, x);
    close(fd);
}

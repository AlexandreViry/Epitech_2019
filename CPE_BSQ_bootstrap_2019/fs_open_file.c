/*
** EPITECH PROJECT, 2019
** fs_open_files
** File description:
** open and read a file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int my_putstr(char const *str);

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    
    if (fd = -1)
        my_putstr("SUCCESS\n");
    else
        my_putstr("FAILURE\n");
    return (fd);
}

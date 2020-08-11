/*
** EPITECH PROJECT, 2019
** fs_understand_return_of_read 
** File description:
** return a specific message according to the read return
*/

#include <unistd.h>

int my_putstr(char const *str);
void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int result = read(fd, buffer, size);

    if (result = -1)
        my_putstr("read failed\n");
    if (result = 0)
        my_putstr("read has nothing more to read\n");
    if (result < size)
        my_putstr("read didn't complete the entire buffer\n");
    if (result == size)
        my_putstr("read completed the entire buffer");
}

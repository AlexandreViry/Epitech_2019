#include "include/my.h"

int main(int ac, char **av)
{
    if (ac != 3)
        return -1;
    printf("%s\n", infin_div(av[1], av[2]));
    return 0;
}

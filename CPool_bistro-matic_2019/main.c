#include "include/my.h"

int main(int ac, char **av)
{
    /* if (ac != 3) */
    /*     return -1; */
    printf("%s\n", eval_expr(av[1]));
    return 0;
}

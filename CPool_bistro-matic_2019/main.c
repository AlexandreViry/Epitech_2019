#include "include/my.h"

int main(int ac, char **av)
{
    char *tmp = av[1];

    if (ac < 2)
        return -1;
    if (ac > 2)
        tmp = concat_strings(ac, av);
    if (is_valid_string(tmp) == 1)
        return 84;
    printf("%s\n", eval_expr(tmp));
    return 0;
}

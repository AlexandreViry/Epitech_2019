#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    FILE *fd;
    char *tmp;
    struct stat sb;

    stat("inputs/input", &sb);
    if ((tmp = malloc(sb.st_size)) == NULL)
        return -1;
    if ((fd = fopen("inputs/input", "r")) == NULL)
        return -1;
    fgets(tmp, sb.st_size, fd);
    if (ferror(fd))
        return -1;
    if (is_valid_string(tmp) == 1)
        return 84;
    printf("%s\n", eval_expr(tmp));
    return 0;
}

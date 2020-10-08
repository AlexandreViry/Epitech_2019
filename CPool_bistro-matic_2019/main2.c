#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char *tmp;
    struct stat sb;

    stat("inputs/input", &sb);
    if ((tmp = malloc(sb.st_size)) == NULL)
        return -1;
    if ((fd = open("inputs/input", O_RDONLY)) == -1)
        return -1;
    if (read(fd, tmp, sb.st_size) < 0)
        return -1;
    if (is_valid_string(tmp) == 1)
        return 84;
    printf("%s\n", eval_expr(tmp));
    return 0;
}

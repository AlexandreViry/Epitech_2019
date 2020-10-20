#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    FILE *fd;
    char *tmp;
    char *result;
    int res;
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
    result = eval_expr("12+5-3*8-(1+2)/6");
    res = strcmp(result, "-7");
    //@ assert res == 0;
    result = eval_expr("77986/-986%854258*2/55500-1");
    res = strcmp(result, "-1");
    //@ assert res == 0;
    result = eval_expr("12+(((3+4)+(5)))");
    res = strcmp(result, "24");
    //@ assert res == 0;
    result = eval_expr("13%2");
    res = strcmp(result, "1");
    //@ assert res == 0;
    result = eval_expr("500%30");
    res = strcmp(result, "20");
    //@ assert res == 0;
    result = eval_expr("-13%2");
    res = strcmp(result, "-1");
    //@ assert res == 0;
    result = eval_expr("-100/10");
    res = strcmp(result, "-10");
    //@ assert res == 0;
    result = eval_expr("-200/-2");
    res = strcmp(result, "100");
    //@ assert res == 0;
    result = eval_expr("0/5000");
    res = strcmp(result, "0");
    //@ assert res == 0;
    result = eval_expr("9500/5000");
    res = strcmp(result, "1");
    //@ assert res == 0;
    result = eval_expr("95000/531");
    res = strcmp(result, "178");
    //@ assert res == 0;
    result = eval_expr("950*5000");
    res = strcmp(result, "4750000");
    //@ assert res == 0;
    result = eval_expr("-2*-6");
    res = strcmp(result, "12");
    //@ assert res == 0;
    result = eval_expr("-765489*11000653");
    res = strcmp(result, "-8420878864317");
    //@ assert res == 0;
    result = eval_expr("0-0");
    res = strcmp(result, "0");
    //@ assert res == 0;
    result = eval_expr("-950--5000");
    res = strcmp(result, "4050");
    //@ assert res == 0;
    result = eval_expr("-760-900");
    res = strcmp(result, "-1660");
    //@ assert res == 0;
    result = eval_expr("8524-5846");
    res = strcmp(result, "2678");
    //@ assert res == 0;
    result = eval_expr("7854-25");
    res = strcmp(result, "7829");
    //@ assert res == 0;
    result = eval_expr("779865-9865854258*2+55500-1");
    res = strcmp(result, "-19730873152");
    //@ assert res == 0;
    result = eval_expr("779865-9865854258*2+55500-1500+1580000*150284");
    res = strcmp(result, "217717845349");
    //@ assert res == 0;
    result = eval_expr("16+25(36+1*2)+(4+(2*6))(3*3)");
    res = strcmp(result, "1110");
    //@ assert res == 0;
    result = eval_expr("10");
    res = strcmp(result, "10");
    //@ assert res == 0;
    result = eval_expr("-17*8(15-3)");
    res = strcmp(result, "-1632");
    //@ assert res == 0;
    return 0;
}

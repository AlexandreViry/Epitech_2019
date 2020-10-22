#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    FILE *fd;
    char *tmp = malloc(300);
    char *result;
    int res;
    struct stat sb;

    //manual tests

    strcpy(tmp, "12+5-3*8-(1+2)/6");
    result = eval_expr(tmp);
    res = strcmp(result, "-7");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "77986/-986%854258*2/55500-1");
    result = eval_expr(tmp);
    res = strcmp(result, "-1");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "12+(((3+4)+(5)))");
    result = eval_expr(tmp);
    res = strcmp(result, "24");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "13%2");
    result = eval_expr(tmp);
    res = strcmp(result, "1");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "500%30");
    result = eval_expr(tmp);
    res = strcmp(result, "20");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "-13%2");
    result = eval_expr(tmp);
    res = strcmp(result, "-1");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "-100/10");
    result = eval_expr(tmp);
    res = strcmp(result, "-10");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "-200/-2");
    result = eval_expr(tmp);
    res = strcmp(result, "100");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "0/5000");
    result = eval_expr(tmp);
    res = strcmp(result, "0");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "9500/5000");
    result = eval_expr(tmp);
    res = strcmp(result, "1");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "95000/531");
    result = eval_expr(tmp);
    res = strcmp(result, "178");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "950*5000");
    result = eval_expr(tmp);
    res = strcmp(result, "4750000");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "-2*-6");
    result = eval_expr(tmp);
    res = strcmp(result, "12");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "-765489*11000653");
    result = eval_expr(tmp);
    res = strcmp(result, "-8420878864317");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "-0-0");
    result = eval_expr(tmp);
    res = strcmp(result, "0");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "-950--5000");
    result = eval_expr(tmp);
    res = strcmp(result, "4050");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "-760-900");
    result = eval_expr(tmp);
    res = strcmp(result, "-1660");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "8524-5846");
    result = eval_expr(tmp);
    res = strcmp(result, "2678");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "7854-25");
    result = eval_expr(tmp);
    res = strcmp(result, "7829");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "779865-9865854258*2+55500-1");
    result = eval_expr(tmp);
    res = strcmp(result, "-19730873152");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "779865-9865854258*2+55500-1500+1580000*150284");
    result = eval_expr(tmp);
    res = strcmp(result, "217717845349");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "16+25(36+1*2)+(4+(2*6))(3*3)");
    result = eval_expr(tmp);
    res = strcmp(result, "1110");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "10");
    result = eval_expr(tmp);
    res = strcmp(result, "10");
    //@ assert res == 0;
    memset(tmp, 0, 300);
    strcpy(tmp, "-17*8(15-3)");
    result = eval_expr(tmp);
    res = strcmp(result, "-1632");
    //@ assert res == 0;
    free(tmp);

    //fuzzer test

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

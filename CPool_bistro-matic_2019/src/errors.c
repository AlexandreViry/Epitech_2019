#include "../include/my.h"

void malloc_error_message(char *function)
{
    dprintf(2, "Error: memory allocation failed in function: %s.\n", function);
    exit(-1);
}

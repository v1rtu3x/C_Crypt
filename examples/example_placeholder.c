#include <stdio.h>

#include "c_crypt/errors.h"

int main(void)
{
    printf("c_crypt example placeholder\n");
    printf("library error string example: %s\n", c_err_string(C_ERR_OK));

    return 0;
}
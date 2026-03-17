// src/core/memory.c

#include <stddef.h>
#include "../../include/c_crypt/memory.h"

void c_memzero(void *ptr, size_t len){
    volatile unsigned char *p = (volatile unsigned char *)ptr;

    while (len-- > 0){
        *p++ = 0U;
    }
}

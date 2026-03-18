// src/core/memory.c

#include <stddef.h>
#include "../../include/c_crypt/memory.h"

void c_secure_zero(void *ptr, size_t len){
    volatile unsigned char *p;
    
    if(ptr == NULL){
        if(len == 0U){
            return;
        }
        return;
    }

    p = (volatile unsigned char *)ptr;

    while(len-- > 0){
        *p++ = 0;
    }
}

void c_memzero(void *ptr, size_t len){
    c_secure_zero(ptr, len);
}



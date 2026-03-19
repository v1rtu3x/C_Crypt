#include <stddef.h>

#include "c_crypt/memory.h"

int c_memcmp_consttime(const void *a, const void *b, size_t len){
    const volatile unsigned char *pa;
    const volatile unsigned char *pb;
    unsigned char diff = 0;
    size_t i;

    if (len == 0){
        return 0;
    }

    if ((a == NULL) || (b == NULL)){
        return -1;
    }

    pa = (const volatile unsigned char *)a;
    pb = (const volatile unsigned char *)b;

    for (i = 0; i < len; i++){
        diff |= (unsigned char)(pa[i] ^ pb[i]);
    }

    return (int)diff;
}
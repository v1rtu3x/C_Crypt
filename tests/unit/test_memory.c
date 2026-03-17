#include <stddef.h>
#include <stdint.h>
#include "../../include/c_crypt/memory.h"

int c_test_memory_placeholder(void){
    uint8_t buf[8];
    size_t i;

    for(i = 0; i < sizeof(buf); i++){
        buf[i] = 0xAAU;
    }

    c_memzero(buf, sizeof(buf));

    for(i = 0; i < sizeof(buf); i++){
        if(buf[i] != 0U){
            return -1;
        }
    }

    return 0;
}

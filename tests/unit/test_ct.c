#include <stddef.h>
#include <stdint.h>

#include "c_crypt/memory.h"
#include "test.h"

int c_test_ct_equal(void){
    static const uint8_t a[] = {0x01, 0x02, 0x03, 0x04};
    static const uint8_t b[] = {0x01, 0x02, 0x03, 0x04};
    
    return (c_memcmp_consttime(a, b, sizeof(a)) == 0) ? 0 : 1;
}

int c_test_ct_diff_start(void){
    static const uint8_t a[] = {0x01, 0x02, 0x03, 0x04};
    static const uint8_t b[] = {0xFF, 0x02, 0x03, 0x04};
    
    return (c_memcmp_consttime(a, b, sizeof(a)) != 0) ? 0 : 1;
}

int c_test_ct_diff_middle(void){
    static const uint8_t a[] = {0x01, 0x02, 0xFF, 0x04};
    static const uint8_t b[] = {0x01, 0x02, 0x03, 0x04};
    
    return (c_memcmp_consttime(a, b, sizeof(a)) != 0) ? 0 : 1;
}

int c_test_ct_diff_end(void){
    static const uint8_t a[] = {0x01, 0x02, 0x03, 0xFF};
    static const uint8_t b[] = {0x01, 0x02, 0x03, 0x04};
    
    return (c_memcmp_consttime(a, b, sizeof(a)) != 0) ? 0 : 1;
}

int c_test_ct_empty(void){
    return ((c_memcmp_consttime(NULL, NULL, 0U) == 0) ? 0 : 1);
}

int c_test_ct_single_byte_equal(void){
    static const uint8_t a[] = {0x05};
    static const uint8_t b[] = {0x05};

    return (c_memcmp_consttime(a, b, 1U) == 0) ? 0 : 1;
}

int c_test_ct_single_byte_diff(void){
    static const uint8_t a[] = {0xFF};
    static const uint8_t b[] = {0x05};

    return (c_memcmp_consttime(a, b, 1U) != 0) ? 0 : 1;
}
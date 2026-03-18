#include <stdio.h>
#include <stdlib.h>
#include "test.h"

typedef int (*c_test_fn_t)(void);
typedef struct{
    const char *name;
    c_test_fn_t fn;
}c_test_case_t;

static const c_test_case_t  g_tests[] = {
    {"test_memory_placeholder", c_test_memory_placeholder},
    {"test_memory_small_buffer", c_test_memory_small_buffer},
    {"test_memory_large_buffer", c_test_memory_large_buffer},
    {"test_memory_null_zero_len", c_test_memory_null_zero_len},
    {"test_endian", c_test_endian},
    {"test_endian_unaligned", c_test_endian_unaligned},
};


int main(void)
{
    size_t i;
    size_t passed = 0;
    size_t failed = 0;
    const size_t total = sizeof(g_tests) / sizeof(g_tests[0]);

    printf("c_crypt test runner\n");
    printf("===================\n");

    for(i = 0; i < total; i++){
        const int rc = g_tests[i].fn();

        if(rc == 0){
            ++passed;
            printf("[PASS] %s\n", g_tests[i].name);
        }
        else{
            ++failed;
            printf("[FAIL] %s\n", g_tests[i].name);
        }
    }

    printf("\n");
    printf("Summary: total=%zu passed=%zu failed=%zu\n", total, passed, failed);

    if(failed != 0U){
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

#include <stddef.h>
#include <stdint.h>

#include "c_crypt/errors.h"
#include "core/buf.h"
#include "test.h"

int c_test_buf_add_no_overflow(void){
    size_t out = 0U;

    if (c_internal_size_add_overflow(10U, 20U, &out) != 0){
        return 1;
    }

    return (out == 30) ? 0 : 1;
}

int c_test_buf_add_overflow(void){
    size_t out = 0U;
    return (c_internal_size_add_overflow((size_t)-1, 1U, &out) != 0) ? 0 : 1;
}

int c_test_buf_mul_no_overflow(void){
    size_t out = 0U;

    if(c_internal_size_mul_overflow(8U, 16U, &out) != 0){
        return 1;
    }

    return (out == 128U) ? 0 : 1;
}

int c_test_buf_mul_overflow(void){
    size_t out = 0U;
    return (c_internal_size_add_overflow((size_t)-1, 2U, &out)) ? 0 : 1;
}

int c_test_buf_validate_read_ok(void){
    const uint8_t data[] = {0U, 1U, 2U, 3U};
    return (c_internal_validate_read_buffer(data, sizeof(data)) == C_ERR_OK) ? 0 : 1;
}

int c_test_buf_validate_read_null_zero(void){
    return (c_internal_validate_read_buffer(NULL, 0U) == C_ERR_OK) ? 0 : 1;
}

int c_test_buf_validate_read_null_nonzero(void){
    return (c_internal_validate_read_buffer(NULL, 8U) == C_ERR_NULL_POINTER) ? 0 : 1;
}

int c_test_buf_validate_write_ok(void)
{
    uint8_t data[4] = { 0U, 1U, 2U, 3U };

    return (c_internal_validate_write_buffer(data, sizeof(data)) == C_ERR_OK) ? 0 : 1;
}

int c_test_buf_validate_write_null_zero(void)
{
    return (c_internal_validate_write_buffer(NULL, 0U) == C_ERR_OK) ? 0 : 1;
}

int c_test_buf_validate_write_null_nonzero(void)
{
    return (c_internal_validate_write_buffer(NULL, 8U) == C_ERR_NULL_POINTER) ? 0 : 1;
}

int c_test_buf_validate_out_capacity_ok(void)
{
    uint8_t out[16];
    size_t out_len = sizeof(out);

    return (c_internal_validate_out_capacity(out, &out_len, 8U) == C_ERR_OK) ? 0 : 1;
}

int c_test_buf_validate_out_capacity_small(void)
{
    uint8_t out[4];
    size_t out_len = sizeof(out);

    if (c_internal_validate_out_capacity(out, &out_len, 8U) != C_ERR_BUFFER_TOO_SMALL)
    {
        return 1;
    }

    return (out_len == 8U) ? 0 : 1;
}

int c_test_buf_validate_out_capacity_null_len(void)
{
    uint8_t out[4];

    return (c_internal_validate_out_capacity(out, NULL, 4U) == C_ERR_NULL_POINTER) ? 0 : 1;
}

int c_test_buf_validate_out_capacity_null_out_zero(void)
{
    size_t out_len = 0U;

    return (c_internal_validate_out_capacity(NULL, &out_len, 0U) == C_ERR_OK) ? 0 : 1;
}

int c_test_buf_validate_out_capacity_null_out_nonzero(void)
{
    size_t out_len = 4U;

    if (c_internal_validate_out_capacity(NULL, &out_len, 8U) != C_ERR_NULL_POINTER)
    {
        return 1;
    }

    return (out_len == 8U) ? 0 : 1;
}




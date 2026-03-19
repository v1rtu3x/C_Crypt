#include "core/buf.h"

int c_internal_size_add_overflow(size_t a, size_t b, size_t *out){
    if(out == NULL){
        return 1;
    }

    if(a > ((size_t)-1 - b)){
        return 1;
    }

    *out = a + b;
    return 0;
}

int c_internal_size_mul_overflow(size_t a, size_t b, size_t *out){
    if(out == NULL){
        return 1;
    }

    if((a != 0U) && (b > ((size_t)-1 / a))){
        return 1;
    }

    *out = a * b;
    return 0;
}

c_err_e c_internal_validate_read_buffer(const void *ptr, size_t len){
    if((ptr == NULL) && len > 0U){
        return C_ERR_NULL_POINTER;
    }
    return C_ERR_OK;
}

c_err_e c_internal_validate_write_buffer(const void *ptr, size_t len)
{
    if ((ptr == NULL) && (len > 0U))
    {
        return C_ERR_NULL_POINTER;
    }

    return C_ERR_OK;
}


c_err_e c_internal_validate_out_capacity(void *out, size_t *out_len, size_t required_len){
    if (out_len == NULL)
    {
        return C_ERR_NULL_POINTER;
    }

    if ((out == NULL) && (required_len > 0U))
    {
        *out_len = required_len;
        return C_ERR_NULL_POINTER;
    }

    if (*out_len < required_len)
    {
        *out_len = required_len;
        return C_ERR_BUFFER_TOO_SMALL;
    }

    return C_ERR_OK;
}

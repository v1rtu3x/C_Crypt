#ifndef C_INTERNAL_BUF_H
#define C_INTERNAL_BUF_H

#include <stddef.h>

#include "c_crypt/errors.h"

int c_internal_size_add_overflow(size_t a, size_t b, size_t *out);
int c_internal_size_mul_overflow(size_t a, size_t b, size_t *out);
c_err_e c_internal_validate_read_buffer(const void *ptr, size_t len);
c_err_e c_internal_validate_write_buffer(const void *ptr, size_t len);
c_err_e c_internal_validate_out_capacity(void *out, size_t *out_len, size_t required_len);

#endif 

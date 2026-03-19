
#ifndef C_INTERNAL_CT_H
#define C_INTERNAL_CT_H

#include "c_crypt/types.h"

static inline c_byte_t c_internal_diff_mask_u8(c_byte_t a, c_byte_t b){
    return (c_byte_t)(a ^ b);
}

#endif // C_INTERNAL_CT_H
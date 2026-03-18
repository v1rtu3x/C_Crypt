#ifndef C_INTERNAL_ENDIAN_H
#define C_INTERNAL_ENDIAN_H

#include "c_crypt/types.h"

static inline c_u16_t c_internal_load16_be(const c_byte_t in[2]) {
    return (c_u16_t)((c_u16_t)in[0] << 8) | (c_u16_t)in[1];
}

static inline c_u16_t c_internal_load16_le(const c_byte_t in[2]) {
    return (c_u16_t)((c_u16_t)in[1] << 8) | (c_u16_t)in[0];
}

static inline c_u32_t c_internal_load32_be(const c_byte_t in[4]){
    return (c_u32_t)(((c_u32_t)in[0] << 24) |
                     ((c_u32_t)in[1] << 16) |
                     ((c_u32_t)in[2] << 8) | 
                     (c_u32_t)in[3]);
}

static inline c_u32_t c_internal_load32_le(const c_byte_t in[4]){
    return (c_u32_t)(((c_u32_t)in[3] << 24) | 
                     ((c_u32_t)in[2] << 16) |
                     ((c_u32_t)in[1] << 8) | 
                     (c_u32_t)in[0]);
}

static inline c_u64_t c_internal_load64_be(const c_byte_t in[8]){
    return (c_u64_t)((((c_u64_t)in[0] << 56))|
                     (((c_u64_t)in[1] << 48))|
                     (((c_u64_t)in[2] << 40))|
                     (((c_u64_t)in[3] << 32))|
                     (((c_u64_t)in[4] << 24))|
                     (((c_u64_t)in[5] << 16))|
                     (((c_u64_t)in[6] << 8))| 
                     (c_u64_t)in[7]);
}

static inline c_u64_t c_internal_load64_le(const c_byte_t in[8]){
    return (c_u64_t)((((c_u64_t)in[7] << 56))|
                     (((c_u64_t)in[6] << 48))|
                     (((c_u64_t)in[5] << 40))|
                     (((c_u64_t)in[4] << 32))|
                     (((c_u64_t)in[3] << 24))|
                     (((c_u64_t)in[2] << 16))|
                     (((c_u64_t)in[1] << 8))| 
                     (c_u64_t)in[0]);
}

static inline void c_internal_store_be(c_byte_t out[2], c_u16_t val){
    out[0] = (c_byte_t)((val >> 8) & 0xFFu);
    out[1] = (c_byte_t)(val & 0xFFu);
}

static inline void c_internal_store16_le(c_byte_t out[2], c_u16_t val){
    out[0] = (c_byte_t)(val & 0xFFu);
    out[1] = (c_byte_t)((val >> 8) & 0xFFu);
}

static inline void c_internal_store32_be(c_byte_t out[4], c_u32_t val){
    out[0] = (c_byte_t)((val >> 24) & 0xFFu);
    out[1] = (c_byte_t)((val >> 16) & 0xFFu);
    out[2] = (c_byte_t)((val >> 8) & 0xFFu);
    out[3] = (c_byte_t)(val & 0xFFu);
}

static inline void c_internal_store32_le(c_byte_t out[4], c_u32_t val){
    out[0] = (c_byte_t)(val & 0xFFu);
    out[1] = (c_byte_t)((val >> 8) & 0xFFu);
    out[2] = (c_byte_t)((val >> 16) & 0xFFu);
    out[3] = (c_byte_t)((val >> 24) & 0xFFu);
}

static inline void c_internal_store64_be(c_byte_t out[8], c_u64_t val){
    out[0] = (c_byte_t)((val >> 56) & 0xFFu);
    out[1] = (c_byte_t)((val >> 48) & 0xFFu);
    out[2] = (c_byte_t)((val >> 40) & 0xFFu);
    out[3] = (c_byte_t)((val >> 32) & 0xFFu);
    out[4] = (c_byte_t)((val >> 24) & 0xFFu);
    out[5] = (c_byte_t)((val >> 16) & 0xFFu);
    out[6] = (c_byte_t)((val >> 8) & 0xFFu);
    out[7] = (c_byte_t)(val & 0xFFu);
}

static inline void c_internal_store64_le(c_byte_t out[8], c_u64_t val){
    out[0] = (c_byte_t)(val & 0xFFu);
    out[1] = (c_byte_t)((val >> 8) & 0xFFu);
    out[2] = (c_byte_t)((val >> 16) & 0xFFu);
    out[3] = (c_byte_t)((val >> 24) & 0xFFu);
    out[4] = (c_byte_t)((val >> 32) & 0xFFu);
    out[5] = (c_byte_t)((val >> 40) & 0xFFu);
    out[6] = (c_byte_t)((val >> 48) & 0xFFu);
    out[7] = (c_byte_t)((val >> 56) & 0xFFu);
}

#endif

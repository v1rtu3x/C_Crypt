#include "c_crypt/types.h"
#include "../../src/core/endian.h"

int c_test_endian(void){

    c_byte_t buf[8];
    c_u16_t val16 = 0x1234;
    c_u32_t val32 = 0x12345678;
    c_u64_t val64 = 0x1234567890ABCDEF;

    c_internal_store_be(buf, val16);
    if(c_internal_load16_be(buf) != val16){
        return 1;
    }

    c_internal_store16_le(buf, val16);
    if(c_internal_load16_le(buf) != val16){
        return 1;
    }

    c_internal_store32_be(buf, val32);
    if(c_internal_load32_be(buf) != val32){
        return 1;
    }

    c_internal_store32_le(buf, val32);
    if(c_internal_load32_le(buf) != val32){
        return 1;
    }

    c_internal_store64_be(buf, val64);
    if(c_internal_load64_be(buf) != val64){
        return 1;
    }

    c_internal_store64_le(buf, val64);
    if(c_internal_load64_le(buf) != val64){
        return 1;
    }

    return 0;
}

int c_test_endian_unaligned(void){
    c_byte_t raw[9];
    c_byte_t *buf = &raw[1];
    c_u32_t v32 = 0xA1B2C3D4;
    c_u64_t v64 = 0x1122334455667788;

    c_internal_store32_be(buf, v32);
    if(c_internal_load32_be(buf) != v32){
        return 1;
    }
    
    c_internal_store64_be(buf, v64);
    if(c_internal_load64_be(buf) != v64){
        return 1;
    }

    return 0;
}

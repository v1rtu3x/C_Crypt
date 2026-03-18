// include/c_crypt/memory.h

#ifndef C_MEMORY_H
#define C_MEMORY_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void c_secure_zero(void *ptr, size_t len);
void c_memzero(void *ptr, size_t len);

#ifdef __cplusplus
}
#endif

#endif // C_MEMORY_H
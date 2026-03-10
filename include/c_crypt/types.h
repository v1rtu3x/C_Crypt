// include/c_crypt/types.h

/*# Portable Integer Usage Rules (`types.h`)

The file `types.h` defines the standard integer types and basic type conventions used across the **C_Crypt** library.  
Its purpose is to ensure **portability, consistency, and correctness** across different compilers and architectures.

All modules must include this header when using integer types or core library type definitions.*/

#ifndef C_TYPES_H
#define C_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>

#if !defined(UINT8_MAX) || !defined(UINT32_MAX) || !defined(UINT64_MAX)
#error "C_Crypt requires <stdint.h> fixed-width unsigned integer types."
#endif


typedef uint8_t c_byte_t; //Byte type used for buffers, keys nonces and other kind of raw binary i/o
typedef uint32_t c_u32_t; //Unsigned 32-bit integer type used state words 
typedef uint64_t c_u64_t; //Unsigned 64-bit integer type used for state words, counters and large lenght tracking

//signed variants are used for non-cryptographic control logic

typedef int32_t c_i32_t;
typedef int64_t c_i64_t;

typedef bool c_bool_t; //Boolean type for logical validation and states

#ifndef C_NULL
#define C_NULL ((void*)0)
#endif

// Safe Array helper

#define C_ARRAY_LEN(x) (sizeof(x) / sizeof((x)[0]))

// unused parameters or variables

#define C_UNUSED(x) ((void)(x))

// C_Crypt assumes 8-bit bytes, availability of uint8_t, uint32_t and uint64_t types, and a conforming standard library

#if CHAR_BIT != 8
#error "C_Crypt requires 8-bit bytes. This platform is not supported."
#endif

#endif // C_TYPES_H
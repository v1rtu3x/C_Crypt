// include/c_crypt/errors.h

/*
 * Error definitions for the C_Crypt library.
 *
 * All public functions return a value of type `c_err_e`.
 *
 * Convention:
 *     C_ERR_OK == success
 *     any other value indicates an error
 *
 * Errors are grouped by category so the enum can grow without
 * breaking the API.
 */


#ifndef C_ERRORS_H
#define C_ERRORS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum{

    C_ERR_OK = 0,

    C_ERR_UNKNOWN,
    C_ERR_NOT_IMPLEMENTED,
    C_ERR_INTERNAL,

    C_ERR_NULL_POINTER,
    C_ERR_INVALID_ARGUMENT,
    C_ERR_INVALID_LENGTH,
    C_ERR_INVALID_STATE,

    C_ERR_OUT_OF_MEMORY,
    C_ERR_BUFFER_TOO_SMALL,
    C_ERR_OVERFLOW,

    C_ERR_INVALID_KEY,
    C_ERR_INVALID_NONCE,
    C_ERR_INVALID_TAG,
    C_ERR_INVALID_SIGNATURE,
    C_ERR_INVALID_PADDING,

    C_ERR_INVALID_FORMAT,
    C_ERR_PARSE_ERROR,
    C_ERR_UNSUPPORTED_FORMAT,

    C_ERR_RNG_FAILURE,
    C_ERR_ENTROPY_SOURCE_FAILURE,

}c_err_e;

const char *c_err_string(c_err_e err);

#ifdef __cplusplus
}
#endif

#endif // C_ERRORS_H


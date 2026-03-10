// src/core/errors.c

#include "../../include/c_crypt/errors.h"

const char *c_err_string(c_err_e err) {
    switch (err) {
        case C_ERR_OK: return "No error";

        case C_ERR_UKNOWN: return "Unknown error";
        case C_ERR_NOT_IMPLEMENTED: return "Not implemented";
        case C_ERR_INTERNAL: return "Internal error";

        case C_ERR_NULL_POINTER: return "Null pointer";
        case C_ERR_INVALID_ARGUMENT: return "Invalid argument";
        case C_ERR_INVALID_LENGTH: return "Invalid length";
        case C_ERR_INVALID_STATE: return "Invalid state";

        case C_ERR_OUT_OF_MEMORY: return "Out of memory";
        case C_ERR_BUFFER_TOO_SMALL: return "Buffer too small";
        case C_ERR_OVERFLOW: return "Overflow";

        case C_ERR_INVALID_KEY: return "Invalid key";
        case C_ERR_INVALID_NONCE: return "Invalid nonce";
        case C_ERR_INVALID_TAG: return "Invalid tag";
        case C_ERR_INVALID_SIGNATURE: return "Invalid signature";
        case C_ERR_INVALID_PADDING: return "Invalid padding";

        case C_ERR_INVALID_FORMAT: return "Invalid format";
        case C_ERR_PARSE_ERROR: return "Parse error";
        case C_ERR_UNSUPORTED_FORMAT: return "Unsupported format";

        case C_ERR_RNG_FAILURE: return "RNG failure";
        case C_ERR_ENTROPY_FAILED: return "Entropy failed";
        default: return "Unknown error code";
    }
}
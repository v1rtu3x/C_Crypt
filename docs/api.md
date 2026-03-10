# Public API Foundation

This document defines the naming conventions and symbol rules used throughout the **C_Crypt** library.  
The goal is to ensure the codebase remains **consistent, readable, and predictable**, while clearly separating **public API symbols** from **internal implementation details**.

---

# Library Prefix

All public symbols in the library must use the prefix:
`c_`


This prefix ensures:

- avoidance of symbol collisions with other libraries
- clear identification of symbols belonging to **C_Crypt**
- consistent API design

Examples:

```
c_sha256_init
c_sha256_update
c_sha256_final
c_aes256_encrypt_block
c_chacha20_stream
```


# Naming Conventions

The library follows **snake_case** naming for all functions and variables.

Naming patterns depend on the type of symbol.

---

# Public Functions

Public API functions must follow the format:

`c_module_operation`

Where:

- `module` identifies the algorithm or subsystem
- `operation` describes the action performed

Examples:

```
c_sha256_init
c_sha256_update
c_sha256_final

c_aes_encrypt_block
c_aes_decrypt_block

c_hkdf_sha256

c_ed25519_sign
c_ed25519_verify
```


## Guidelines:

- use **verb-oriented naming**
- keep function names concise
- avoid abbreviations unless widely understood
- maintain consistent parameter ordering across modules

---

# Internal Functions

Internal functions must not be exposed through public headers.

They use the prefix:
`c_internal`
`c_internal_<module>_<operation>`

Examples:
```
c_internal_sha256_transform
c_internal_aes_key_expand
c_internal_bigint_mul_word
```

## Guidelines:

- internal symbols should never appear in installed headers
- internal helpers should remain within their module
- avoid exposing internal APIs across unrelated modules
---

# Structs

Public struct types follow the format:
`c_<module>_<name>_t`

Examples:
```
c_sha256_ctx_t
c_aes_key_t
c_rng_state_t
```

## Guidelines:

- `_ctx_t` suffix should be used for algorithm contexts
- `_key_t` suffix should be used for key structures
- `_state_t` for persistent state structures

Examples:

```
c_sha256_ctx_t
c_chacha20_ctx_t
c_aes_key_t
```

Internal structs use:

`c_internal_<module>_<name>_t`

Example:

`c_internal_bigint_wordvec_t`


---

# Enums

Enum types use the suffix:
`_e`
Format:
`c_<name>_e`
Examples:
```
c_err_e
c_cipher_mode_e
```

Enum values use uppercase constants:

`C_<CATEGORY>_<VALUE>`

Examples:

```
C_ERR_OK
C_ERR_BAD_ARG
C_ERR_INVALID_KEY
C_ERR_INVALID_FORMAT
```

Example enum:

```c
typedef enum
{
    C_ERR_OK = 0,
    C_ERR_BAD_ARG,
    C_ERR_INVALID_KEY,
    C_ERR_INTERNAL
} c_err_e;
```

# Macros

Public macros must use uppercase names with the prefix:

`C_`
Format:

`C_<MODULE>_<NAME>`

Examples:
```
C_SHA256_BLOCK_SIZE
C_SHA256_DIGEST_SIZE
C_AES_BLOCK_SIZE
C_VERSION_MAJOR
```

## Guidelines:

- macros should only be used for compile-time constants
- prefer static const for internal constants
- avoid function-like macros when possible

# Constants

Constants follow two different conventions depending on visibility.

# 1. Public constants

Public compile-time constants should be defined as macros:

`C_<MODULE>_<NAME>`

Examples:
```
C_SHA256_BLOCK_SIZE
C_SHA256_DIGEST_SIZE
C_AES_BLOCK_SIZE
```

# 2.Internal constants

Internal constants should use static const variables:

`c_internal_<module>_<name>`

Examples:

`static const uint32_t c_internal_sha256_k[64];`

## Guidelines:

- avoid exposing large constant tables in public headers
- keep algorithm constants private to their module


# Naming Summary

| Symbol Type       | Format                            | Example                       |
| ----------------- | --------------------------------- | ----------------------------- |
| Public function   | `c_<module>_<operation>`          | `c_sha256_update`             |
| Internal function | `c_internal_<module>_<operation>` | `c_internal_sha256_transform` |
| Public struct     | `c_<module>_<name>_t`             | `c_sha256_ctx_t`              |
| Internal struct   | `c_internal_<module>_<name>_t`    | `c_internal_bigint_wordvec_t` |
| Enum type         | `c_<name>_e`                      | `c_err_e`                     |
| Enum values       | `C_<CATEGORY>_<VALUE>`            | `C_ERR_BAD_ARG`               |
| Public macro      | `C_<MODULE>_<NAME>`               | `C_SHA256_DIGEST_SIZE`        |
| Internal constant | `c_internal_<module>_<name>`      | `c_internal_sha256_k`         |

# General Rules

- All public symbols must begin with c_
- All internal symbols must begin with c_internal_
- All macros must begin with C_
- All identifiers use snake_case
- Enum values use UPPERCASE_SNAKE_CASE
- Public headers must expose only the stable API
- Internal headers must never be installed or exported

# Future Extensions

As the library grows, additional conventions may be defined for:

- module naming rules
- error handling patterns
- context lifecycle (init, update, final)
- serialization and parsing APIs
- memory ownership conventions
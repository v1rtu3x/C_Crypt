# Architecture

## Overview

C_Crypt is a modular, layered cryptographic library written in C, designed for:

- clarity
- correctness
- portability
- auditability

The architecture separates **low-level primitives** from **high-level constructions**, ensuring flexibility and correctness.

---

## Layered Design

The library is structured in layers:

### 1. Core Layer

Located in: `src/core`

Responsibilities:

- error handling
- memory utilities
- constant-time helpers
- buffer handling
- RNG abstraction
- endian utilities

This layer is dependency-free and used by all other modules.

---

### 2. Primitive Layer

Located in:

``` txt
src/hash/
src/cipher/
src/mac/
```

Includes:

- hash functions (SHA-2, SHA-3, BLAKE2)
- block ciphers (AES, Camellia, Twofish)
- stream ciphers (ChaCha20, XChaCha20)
- MAC primitives (HMAC, Poly1305, CMAC)

Properties:

- deterministic
- stateless or context-based
- no protocol logic

---

### 3. Construction Layer

Located in:

``` txt
src/aead/
src/mode/
src/kdf/
```

- AEAD modes (AES-GCM, ChaCha20-Poly1305)
- block cipher modes (CBC, CTR, XTS)
- key derivation (HKDF, PBKDF2, Argon2)

Properties:

- built from primitives
- enforce correct usage patterns
- handle nonces, IVs, tags

---

### 4. Public Key Layer

Located in:

``` txt
src/pk/
src/bigint/
```

Includes:

- RSA
- ECC (P-256, Ed25519, X25519)
- big integer arithmetic

---

### 5. Encoding / Parsing Layer

Located in: `src/encoding`

Includes:

- Base64
- PEM
- ASN.1 DER
- key formats (PKCS#8, SPKI)

---

## Design Principles

### Separation of Concerns

- primitives do not know about protocols
- constructions do not reimplement primitives
- encoding is separate from cryptography

---

### Minimal Dependencies

- no external crypto libraries
- only standard C library
- optional OS-specific RNG backend

---

### Constant-Time First

- sensitive operations must be constant-time
- comparisons must use constant-time functions
- no secret-dependent branches

---

### Testability

- each module is independently testable
- deterministic functions are preferred

---

## Data Flow Example

Example: AES-GCM encryption

``` txt
plaintext
↓
AES (block cipher)
↓
CTR mode (keystream)
↓
GHASH (authentication)
↓
ciphertext + tag
```

---

## Future Evolution

- SIMD optimizations
- hardware acceleration (AES-NI, NEON)
- pluggable RNG backends
- streaming APIs

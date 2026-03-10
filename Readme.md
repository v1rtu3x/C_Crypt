# C_Crypt

A complete lightweight cryptographic library written in C.

## Scope

C_Crypt aims to provide a clean, modular, and portable cryptographic library implemented in C, with a strong focus on correctness, testability, and practical API design.

The project covers the main areas of modern applied cryptography:

- cryptographic hash functions
- message authentication codes
- symmetric encryption
- authenticated encryption
- key derivation and password hashing
- encoding and key serialization
- public-key cryptography
- cryptographic random number generation
- validation, fuzzing, benchmarking, and self-tests

The library is designed to serve both as:

- a learning-oriented implementation project for mastering cryptography and C systems programming
- a structured, reusable crypto toolkit with a clear internal architecture

The project intentionally separates:

- low-level primitives from higher-level constructions
- public API headers from internal implementation details
- recommended modern algorithms from legacy or compatibility-oriented algorithms

Initial priority is given to modern and widely used primitives such as:

- SHA-2
- SHA-3
- BLAKE2
- AES
- ChaCha20
- AES-GCM
- ChaCha20-Poly1305
- HKDF
- PBKDF2
- Argon2id
- RSA-PSS / RSA-OAEP
- X25519
- Ed25519
- P-256 ECDH / ECDSA

## Objectives

The main objectives of C_Crypt are:

- provide a Linux-first C implementation of modern cryptographic primitives
- maintain a clean and auditable project structure
- expose a consistent, minimal, and well-documented public API
- prioritize correctness over algorithm count
- use official known-answer test vectors wherever possible
- enforce strict input validation and safe failure behavior
- support differential testing against established libraries
- support fuzzing of parsers and high-risk interfaces
- support benchmarking of major primitives
- document security boundaries, assumptions, and limitations clearly

Engineering objectives:

- use a layered architecture
- avoid unnecessary dynamic allocation in performance-critical code
- keep parsing code isolated from cryptographic math
- keep constructions isolated from raw primitives
- make it easy to test modules independently
- keep the library warning-clean under strict compiler settings
- support sanitizer-enabled development
- keep internal APIs private and public APIs stable

Security objectives:

- favor secure defaults
- use constant-time techniques where appropriate
- include secure memory wiping utilities
- provide authenticated encryption modes for practical use
- reject malformed inputs strictly
- clearly label legacy or compatibility-only algorithms

## Supported Platforms

C_Crypt is currently designed and developed for Linux only.

Other Linux architectures may work as long as they provide:

- a C11-compatible compiler
- standard userspace interfaces required by the library
- access to the Linux system facilities used by the random backend and build system

### Platform notes

Linux-specific functionality is expected primarily in:

- secure random number generation
- build and toolchain configuration
- sanitizer and debugging workflows

The initial development and validation workflow assumes a Linux environment.
# Side-Channel Resistance

## Overview

C_Crypt is designed to minimize side-channel leakage, including:

- timing attacks
- cache attacks
- branch prediction attacks

---

## Core Principles

### Constant-Time Operations

- no secret-dependent branches
- no secret-dependent memory access

Example (bad):

```c
if (secret)
    x = a;
else
    x = b;
```

Example (good):

`x = (mask & a) | (~mask & b);`

Constant-Time Comparison

Always use:

`c_memcmp_consttime()`

Never use:

`memcmp()`

for secrets.

## Memory Handling

- sensitive buffers must be wiped
- use secure zero functions
- avoid compiler optimizations removing wipes

## Table Lookups

Avoid:

- secret-indexed lookup tables

Prefer:

- arithmetic implementations
- bit-sliced approaches

## Branching

Avoid branching on:

- keys
- plaintext
- intermediate values
- RNG Safety
- use secure system RNG
- never reuse nonces
- validate entropy sources

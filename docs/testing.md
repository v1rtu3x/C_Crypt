# Testing

## Overview

C_Crypt uses a custom minimal test harness for:

- zero dependencies
- portability
- simplicity

---

## Running Tests

```sh
ctest --output-on-failure
```

Or:

```make
make test
Test Structure
tests/
  test_main.c
  unit/
    test_memory.c
Writing Tests
```

Each test function:

- returns 0 on success
- returns non-zero on failure

Example:

```c
int c_test_example(void)
{
    if (1 != 1)
        return 1;

    return 0;
}
Output Format
[PASS] test_name
[FAIL] test_name
Sanitizer Testing
```

Run:

`./ci/sanitizer.sh`

This enables:

- AddressSanitizer
- UndefinedBehaviorSanitizer
- Future Testing
- test vectors (NIST, RFC)
- fuzz testing
- differential testing
- constant-time verification

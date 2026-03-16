#include <stddef.h>

int c_test_memory_placeholder(void)
{
    const int expected = 1;
    const int actual = 1;

    if (actual != expected) {
        return -1;
    }

    return 0;
}

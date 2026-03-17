#define _POSIX_C_SOURCE 200809L 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

static double c_bench_now_seconds(void)
{
    struct timespec ts;

    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0){
        return 0.0;
    }

    return  (double)ts.tv_sec + ((double)ts.tv_nsec/ 1000000000.0);
}


int main(void)
{
    const size_t num_iterations = 1000000;
    size_t i;
    volatile uint64_t sink = 0U;

    double start, end, elapsed;

    printf("C_Crypt benchmark scaffold\n");
    printf("==========================\n");

    start = c_bench_now_seconds();

    for(i = 0; i < num_iterations; i++) {
        sink ^= (uint64_t)i;
    }

    end = c_bench_now_seconds();
    elapsed = end - start;

    printf("Benchmark: placeholder_loop\n");
    printf("Iterations: %zu\n", num_iterations);
    printf("Elapsed time: %.6f seconds\n", elapsed);
    printf("Sink value: %lu\n", sink);

    return EXIT_SUCCESS;
}
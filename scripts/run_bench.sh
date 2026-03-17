#!/usr/bin/env bash
set -eu

BUILD_DIR="build-bench"

cmake -S . -B "${BUILD_DIR}" \
  -DCMAKE_BUILD_TYPE=Release \
  -DBUILD_BENCH=ON \
  -DBUILD_TESTS=OFF

cmake --build "${BUILD_DIR}"

"${BUILD_DIR}/bin/c_crypt_bench_hash"
#!/usr/bin/env bash
set -eu

BUILD_DIR="build-sanitize"

cmake -S . -B "${BUILD_DIR}" \
  -DCMAKE_BUILD_TYPE=Debug \
  -DBUILD_TESTS=ON \
  -DC_CRYPT_ENABLE_ASAN=ON \
  -DC_CRYPT_ENABLE_UBSAN=ON

cmake --build "${BUILD_DIR}"

ctest --test-dir "${BUILD_DIR}" --output-on-failure
#!/usr/bin/env bash
set -eu

ROOT_DIR="$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)"

if ! command -v clang-format >/dev/null 2>&1; then
    echo "error: clang-format not found"
    exit 1
fi

find "${ROOT_DIR}" \
    \( -path "${ROOT_DIR}/build" -o -path "${ROOT_DIR}/build-*" -o -path "${ROOT_DIR}/.git" \) -prune -o \
    \( -name "*.c" -o -name "*.h" \) -type f -print \
    | while IFS= read -r file; do
        clang-format -i "${file}"
    done

echo "Formatting complete."
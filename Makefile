BUILD_DIR := build
CMAKE := cmake

.PHONY: all debug release test clean bench format

all: debug

debug:
	$(CMAKE) -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON
	$(CMAKE) --build $(BUILD_DIR)

release:
	$(CMAKE) -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON
	$(CMAKE) --build $(BUILD_DIR)

test:
	ctest --test-dir $(BUILD_DIR) --output-on-failure

bench:
	$(CMAKE) -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Release -DBUILD_BENCH=ON
	$(CMAKE) --build $(BUILD_DIR)
	./$(BUILD_DIR)/bin/c_crypt_bench_hash

format:
	./scripts/format.sh

clean:
	rm -rf $(BUILD_DIR)
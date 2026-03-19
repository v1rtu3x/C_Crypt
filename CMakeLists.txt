cmake_minimum_required(VERSION 3.16)

project(c_crypt
    VERSION 0.1.0
    DESCRIPTION "A lightweight cryptographic library written in C"
    LANGUAGES C
)

# -----------------------------------------------------------------------------
# Language standard
# -----------------------------------------------------------------------------

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# -----------------------------------------------------------------------------
# Build options
# -----------------------------------------------------------------------------

option(BUILD_SHARED_LIBS "Build shared libraries by default" ON)
option(BUILD_TESTS "Build tests" ON)
option(BUILD_BENCH "Build benchmarks" OFF)
option(BUILD_FUZZ "Build fuzz targets" OFF)
option(BUILD_EXAMPLES "Build examples" OFF)
option(C_CRYPT_WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)
option(C_CRYPT_ENABLE_ASAN "Enable AddressSanitizer" OFF)
option(C_CRYPT_ENABLE_UBSAN "Enable UndefinedBehaviorSanitizer" OFF)

# -----------------------------------------------------------------------------
# Default build type
# -----------------------------------------------------------------------------

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    Debug
    Release
    RelWithDebInfo
    MinSizeRel
)

# -----------------------------------------------------------------------------
# Output directories
# -----------------------------------------------------------------------------

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# -----------------------------------------------------------------------------
# Compiler warnings
# -----------------------------------------------------------------------------

set(C_CRYPT_WARNING_FLAGS)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    list(APPEND C_CRYPT_WARNING_FLAGS
        -Wall
        -Wextra
        -Wpedantic
        -Wshadow
        -Wconversion
        -Wcast-qual
        -Wstrict-prototypes
        -Wmissing-prototypes
    )

    if(C_CRYPT_WARNINGS_AS_ERRORS)
        list(APPEND C_CRYPT_WARNING_FLAGS -Werror)
    endif()
endif()

# -----------------------------------------------------------------------------
# Sanitizers
# -----------------------------------------------------------------------------

set(C_CRYPT_SANITIZER_FLAGS)
set(C_CRYPT_SANITIZER_LINK_FLAGS)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    if(C_CRYPT_ENABLE_ASAN)
        list(APPEND C_CRYPT_SANITIZER_FLAGS -fsanitize=address)
        list(APPEND C_CRYPT_SANITIZER_LINK_FLAGS -fsanitize=address)
    endif()

    if(C_CRYPT_ENABLE_UBSAN)
        list(APPEND C_CRYPT_SANITIZER_FLAGS -fsanitize=undefined)
        list(APPEND C_CRYPT_SANITIZER_LINK_FLAGS -fsanitize=undefined)
    endif()

    if(C_CRYPT_SANITIZER_FLAGS)
        list(APPEND C_CRYPT_SANITIZER_FLAGS -fno-omit-frame-pointer)
    endif()
endif()

# -----------------------------------------------------------------------------
# Source placeholders
# -----------------------------------------------------------------------------

set(C_CRYPT_CORE_SOURCES
    src/core/errors.c
    src/core/memory.c
    src/core/ct.c
    src/core/buf.c
    src/core/random_sys.c
)

set(C_CRYPT_HASH_SOURCES)
set(C_CRYPT_MAC_SOURCES)
set(C_CRYPT_CIPHER_SOURCES)
set(C_CRYPT_MODE_SOURCES)
set(C_CRYPT_AEAD_SOURCES)
set(C_CRYPT_KDF_SOURCES)
set(C_CRYPT_BIGINT_SOURCES)
set(C_CRYPT_PK_SOURCES)
set(C_CRYPT_ENCODING_SOURCES)

set(C_CRYPT_ALL_SOURCES
    ${C_CRYPT_CORE_SOURCES}
    ${C_CRYPT_HASH_SOURCES}
    ${C_CRYPT_MAC_SOURCES}
    ${C_CRYPT_CIPHER_SOURCES}
    ${C_CRYPT_MODE_SOURCES}
    ${C_CRYPT_AEAD_SOURCES}
    ${C_CRYPT_KDF_SOURCES}
    ${C_CRYPT_BIGINT_SOURCES}
    ${C_CRYPT_PK_SOURCES}
    ${C_CRYPT_ENCODING_SOURCES}
)

# -----------------------------------------------------------------------------
# Common target settings helper
# -----------------------------------------------------------------------------

function(c_crypt_apply_common_settings target_name)
    target_include_directories(${target_name}
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

    target_compile_options(${target_name}
        PRIVATE
            ${C_CRYPT_WARNING_FLAGS}
            ${C_CRYPT_SANITIZER_FLAGS}
            $<$<C_COMPILER_ID:GNU,Clang>:$<$<CONFIG:Debug>:-O0;-g3>>
            $<$<C_COMPILER_ID:GNU,Clang>:$<$<CONFIG:Release>:-O3>>
    )

    target_link_options(${target_name}
        PRIVATE
            ${C_CRYPT_SANITIZER_LINK_FLAGS}
    )

    target_compile_definitions(${target_name}
        PRIVATE
            C_CRYPT_BUILD
    )

    set_target_properties(${target_name} PROPERTIES
        POSITION_INDEPENDENT_CODE ON
    )
endfunction()
# -----------------------------------------------------------------------------
# Static library target
# -----------------------------------------------------------------------------

add_library(c_crypt_static STATIC ${C_CRYPT_ALL_SOURCES})
add_library(c_crypt::static ALIAS c_crypt_static)

set_target_properties(c_crypt_static PROPERTIES
    OUTPUT_NAME c_crypt
)

c_crypt_apply_common_settings(c_crypt_static)

# -----------------------------------------------------------------------------
# Shared library target
# -----------------------------------------------------------------------------

add_library(c_crypt_shared SHARED ${C_CRYPT_ALL_SOURCES})
add_library(c_crypt::shared ALIAS c_crypt_shared)

set_target_properties(c_crypt_shared PROPERTIES
    OUTPUT_NAME c_crypt
)

c_crypt_apply_common_settings(c_crypt_shared)

# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------

if(BUILD_TESTS)
    enable_testing()

    add_executable(c_crypt_tests
        tests/test_main.c
        tests/unit/test_memory.c
        tests/unit/test_endian.c
        tests/unit/test_ct.c
        tests/unit/test_buf.c
    )

    target_link_libraries(c_crypt_tests PRIVATE c_crypt_static)

    target_include_directories(c_crypt_tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/tests
    )

    target_compile_options(c_crypt_tests PRIVATE
        ${C_CRYPT_WARNING_FLAGS}
        ${C_CRYPT_SANITIZER_FLAGS}
    )

    target_link_options(c_crypt_tests PRIVATE
        ${C_CRYPT_SANITIZER_LINK_FLAGS}
    )

    add_test(NAME c_crypt_tests COMMAND c_crypt_tests)
endif()

# -----------------------------------------------------------------------------
# Benchmarks
# -----------------------------------------------------------------------------

if(BUILD_BENCH)
    add_executable(c_crypt_bench_hash
        bench/bench_hash.c
    )

    target_link_libraries(c_crypt_bench_hash PRIVATE c_crypt_static)
    target_compile_options(c_crypt_bench_hash PRIVATE ${C_CRYPT_WARNING_FLAGS})
endif()

# -----------------------------------------------------------------------------
# Examples
# -----------------------------------------------------------------------------

if(BUILD_EXAMPLES)
    add_executable(c_crypt_example_placeholder
        examples/example_placeholder.c
    )

    target_link_libraries(c_crypt_example_placeholder PRIVATE c_crypt_static)

    target_include_directories(c_crypt_example_placeholder PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/tests
    )

    target_compile_options(c_crypt_example_placeholder PRIVATE
        ${C_CRYPT_WARNING_FLAGS}
    )
endif()

# -----------------------------------------------------------------------------
# Fuzzing placeholder
# -----------------------------------------------------------------------------

if(BUILD_FUZZ)
    message(STATUS "BUILD_FUZZ is ON, but no fuzz targets are defined yet.")
endif()

# -----------------------------------------------------------------------------
# Install rules
# -----------------------------------------------------------------------------

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(TARGETS c_crypt_static c_crypt_shared
    EXPORT c_cryptTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# -----------------------------------------------------------------------------
# Export target support
# -----------------------------------------------------------------------------

install(EXPORT c_cryptTargets
    FILE c_cryptTargets.cmake
    NAMESPACE c_crypt::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/c_crypt
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/c_cryptConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/c_cryptConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/c_cryptConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/c_crypt
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/c_cryptConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/c_cryptConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/c_crypt
)
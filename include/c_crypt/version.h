// include/c_crypt/version.h

/*The file `version.h` defines the compile-time version of the C_Crypt library.  
These macros allow applications and tools to detect the library version during compilation and optionally during runtime.

The version follows semantic versioning:


- MAJOR — incompatible API changes
- MINOR — new features, backwards compatible
- PATCH — bug fixes and internal improvements
*/

#ifndef C_VERSION_H
#define C_VERSION_H


#define C_VERSION_MAJOR 0
#define C_VERSION_MINOR 1
#define C_VERSION_PATCH 0

#define C_VERSION_NUMBER \
    ((C_VERSION_MAJOR * 10000) + (C_VERSION_MINOR * 100) + (C_VERSION_PATCH))

#define C_VERSION_STRING "0.1.0"

#endif // C_VERSION_H
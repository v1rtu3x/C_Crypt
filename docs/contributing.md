# Coding Style

C_Crypt uses `clang-format` for formatting. All contributed C source and header files must be formatted before submission.

## Formatting rules

- 4 spaces per indentation level
- no tabs
- Allman brace style
- 100 character line width
- pointer style: `type *name`
- one declaration per line
- deterministic include ordering
- no trailing whitespace
- files must end with a newline

## Include order

Source files should include headers in this order:

1. the corresponding related header
2. C standard library headers
3. third-party headers
4. public project headers
5. internal project headers

## Formatting command

Run:

```sh
./scripts/format.sh
```

or :

``` make
make format
```

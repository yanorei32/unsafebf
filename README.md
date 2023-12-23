# unsafebf
An unsafe brainfuck interpreter.
It uses stack as memory directly.

## Features
- Simple code
- Dynamically allocated large memory
- A little fast
- Allows RCE for attacker
- Non portable (It depends on POSIX read and write functions that do not use stack.)

## How to

```bash
gcc main.c -o unsafebf
./unsafebf "Some bf code"
```

## Compatibility

| Arch     | OS           | Compiler           | libc             | Compile Options     | Result                  |
|:---------|:-------------|:-------------------|:-----------------|:--------------------|:------------------------|
| `x86_64` | `Debian 12`  | `gcc-12 12.2.0-14` | `2.36-9+deb12u3` | `gcc main.c`        | Segmentation fault      |
| `x86_64` | `Debian 12`  | `gcc-12 12.2.0-14` | `2.36-9+deb12u3` | `gcc main.c -O0`    | Segmentation fault      |
| `x86_64` | `Debian 12`  | `gcc-12 12.2.0-14` | `2.36-9+deb12u3` | `gcc main.c -O1`    | Unexpected behaviour †1 |
| `x86_64` | `Debian 12`  | `gcc-12 12.2.0-14` | `2.36-9+deb12u3` | `gcc main.c -O2`    | ✅                      |
| `x86_64` | `Debian 12`  | `gcc-12 12.2.0-14` | `2.36-9+deb12u3` | `gcc main.c -O3`    | ✅                      |
| `x86_64` | `Debian 12`  | `gcc-12 12.2.0-14` | `2.36-9+deb12u3` | `gcc main.c -Og`    | Unexpected behaviour †1 |
| `x86_64` | `Debian 12`  | `gcc-12 12.2.0-14` | `2.36-9+deb12u3` | `gcc main.c -Oz`    | ✅                      |
| `x86_64` | `Debian 12`  | `gcc-12 12.2.0-14` | `2.36-9+deb12u3` | `gcc main.c -Os`    | ✅                      |
| `x86_64` | `Debian 12`  | `gcc-12 12.2.0-14` | `2.36-9+deb12u3` | `gcc main.c -Ofast` | ✅                      |
| `x86_64` | `Arch Linux` | `gcc 13.2.1-3`     | `glibc 2.38-7`   | `gcc main.c`        | ✅                      |
| `x86_64` | `Arch Linux` | `gcc 13.2.1-3`     | `glibc 2.38-7`   | `gcc main.c -O0`    | ✅                      |
| `x86_64` | `Arch Linux` | `gcc 13.2.1-3`     | `glibc 2.38-7`   | `gcc main.c -O1`    | ✅                      |
| `x86_64` | `Arch Linux` | `gcc 13.2.1-3`     | `glibc 2.38-7`   | `gcc main.c -O2`    | ✅                      |
| `x86_64` | `Arch Linux` | `gcc 13.2.1-3`     | `glibc 2.38-7`   | `gcc main.c -O3`    | ✅                      |
| `x86_64` | `Arch Linux` | `gcc 13.2.1-3`     | `glibc 2.38-7`   | `gcc main.c -Og`    | ✅                      |
| `x86_64` | `Arch Linux` | `gcc 13.2.1-3`     | `glibc 2.38-7`   | `gcc main.c -Oz`    | ✅                      |
| `x86_64` | `Arch Linux` | `gcc 13.2.1-3`     | `glibc 2.38-7`   | `gcc main.c -Os`    | ✅                      |
| `x86_64` | `Arch Linux` | `gcc 13.2.1-3`     | `glibc 2.38-7`   | `gcc main.c -Ofast` | ✅                      |

†1: It can use first cell only.

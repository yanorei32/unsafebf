# unsafebf
An unsafe brainfuck interpreter.
It uses stack as memory directly.

## How to

```bash
gcc main.c -o unsafebf
./unsafebf "Some bf code"
```

## Features
- Simple code
- Dynamically allocated large memory
- A little fast
- Allows RCE for attacker
- Non portable (It depends on POSIX read and write functions that do not use stack.)

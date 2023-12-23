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

## FAQ

### Q. It's not working in my environment
This software depends on the implementation heavily.
I confirmed it works in x86_64 and -O3 flags.

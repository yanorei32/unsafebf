#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

struct {} typedef Void;

void f(
	volatile int *allocated,
	volatile int *cursor,
	volatile int *block,
	const char *program,
	volatile uint8_t *p
) {
	// Get a stack address
	volatile Void a;
	p = (volatile uint8_t *) &a;

	// Initialize first cell
	*p = 0;
	*allocated = 1;
	*cursor = 0;
	
	while (*program) {
		switch(*program) {
			case '+': ++(*p); break;
			case '-': --(*p); break;
			case '.': write(1, p, 1); break;
			case ',': read(1, p, 1); break;
			case '<': --*cursor, ++p; break;

			case '>':
				++(*cursor);

				// Allocate to minus direction (because stack is stack)
				--p;

				// Dynamically cell initialization (if non initilized)
				if (*allocated <= *cursor) *p = 0, *allocated += 1;

				break;

			case '[':
				// If *p is zero, Seek to ']'
				*block = !*p;

				while (*block) {
					program++;
					switch (*program) {
						case '[': (*block)++; break;
						case ']': (*block)--; break;
						default: break;
					}
				}

				break;

			case ']':
				*block = 1;

				// Seekback to '['
				while (*block) {
					program--;
					switch (*program) {
						case ']': (*block)++; break;
						case '[': (*block)--; break;
						default: break;
					}
				}

				program--;

				break;

			default: break;
		}

		// Fetch next op
		program++;
	}
}

int main(int argc, char** argv) {
	volatile int allocated, cursor, block;

	if (argc-2)
		printf("%s [brainfuck code]\n", argv[0]);
	else
		f(&allocated, &cursor, &block, argv[1], 0);

	return 0;
}

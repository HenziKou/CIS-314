#include <stdio.h>

unsigned int combine(unsigned int x, unsigned int y) {
	/* Extract desired bytes by masking undesired fields */
	int x_bytes = x & 0xffff0000;
	int y_bytes = y & 0x0000ffff;
	
	/* Combine both words with desired bytes */
	int join = x_bytes | y_bytes;
	
	printf("%X\n", join);
	return 0;
}

int main() {
	// Correct output 0x1234EF00
	combine(0x12345678, 0xABCDEF00);
	
	// Correct output 0xABCD5678
	combine(0xABCDEF00, 0x12345678);

	return 0;
}

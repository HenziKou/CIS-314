#include <stdio.h>

unsigned int extract(unsigned int x, int i) {
	/* Find byte field to extract */
	int field = 3 - i;

	/* Bit-shifting multiplier (moves by a whole byte length) */
	int dist = field << 3;

	/* Shift word by required distances */
	int shift = x << dist;

	/* Reshift word back into 0 byte position */
	int reverse = shift >> 24;

	printf("0x%X\n", reverse);
	return 0;	
}

int main() {
	extract(0x12345678, 0);
	extract(0xABCDEF00, 2);
}

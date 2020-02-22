#include <stdio.h>

unsigned int replace(unsigned int x, int i, unsigned char b) {
	/* Shifts words by one byte */
	int field = i << 3;
	
	/* Shift mask based on the desired fields of bytes */
	int mask = 0xff << field;

	/* Clear byte field with mask */
	int clear = x & ~mask;

	/* Shift new byte values to desire byte field */
	int value = b << field;

	/* Combine new byte values with old word */
	int replaced = clear | value;

	printf("0x%X\n", replaced);
	return 0;
}

int main() {
	replace(0x12345678, 2, 0xab);
	replace(0x12345678, 0, 0xab);
}

#include <stdio.h>

int mask(int n) {
	/* Shift -1 by n positions and then return the inverse */
	int shift = ~(0xFFFFFFFF << n);

	printf("0x%X\n", shift);
	return 0;
}

int main() {
	mask(0);
	mask(1);
	mask(2);
	mask(3);
	mask(5);
	mask(8);
	mask(16);
	mask(31);
}		

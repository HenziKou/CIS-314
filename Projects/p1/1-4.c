#include <stdio.h>

int oddBit(unsigned int x) {
	/* Intialize a mask detector */
	int mask = 0xaaaaaaaa;
	
	/* Remove all values in even indicies */
	int clear = x & mask;
	
	/* Test if word has value at odd indices */
	int odd = clear && mask;
	
	printf("%X\n", odd);
	return 0;
}

int main() {
	oddBit(0x1);
	oddBit(0x2);
	oddBit(0x3);
	oddBit(0x4);
	oddBit(0xFFFFFFFF);
	oddBit(0xAAAAAAAA);
	oddBit(0x55555555);
}

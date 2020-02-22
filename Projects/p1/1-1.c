#include <stdio.h>

void printBytes(unsigned char *start, int len) {
	for (int i = 0; i < len; ++i) {
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void printInt(int x) {
	printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x) {
	printBytes((unsigned char *) &x, sizeof(float));
}

void printShort(short x) {
	printBytes((unsigned char *) &x, sizeof(short));
}

void printLong(long x) {
	printBytes((unsigned char *) &x, sizeof(long));
}

void printDouble(double x) {
	printBytes((unsigned char *) &x, sizeof(double));
}

int main() {
	/* Testing integers:
		- The results match the example outputs in Figure 2.6
		- Values only go up to a maximum of 2 bytes
		- Uses Big Endian style of ordering
	*/
	printInt(12345);
	

	/* Testing floats
		- The results match the example outputs in Figure 2.6
		- Values only go up to a maximum of 2 bytes
		- Uses Little Endian style of ordering
	*/
	printFloat(12345);


	/* Testing short
		- Values only go up to a maximum of 1 byte
		- Uses Big Endian style of ordering
	*/
	printShort(12345);

	
	/* Testing long
		- Values only go up to a maximum of 4 bytes
		- Uses Big Endian style of ordering
	*/
	printLong(12345);


	/* Testing doubles
		- Values only go up to a maximum of 4 bytes
		- Uses Little Endian style of ordering
	*/
	printDouble(12345);	
}	

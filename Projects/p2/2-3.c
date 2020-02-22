#include <stdio.h>

int ge(float x, float y) {
	unsigned int ux = *((unsigned int*) &x);	// convert x raw bits
	unsigned int uy = *((unsigned int*) &y);	// convert y raw bits
	unsigned int sx = ux >> 31;			// extract sign bit of ux
	unsigned int sy = uy >> 31;			// extract sign bit of uy
	ux <<= 1;					// drop sign bit ux
	uy <<= 1;					// drop sign bit uy
	
	/* Check that sx is indeed less than sy because unsigned numbers have value 0 */
	int svalue = (sx < sy);
	
	/* If both numbers are unsigned check for bigger value */
	int unsign = ((sx == 0) & (sy == 0)) & (ux >= uy);
	
	/* If both numbers are signed check for smaller value */
	int sign = ((sx == 1) & (sy == 1)) & (ux <= uy);
	
	/* Negative zero and zero are equivalent */
	int zero = (ux | uy) == 0;
	
	/* Combine the four conditions and return result */	
	int result = (svalue | unsign | sign | zero);

	printf("%d\n", result);
	return 0;
}

int main() {
	ge(0.0f, 0.0f);
	ge(-0.0f, 0.0f);
	ge(-1.0f, 0.0f);
	ge(0.0f, 1.0f);
	ge(1.0f, 0.0f);
	ge(0.0f, -1.0f);
}

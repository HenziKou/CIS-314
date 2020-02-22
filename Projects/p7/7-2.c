#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Simulate a:
	- 256B cache
	- 16B blocks
	- 16 sets
   (i.e., direct mapped) for a 32-bit architecture.

   Cache Parameters:
	s = log2(S)		Number of set index bits
	b = log2(B)		Number of block offset bits
	t = m - (s + b)		Number of tag bits
*/

unsigned int getOffset(unsigned int address)
{
    /* b = log2(16) = 4 */
    return 0x0000000F & address;
}

unsigned int getSet(unsigned int address)
{
    return (0x000000F0 & address) >> 4;
}

unsigned int getTag(unsigned int address)
{
    return (0xFFFFFF00 & address) >> 8;
}

int main()
{
    unsigned int a = 0x12345678;
    unsigned int b = 0x87654321;

    /* Test runs: */
    printf("0x%X: offset: %X - tag: %X - set: %X\n", a, getOffset(a), getTag(a), getSet(a));
    printf("0x%X: offset: %X - tag: %X - set: %X\n", b, getOffset(b), getTag(b), getSet(b));
}

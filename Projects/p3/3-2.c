#include <stdio.h>

long decode(long a, long b, long c)
{
	/*   %rdi    %rsi    %rdx */

	/* subq %rdx, %rsi
	 * imulq %rsi, %rdi
	 * salq $63, %rsi
	 * sarq $63, %rsi
	 * movq %rdi, %rax
	 * xorq %rsi, %rax
	 */
	
	long rax;
	b -= c;
	a *= b;
	b <<= 63;
	b >>= 63;
	rax = a;
	rax = rax ^ b;
	printf("%ld\n", rax);
	return rax;
}

int main()
{
	decode(1, 2, 4);
	decode(3, 5, 7);
	decode(10, 20, 30);
}
